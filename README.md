# 🚀 Projeto: Controle de Servomotor por PWM

## 📋 Descrição do Projeto
Neste projeto, utilizamos o módulo PWM (Pulse Width Modulation) presente no microcontrolador RP2040 para simular o controle do ângulo de um servomotor. A simulação é feita utilizando o motor micro servo padrão presente no simulador de eletrônica online Wokwi.

### 🧰 Componentes Utilizados
1. Microcontrolador Raspberry Pi Pico W
2. Servomotor – motor micro servo padrão – Wokwi

## 🎯 Requisitos do Projeto
1. Definir a frequência de PWM na GPIO 22 para aproximadamente 50Hz (período de 20ms).
2. Definir o ciclo ativo do módulo PWM para 2.400µs (0,12% Duty Cycle) ajustando a flange do servomotor para aproximadamente 180 graus e aguardar 5 segundos.
3. Definir o ciclo ativo do módulo PWM para 1.470µs (0,0735% Duty Cycle) ajustando a flange do servomotor para aproximadamente 90 graus e aguardar 5 segundos.
4. Definir o ciclo ativo do módulo PWM para 500µs (0,025% Duty Cycle) ajustando a flange do servomotor para aproximadamente 0 graus e aguardar 5 segundos.
5. Criar uma rotina para movimentação periódica do braço do servomotor entre 0 e 180 graus com incrementos de ciclo ativo de ±5µs e atraso de ajuste de 10ms.
6. Realizar um experimento utilizando a Ferramenta Educacional BitDogLab com o LED RGB na GPIO 12 e observar o comportamento da iluminação.

## 🛠️ Desenvolvimento
### Ambiente de Desenvolvimento
- VS Code
- Linguagem C com Pico SDK
- Simulador Wokwi integrado ao VS Code

### 📝 O que foi feito
1. **Configuração do GPIO para PWM:**
    - Configuramos o pino GPIO para função PWM.
    - Inicializamos o slice de PWM e configuramos o valor de wrap e divisor de clock para obter a frequência desejada.

2. **Controle do Servomotor:**
    - Definimos o ciclo ativo do PWM para ajustar a flange do servomotor para 180 graus e aguardamos 5 segundos.
    - Ajustamos o ciclo ativo para 90 graus e aguardamos 5 segundos.
    - Ajustamos o ciclo ativo para 0 graus e aguardamos 5 segundos.
    - Implementamos uma rotina contínua para movimentar o braço do servomotor entre 0 e 180 graus suavemente.

3. **Experimento com LED RGB:**
    - Realizamos um experimento utilizando o LED RGB na GPIO 12 para observar o comportamento da iluminação.

### 🔗 Link do Vídeo
[Vídeo de Demonstração](https://drive.google.com/file/d/1ZjOb5Oba4BBt6PLLUCJknEZ2tVNRFytS/view?usp=sharing)


