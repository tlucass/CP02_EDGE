# Checkpoint - Edge Computing and Computer Systems


## Sobre
Este projeto usa uma placa Arduino para monitorar e exibir os níveis de temperatura, luminosidade e umidade em um ambiente. O programa usa um LDR (resistor dependente de luz) para medir o nível de luz e um termistor para medir a temperatura. Os resultados são exibidos em uma tela LCD 16x2. Além disso, o programa usa três LEDs e uma campainha para fornecer feedback visual e auditivo quando o nível de luz ou a temperatura é muito alta ou muito baixa.

---

⚙️ Requisitos:
Para executar este projeto, você precisará dos seguintes componentes:
• Arduino Uno
• Sensor de luminosidade
• Buzzer
• LEDs verde, amarelo e vermelho
• Display LCD 16x2
• Resistores
• Jumpers

---

🖥️ Instalação:
• Conecte o sensor de luminosidade ao pino A0 do Arduino Uno.
• Conecte os LEDs verde, amarelo e vermelho aos pinos 2, 3 e 4 do Arduino,
respectivamente.
• Conecte o buzzer ao pino 7 do Arduino.
• Conecte o display LCD aos pinos 8, 13, 9, 10, 11 e 12 do Arduino.
• Carregue o código no Arduino Uno.
⌨️ Uso:
Ao ligar o Arduino, o display LCD exibirá a leitura atual do sensor de luminosidade. Se a
luminosidade estiver dentro dos limites estipulados, o LED verde ficará aceso. Se a
luminosidade estiver em nível de alerta, o LED amarelo ficará aceso e um alarme sonoro
será ativado por 3 segundos. Se a luminosidade estiver acima do nível de alerta, o LED
vermelho ficará aceso e o alarme sonoro continuará a tocar
