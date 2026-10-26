# Real-Time Ocular Artifact BCI

![Status](https://img.shields.io/badge/status-academic%20prototype-blue)
![Platform](https://img.shields.io/badge/platform-Arduino%20%2F%20Embedded%20Systems-green)
![Signal](https://img.shields.io/badge/signal-EEG-purple)
![Sampling](https://img.shields.io/badge/sampling-500%20Hz-lightgrey)
![Award](https://img.shields.io/badge/FEBITEC-honorable%20mention-orange)

🇺🇸 **English** | 🇧🇷 **Português**

---

## 🇺🇸 English

## Overview

This project presents an embedded Brain-Computer Interface prototype for real-time detection of ocular artifacts, especially intentional eye blinks, from Electroencephalography signals.

The system acquires EEG data, processes the signal in real time, identifies blink-related patterns through peak and valley detection, and uses the detected event as a control signal to activate a DC motor.

This project received an **Honorable Mention at the 6th FEBITEC** with the work:

**“Algorithm for Real-Time Detection of Ocular Artifacts in Electroencephalography Signals.”**

---

## Hardware Setup

Place the photo of the physical setup, wiring, electrodes, board, and motor connection here:

<img width="3716" height="1760" alt="CircuitoPNG2" src="https://github.com/user-attachments/assets/dc024a3f-4c53-4587-a6ac-23da2203e2d7" />

The hardware prototype integrates EEG acquisition, embedded processing, and external actuation through a DC motor.

---

## Detection Example

Place the graph showing the detected ocular artifact here:

<img width="1415" height="1007" alt="SinalDetec_Ing" src="https://github.com/user-attachments/assets/d5e62c28-9a1e-486e-b2e2-2bc1de032549" />

This graph illustrates the signal behavior during ocular artifact detection and highlights the blink-related pattern identified by the algorithm.

---

## Threshold Approaches

This project includes two detection approaches:

| Branch                 | Approach            | Description                                                                                                                  |
| ---------------------- | ------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| `main`                 | Static thresholds   | Uses predefined threshold values for ocular artifact detection                                                               |
| `Limiares-Adaptativos` | Adaptive thresholds | Uses dynamic thresholds based on running mean and standard deviation to improve robustness against signal baseline variation |

The adaptive threshold approach increases the system’s robustness when the EEG baseline changes over time.

---

## Temporal Delay Measurements

To evaluate the real-time response of the system, temporal delay measurements were collected during experimental tests.

The EEG acquisition was configured with a sampling frequency of **500 Hz**, resulting in a sample period of **2 ms**.

| Group         | Mean Delay (samples) | Mean Delay (ms) |
| ------------- | -------------------: | --------------: |
| Participant 1 |                    2 |            4 ms |
| Participant 2 |                    3 |            6 ms |
| Participant 3 |                    2 |            4 ms |
| Participant 4 |                    1 |            2 ms |
| **Overall**   |                **2** |        **4 ms** |

The overall mean delay of **4 ms** indicates that the proposed detection pipeline is suitable for real-time embedded response.

The complete anonymized delay measurements are available in:

📄 [`delay_measurements.csv`](delay_measurements.csv)

---

## Demonstration

The demonstration video shows the complete system operation, including electrode placement, intentional blinking, real-time artifact detection, and DC motor activation.

<video src="https://github.com/user-attachments/assets/26089015-e8d5-4e18-a7d6-7d24f8ae349d" width="100%" controls></video>

---

## Source Code

The embedded implementation is available in the Arduino `.ino` files in this repository.

The code performs signal acquisition, real-time processing, ocular artifact detection, and output control for motor activation.

---

## Academic Context

This project was developed as an academic prototype in embedded systems and biomedical signal processing.

It is intended for educational, research, and demonstration purposes only.

> This project is not a medical device and must not be used for diagnosis, treatment, clinical monitoring, or safety-critical applications.

---

## Author

**Yuri Silveira Pereira**
Computer Engineering Undergraduate — UFSM

---

# 🇧🇷 Português

## Visão Geral

Este projeto apresenta um protótipo embarcado de Interface Cérebro-Máquina para detecção em tempo real de artefatos oculares, especialmente piscadas intencionais, a partir de sinais de Eletroencefalografia.

O sistema realiza a aquisição dos dados de EEG, processa o sinal em tempo real, identifica padrões relacionados à piscada por meio da detecção de picos e vales e utiliza o evento detectado como sinal de controle para acionar um motor DC.

Este projeto recebeu **Menção Honrosa na 6ª FEBITEC** com o trabalho:

**“Algoritmo para Detecção em Tempo Real de Artefatos Oculares em Sinais de Eletroencefalografia.”**

## Montagem de Hardware

<img width="3716" height="1760" alt="CircuitoPNG2" src="https://github.com/user-attachments/assets/dc024a3f-4c53-4587-a6ac-23da2203e2d7" />


O protótipo de hardware integra aquisição de EEG, processamento embarcado e atuação externa por meio de um motor DC.

---

## Exemplo de Detecção

<img width="1415" height="1007" alt="Detecção" src="https://github.com/user-attachments/assets/197597fb-5689-4b08-be3e-1c2fa72a82c4" />


Este gráfico ilustra o comportamento do sinal durante a detecção do artefato ocular e destaca o padrão relacionado à piscada identificado pelo algoritmo.

---

## Abordagens de Limiar

Este projeto inclui duas abordagens de detecção:

| Branch                 | Abordagem            | Descrição                                                                                                                                 |
| ---------------------- | -------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `main`                 | Limiares estáticos   | Utiliza valores de limiar predefinidos para a detecção de artefatos oculares                                                              |
| `Limiares-Adaptativos` | Limiares adaptativos | Utiliza limiares dinâmicos baseados na média móvel e no desvio padrão para aumentar a robustez contra variações da linha de base do sinal |

A abordagem com limiares adaptativos aumenta a robustez do sistema quando a linha de base do EEG varia ao longo do tempo.

---

## Medições de Atraso Temporal

Para avaliar a resposta em tempo real do sistema, foram realizadas medições de atraso temporal durante testes experimentais.

A aquisição de EEG foi configurada com frequência de amostragem de **500 Hz**, resultando em um período de amostragem de **2 ms**.

| Grupo          | Atraso Médio (amostras) | Atraso Médio (ms) |
| -------------- | ----------------------: | ----------------: |
| Participante 1 |                       2 |              4 ms |
| Participante 2 |                       3 |              6 ms |
| Participante 3 |                       2 |              4 ms |
| Participante 4 |                       1 |              2 ms |
| **Geral**      |                   **2** |          **4 ms** |

O atraso médio geral de **4 ms** indica que o pipeline de detecção proposto é adequado para resposta embarcada em tempo real.

As medições completas e anonimizadas de atraso estão disponíveis em:

📄 [`delay_measurements.csv`](delay_measurements.csv)

---

## Demonstração

O vídeo de demonstração mostra o funcionamento completo do sistema, incluindo o posicionamento dos eletrodos, piscadas intencionais, detecção em tempo real do artefato ocular e acionamento do motor DC.

<video src="https://github.com/user-attachments/assets/26089015-e8d5-4e18-a7d6-7d24f8ae349d" width="100%" controls></video>

---

## Código-Fonte

A implementação embarcada está disponível nos arquivos Arduino `.ino` deste repositório.

O código realiza aquisição do sinal, processamento em tempo real, detecção de artefatos oculares e controle da saída para acionamento do motor.

---

## Contexto Acadêmico

Este projeto foi desenvolvido como um protótipo acadêmico nas áreas de sistemas embarcados e processamento de sinais biomédicos.

Ele é destinado apenas para fins educacionais, de pesquisa e demonstração.

> Este projeto não é um dispositivo médico e não deve ser utilizado para diagnóstico, tratamento, monitoramento clínico ou aplicações críticas de segurança.

---

## Autor

**Yuri Silveira Pereira**
Graduando em Engenharia de Computação — UFSM

**Daniel Dargelio Ferrão Luft**
Graduando em Engenharia Elétrica — UFSM
