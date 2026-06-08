#include <SoftwareSerial.h>
#include <TimerOne.h>

#define Janela 50

// PINOS ---------------------------------------------------------------------
int PM = 2, LOMais = 11, LOMenos = 10, RX = 7, TX = 8;

// VARIÁVEIS GERAIS ----------------------------------------------------------
char incomingByte = 'h';

int cont_diff = 0, a = 0;

float fifo_sinal[5];

float sinal, V = 0;
float EEG = 0, EEG_Old = 0;
float EEG_Diff = 0, EEG_Diff_Old = 0;

float Leitura = 0;

// LIMIARES ESTÁTICOS --------------------------------------------------------
// Ajuste estes valores de acordo com a calibração do seu sinal
float LMax_Estatico = 500.0; 
float LMin_Estatico = 100.0; 

// FLAGS ---------------------------------------------------------------------
bool flag = 1;

bool flag_mV = 1;
bool flag_uV = 0;
bool flag_nV = 0;

bool flagLMax = 0;
bool flagLMin = 0;

bool flagLMax_Old = 0;
bool flagUltra = 0;
bool flagEEG_Diff_Old = 0;

// SERIAL --------------------------------------------------------------------
SoftwareSerial mySerial(RX, TX);

// JANELAS -------------------------------------------------------------------
float Peak_W[Janela];
int t_W[Janela];

// PICOS ---------------------------------------------------------------------
float Peak_Global = 0;
float Valley_Peak = 0;

// DETECTOR DE PICOS ---------------------------------------------------------
bool Peak_Finder(float EEG, float EEG_Old, float EEG_Diff, float EEG_Diff_Old, float LMax, float LMin)
{
  // LIMIAR SUPERIOR ---------------------------------------------------------
  if(EEG > LMax && EEG_Old <= LMax)
    {
    flagLMax = 1;
    }

  // PICO MÁXIMO -------------------------------------------------------------
  if(flagLMax == 1)
    {
    if(EEG_Diff <= 0 && EEG_Diff_Old > 0)
      {
      flagLMax_Old = 1;

      Peak_Global = EEG;
      flagLMax = 0;
      }
    }

  // INVERSÕES DA DERIVADA ---------------------------------------------------
  if(flagLMax_Old == 1)
    {
    if(EEG_Diff > 0 && EEG_Diff_Old <= 0)
      {
      cont_diff++;

      flagEEG_Diff_Old = 1;
      }

    if(flagEEG_Diff_Old == 1)
      {
      if(EEG_Diff < 0 && EEG_Diff_Old >= 0)
        {
        cont_diff++;

        flagEEG_Diff_Old = 0;
        }
      }
    }

  // LIMIAR INFERIOR ---------------------------------------------------------
  if(flagLMax_Old == 1 && EEG < LMin && EEG_Old >= LMin && cont_diff == 2)
    {
    flagLMin = 1;
    }

  // VALE --------------------------------------------------------------------
  if(flagLMin == 1)
    {
    if(EEG_Diff > 0 && EEG_Diff_Old <= 0)
      {
      Valley_Peak = EEG;

      flagLMin = 0;
      flagLMax_Old = 0;
      }
    }

  // DETECÇÃO FINAL ----------------------------------------------------------
  if(Peak_Global > LMax && Valley_Peak < LMin && cont_diff == 2)
    {
    flagUltra = 1;

    flagLMax = 0;
    flagLMin = 0;
    flagEEG_Diff_Old = 0;
    flagLMax_Old = 0;

    Peak_Global = 0;
    Valley_Peak = 0;

    cont_diff = 0;

    return 1;
    }

  return 0;
}

// PLOTTER -------------------------------------------------------------------
void plotter(float sinalPlotter)
{
  Serial.println(sinalPlotter);
}

// FILTRO / MÉDIA ------------------------------------------------------------
float filter_sinal(float sinalAD)
{
  float sinalFilter = 0;

  if((digitalRead(LOMais) == 1) || (digitalRead(LOMenos) == 1))
    {
    }
  else
    {
    fifo_sinal[4] = fifo_sinal[3];

    fifo_sinal[3] = fifo_sinal[2];
    fifo_sinal[2] = fifo_sinal[1];
    fifo_sinal[1] = fifo_sinal[0];
    fifo_sinal[0] = sinalAD;

    sinalFilter = (fifo_sinal[0] + fifo_sinal[1] + fifo_sinal[2] + fifo_sinal[3] + fifo_sinal[4]) / 5.0;
    }

  return sinalFilter;
}

// AMOSTRAGEM ----------------------------------------------------------------
float amostragem(int Porta)
{
  Leitura = analogRead(Porta);
  return Leitura;
}

// CONVERSÃO ADC / TENSÃO ----------------------------------------------------
float conversao_v(float SinalConv, bool flag_mV, bool flag_uV, bool flag_nV)
{
  if(flag_mV == 1)
    {
    V = SinalConv / 1023.0 * 5.0 * 1000.0;
    }

  else if(flag_uV == 1)
    {
    V = SinalConv / 1023.0 * 5.0 * 1000000.0;
    }

  else if(flag_nV == 1)
    {
    V = SinalConv / 1023.0 * 5.0 * 1000000000.0;
    }

  return V;
}

// PAUSA / CONTROLE SERIAL ---------------------------------------------------
void start_stop()
{
  if(Serial.available() > 0)
    {
    incomingByte = Serial.read();
    }

  if(incomingByte == 'a')
    {
    while(1)
      {
      if(Serial.available() > 0)
        {
        incomingByte = Serial.read();
        }

      if(incomingByte == 'b')
        {
        break;
        }
      }
    }
}

// MOTOR ---------------------------------------------------------------------
void motor(float sinalAD_Filtrado)
{
  if(sinalAD_Filtrado >= 415)
    {
    a = a + 1;

    if(a > 1)
      {
      a = 0;
      }

    delay(3000);
    }

  if(a == 1)
    {
    digitalWrite(PM, 0);
    }
  else
    {
    digitalWrite(PM, 1);
    }
}

// CONFIGURAÇÃO DE ESCALA ----------------------------------------------------
void config_in()
{
  while(1)
    {
    incomingByte = Serial.read();

    if(incomingByte == 'm')
      {
      flag_mV = 1;
      flag_uV = 0;

      flag_nV = 0;
      break;
      }

    else if(incomingByte == 'u')
      {
      flag_mV = 0;

      flag_uV = 1;
      flag_nV = 0;
      break;
      }

    else if(incomingByte == 'n')
      {
      flag_mV = 0;

      flag_uV = 0;
      flag_nV = 1;
      break;
      }
    }
}

// INTERRUPÇÃO ---------------------------------------------------------------
void Semaphore()
{
  flag = 1;
}

// SETUP ---------------------------------------------------------------------
void setup()
{
  Timer1.initialize(2000);
  Timer1.attachInterrupt(Semaphore);

  Serial.begin(9600);
  mySerial.begin(9600);

  config_in();

  pinMode(LOMais, INPUT);
  pinMode(LOMenos, INPUT);

  pinMode(PM, OUTPUT);

  fifo_sinal[0] = 0;

  fifo_sinal[1] = 0;
  fifo_sinal[2] = 0;
  fifo_sinal[3] = 0;
  fifo_sinal[4] = 0;

  delay(1000);

  for(int CTT = 0; CTT < Janela; CTT++)
    {
    Peak_W[CTT] = 0;
    }
}

// LOOP ----------------------------------------------------------------------
void loop()
{
  start_stop();

  if(flag == 1)
    {
    Timer1.stop();

    EEG_Old = EEG;

    // EEG -------------------------------------------------------------------
    Leitura = amostragem(A0);

    EEG = filter_sinal(Leitura);

    EEG = conversao_v(EEG, flag_mV, flag_uV, flag_nV);

    // DERIVADA --------------------------------------------------------------
    EEG_Diff_Old = EEG_Diff;
    
    EEG_Diff = (EEG - EEG_Old);

    // DETECÇÃO COM LIMIARES ESTÁTICOS ---------------------------------------
    Peak_Finder(EEG, EEG_Old, EEG_Diff, EEG_Diff_Old, LMax_Estatico, LMin_Estatico);

    // SERIAL PLOTTER --------------------------------------------------------
    Serial.print(EEG);
    Serial.print(",");

    Serial.print(LMax_Estatico);
    Serial.print(",");

    Serial.print(LMin_Estatico);
    Serial.print(",");

    // Removida a soma com a média adaptativa, plotando a derivada diretamente
    Serial.print(EEG_Diff); 
    Serial.print(",");

    // A flagUltra agora multiplicada e sem a adição da média basal
    Serial.println(flagUltra * 1000); 

    // MOTOR -----------------------------------------------------------------
    // motor(EEG);

    flagUltra = 0;

    flag = 0;

    Timer1.start();
    }
}