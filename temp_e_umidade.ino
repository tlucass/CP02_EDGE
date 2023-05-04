//Biblioteca LiquidCrystal

#include <LiquidCrystal.h>

byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
};


//Váriaveis 
const int BUZZER_PIN = 7;
const int GREEN_LED_PIN = 2;
const int YELLOW_LED_PIN = 3;
const int RED_LED_PIN = 4;
const int LDR_PIN = 0;
const int RS_PIN = 13;
const int EN_PIN = 12;
const int D4_PIN = 11;
const int D5_PIN = 10;
const int D6_PIN = 9;
const int D7_PIN = 8;

int sensor = 0;

int pinoSensor = A1;
int umidade = 0;
int porcem = 0;


// Definir os limites de luminosidade para o alarme
const int OK_LIGHT = 890;
const int ALERT_LIGHT = 950;

// Inicializar o display LCD
LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);




void setup() {
  // Configurar as portas do Arduino como saídas ou entradas
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Inicializar o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.createChar(1, degree);
  
}


void loop() {
  
  //Temperatura
    sensor = analogRead(A2);// Lendo sensor de temperatura
    float Tensao = sensor* 0.00488759;// Converter o valor lido pelo sensor
    float temperatura = (Tensao-0.5)*100; //Converter tensão em graus centigrados


    //limpar a tela 
    lcd.clear();
    //Posiciona o cusor na coluna 3, linha 0
    lcd.setCursor(0,0);
    //Envia o texto entre aspas para o lcd
    lcd.print("Temp. ");
    lcd.print(temperatura);
    lcd.setCursor(12, 0);
    lcd.write(1);
    lcd.print("C");


    if(temperatura < 10){ 
      lcd.setCursor(0,2);
      lcd.print("Temp. BAIXA!"); 
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      tone(BUZZER_PIN, 1000); // liga o buzzer com frequência de 1000Hz
      delay(5000);
    }
    else if(temperatura >= 10 && temperatura <= 15.01){
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      lcd.setCursor(0,2);
      lcd.print("Temperatura OK!");  
      delay(5000);
    }
    else{
      lcd.setCursor(0,2);
      lcd.print("Temp. ALTA!");  
      delay(1000);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      tone(BUZZER_PIN, 1000); // liga o buzzer com frequência de 1000Hz
      delay(5000);
    }
  
  
  
  
  //Luminosidade
  	// Capturar a leitura do sensor de luminosidade
    int light = analogRead(LDR_PIN);
  

    // Verificar se a luminosidade está OK
    if (light < OK_LIGHT){
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Luminosidade OK!"); 
      noTone(BUZZER_PIN); // desliga o buzzer
    }
    // Verificar se a luminosidade está em nível de alerta
    else if (light >= OK_LIGHT && light < ALERT_LIGHT) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      lcd.clear(); // limpa o conteúdo do display
      lcd.setCursor(0, 0);
      lcd.print("Ambiente a meia");
      lcd.setCursor(0, 1);
      lcd.print("luz.           ");
      tone(BUZZER_PIN, 1000); // liga o buzzer com frequência de 1000Hz
      delay(1000); 
      noTone(BUZZER_PIN); // desliga o buzzer
      delay(500); // aguarda meio segundo antes de ligar novamente
      tone(BUZZER_PIN, 1000);
      delay(1000);
      noTone(BUZZER_PIN);
      delay(500); // aguarda meio segundo antes de ligar novamente
      tone(BUZZER_PIN, 1000);
      delay(1000);
      noTone(BUZZER_PIN);
      delay(3000);
      
    }
    // Caso contrário, a luminosidade está fora dos limites estipulados
    else{
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      lcd.clear(); // limpa o conteúdo do display
      lcd.setCursor(0, 0);
      lcd.print("Ambiente muito");
      lcd.setCursor(0, 1);
      lcd.print("claro.");
      tone(BUZZER_PIN, 1000); // liga o buzzer com frequência de 1000Hz
      delay(5000);
      noTone(BUZZER_PIN);
     }
  
  
  

  //Umidade
    // Faz a leitura do sensor de umidade do solo
    umidade = analogRead(pinoSensor);
    float porcem = map(umidade,0,1023,0,100);
  
  	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade: ");  
    lcd.print(porcem);
    lcd.print("%");
  
  	Serial.println(porcem);

    if(porcem < 50){
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      lcd.setCursor(0, 2);
      lcd.print("Umidade BAIXA.");
      tone(BUZZER_PIN, 1000);
      delay(5000);
      noTone(BUZZER_PIN);
    }
    else if(porcem >= 50 && porcem <= 70){
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      lcd.setCursor(0, 2);
      lcd.print("Umidade OK!");	
      delay(5000);
    }
    else{
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      lcd.setCursor(0, 2);
      lcd.print("Umidade ALTA.");	
      tone(BUZZER_PIN, 1000);
      delay(5000);
      noTone(BUZZER_PIN);
    }

  
}



