# Checkpoint - Edge Computing and Computer Systems


## Sobre
Este projeto usa uma placa Arduino para monitorar e exibir os níveis de temperatura, luminosidade e umidade em um ambiente. O programa usa um LDR (resistor dependente de luz) para medir o nível de luz e um termistor para medir a temperatura. Os resultados são exibidos em uma tela LCD 16x2. Além disso, o programa usa três LEDs e um buzzer para fornecer feedback visual e auditivo quando o níveis de luz, temperatura ou umidade estiverem muito altos ou baixos.


## ⚙️ Requisitos:
 + Para executar este projeto, você precisará dos seguintes componentes:
 + Placa Arduino
 + Protoboard
 + Display LCD 16x2
 + Jumpers
 + Resistores
 + LEDs verde, amarelo e vermelho
 + Buzzer
 + Potenciômetros
 + Sensor LDR
 + Sensor de Temperatura TMP36


## ⌨️ Implementação:
O código foi escrito na linguagem C++ e utiliza a biblioteca LiquidCrystal.h para controlar o display LCD.

Na função `setup()` do código, é realizada a configuração das portas do Arduino como saídas ou entradas. O display LCD é inicializado com as portas que foram definidas para os pinos RS, EN, D4, D5, D6 e D7, e é criado um novo caractere personalizado para exibir o símbolo de grau Celsius.

Na função `loop()`, o programa realiza a leitura do nível da umidade, através do potenciômetro, e mede os níveis de temperatura e luminosidade pelo seus sensores, e exibe as leituras no display LCD. Em seguida, o programa verifica se os valores estão dentro dos limites estipulados e aciona os LEDs e o buzzer conforme a necessidade.

O sistema é capaz de alertar o usuário de três maneiras diferentes, dependendo do estado das leituras dos sensores:

Se a temperatura estiver abaixo de 10 graus Celsius, o LED amarelo acende e o buzzer emite um som contínuo por cinco segundos, enquanto a mensagem "Temp. BAIXA!" é exibida no display LCD.
Se a temperatura estiver entre 10 e 15 graus Celsius, o LED verde acende e a mensagem "Temperatura OK!" é exibida no display LCD.
Se a temperatura estiver acima de 15 graus Celsius, o LED amarelo acende e o buzzer emite um som contínuo por cinco segundos, enquanto a mensagem "Temp. ALTA!" é exibida no display LCD.
Se estiver em nível de alerta, o LED amarelo acende e o buzzer emite um som de alerta por três vezes com meio segundo de pausa entre cada som, enquanto a mensagem "Ambiente a meia luz." é exibida no display LCD. Se a luminosidade for superior ao nível estipulado, o LED vermelho acende e o buzzer emite um som contínuo por cinco segundos, enquanto a mensagem "Ambiente muito claro." é exibida no display.

Em resumo, este projeto é uma aplicação prática de programação e eletrônica que permite a criação de um sistema de monitoramento ambiental simples, mas eficaz, para monitorar a temperatura e a luminosidade em um ambiente.
