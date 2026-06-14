# Real-Time Ocular Artifact BCI (Brain-Computer Interface)

🇺🇸 **English** | 🇧🇷 **Português**

---

## 🇺🇸 English

### Description
This repository contains the embedded software for a Brain-Computer Interface (BCI) designed to detect ocular artifacts (eye blinks) in real-time using Electroencephalography (EEG) signals. The processed signal is used as a control input to trigger an external hardware component (a DC motor). This project was awarded an Honorable Mention at the 6th FEBITEC under the title "Algorithm for Real-Time Detection of Ocular Artifacts in Electroencephalography Signals".

### Features
- **Real-Time Signal Processing:** Continuous acquisition and filtering of EEG data.
- **Peak and Valley Detection:** Customized algorithm for reliable identification of ocular artifacts.
- **Threshold Approaches (Branches):**
  - `main`: Utilizes static thresholds for artifact detection.
  - `Limiares-Adaptativos`: Implements dynamic, adaptive thresholds based on the signal's running mean and standard deviation, enhancing system robustness against baseline drift.
- **Hardware Integration:** Translates neural/muscular activity into physical actuation.

### Demonstration
A practical demonstration of this system can be seen in the video below. It showcases the complete setup, including electrode placement, intentional blinking, and the real-time activation of the motor.

🎥 
<video src="https://github.com/user-attachments/assets/26089015-e8d5-4e18-a7d6-7d24f8ae349d" width="100%" controls></video>

### Author
**Yuri Silveira Pereira** Computer Engineering Undergraduate - UFSM

---

## 🇧🇷 Português

### Descrição
Este repositório contém o software embarcado de uma Interface Cérebro-Máquina (ICM) projetada para detectar artefatos oculares (piscadas) em tempo real através de sinais de Eletroencefalografia (EEG). O sinal processado atua como entrada de controle para acionar um componente de hardware externo (um motor DC). Este projeto recebeu Menção Honrosa na 6ª FEBITEC com o trabalho “Algoritmo para Detecção em Tempo Real de Artefatos Oculares em Sinais de Eletroencefalografia”.

### Funcionalidades
- **Processamento de Sinais em Tempo Real:** Aquisição contínua e filtragem de dados de EEG.
- **Detecção de Picos e Vales:** Algoritmo desenvolvido para a identificação confiável de artefatos oculares.
- **Abordagens de Limiares (Branches):**
  - `main`: Utiliza limiares estáticos para a detecção dos artefatos.
  - `Limiares-Adaptativos`: Implementa limiares dinâmicos e adaptativos baseados na média móvel e no desvio padrão do sinal, aumentando a robustez do sistema contra flutuações de base.
- **Integração de Hardware:** Traduz a atividade neural/muscular em atuação física.

### Demonstração
Uma demonstração prática deste sistema pode ser vista no vídeo abaixo. O registro ilustra a configuração completa, incluindo o posicionamento dos eletrodos, as piscadas intencionais e o acionamento em tempo real do motor.

🎥 
<video src="https://github.com/user-attachments/assets/26089015-e8d5-4e18-a7d6-7d24f8ae349d" width="100%" controls></video>

### Autor
**Yuri Silveira Pereira** Estudante de Engenharia de Computação - UFSM
