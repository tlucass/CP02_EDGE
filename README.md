# Checkpoint - Edge Computing and Computer Systems


## Sobre
> Este projeto usa uma placa Arduino para monitorar e exibir os níveis de temperatura, luminosidade e umidade em um ambiente. O programa usa um LDR (resistor dependente de luz) para medir o nível de luz e um termistor para medir a temperatura. Os resultados são exibidos em uma tela LCD 16x2. Além disso, o programa usa três LEDs e um buzzer para fornecer feedback visual e auditivo quando o níveis de luz, temperatura ou umidade estiverem muito altos ou baixos.


## ⚙️ Requisitos:
 > + Para executar este projeto, você precisará dos seguintes componentes:
 > + Placa Arduino
 > + Protoboard
 > + Display LCD 16x2
 > + Jumpers
 > + Resistores
 > + LEDs verde, amarelo e vermelho
 > + Buzzer
 > + Potenciômetros
 > + Sensor LDR
 > + Sensor de Temperatura TMP36


## ⌨️ Implementação:
> O programa começa com a declaração de algumas variáveis e constantes. As constantes "BUZZER_PIN", "GREEN_LED_PIN", "YELLOW_LED_PIN" e "RED_LED_PIN" definem os pinos que estão conectados ao buzzer e aos LEDs. As constantes "LDR_PIN", "RS_PIN", "EN_PIN", "D4_PIN", "D5_PIN", "D6_PIN" e "D7_PIN" definem os pinos conectados à tela LCD e ao sensor LDR. As constantes "OK_LIGHT" e "ALERT_LIGHT" definem os níveis de luz nos quais os LEDs e o buzzer fornecerão feedback.

> Na função `setup()`, o programa define os pinos como entradas ou saídas e inicializa a tela LCD. A função "createChar" é usada para definir o caractere personalizado a ser exibido na tela LCD.

> Na função `loop()`, o programa lê a temperatura e a exibe na tela LCD, assim como a umidade. Ele também verifica se os níveis estão muito altos ou muito baixos e fornece feedback de acordo. Em seguida, o programa faz a leitura do nível de luminosidade e verifica se está dentro da faixa aceitável. Se o nível de luz estiver dentro da faixa aceitável, o LED verde acende e a campainha é desligada. Se o nível de luz estiver na faixa de alerta, o LED amarelo é ligado e a campainha é ligada por três ciclos de um segundo cada. Se o nível de luz estiver muito alto, o LED vermelho é ligado e os LEDs verde e amarelo são desligados.

> No geral, o programa é um exemplo simples de como uma placa Arduino pode ser usada para monitorar e controlar o ambiente de uma sala. Ele pode ser modificado e expandido para incluir outros sensores e atuadores e fornecer feedback mais sofisticado ao usuário.
