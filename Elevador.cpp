// Elevador.cpp
#include "Elevador.h"

// O construtor é chamado quando eu declaro o meu objeto
Elevador::Elevador() {
  estadoAtual = PARADO;
}

bool Elevador::configurarElevador(){
  configurarDispositivos();
  configurarLCD();
  return true;
};

bool Elevador::configurarDispositivos(){
  // Configuração do servo motor
  pinServo = PINO_SERVO;
  // Fala para biblioteca do servo qual pino ele está conectado
  servo.attach(pinServo);
  servo.write(SERVO_START_POSITION);

  // Configuração do sensor
  pinTrigSensor = PINO_OUTPUT_SENSOR;
  pinEchoSensor = PINO_INPUT_SENSOR;
  pinMode(pinTrigSensor, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(pinEchoSensor, INPUT); // Sets the echoPin as an INPUT

  // Configuração do botão
  pinButton = PINO_BOTAO;
  pinMode(pinButton,INPUT_PULLUP); // Set the Tilt Switch as an input

};

bool Elevador::configurarLCD(){
  // Configures internal LCD pins
  pinRs = PINO_LCD_RS;
  pinEn = PINO_LCD_ENABLE;
  pinD4 = PINO_LCD_D4;
  pinD5 = PINO_LCD_D5;
  pinD6 = PINO_LCD_D6;
  pinD7 = PINO_LCD_D7;
  pinVDD = PINO_LCD_VDD;
  pinLCDBacklight = PINO_LCD_BACKLIGHT;
  //CREATES LCD OBJECT
  lcd = LiquidCrystal lcd(pinRs,
                          pinEn,
                          pinD4,
                          pinD5,
                          pinD6,
                          pinD7);
  // LIGA LCD
  lcd.begin(pinLCDBacklight, pinVDD);
  lcd.print("LOVE IN THE ELEVATOR");
};

//Função para ler distância utilizando sonar
int Elevador::lerSonar(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(pinTrigSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigSensor, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(pinEchoSensor, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  // Serial.print("Distance = ");
  // Serial.print(distance);
  // Serial.println(" cm");

  delay(50);
  return distance;
}

bool Elevador::lerBotao(){
   int digitalVal = digitalRead(pinButton); // Take a reading
   if(HIGH == digitalVal){
     mostrarNaTela("APERTOU BOTAO");
     return true;}
   else{
     mostrarNaTela("SEM BOTAO");
     return false;}
}

//Função para ler estado atual
string Elevador::lerEstado() {
  return Elevador.estadoAtual;
}

//Função para mostrar em dispositivo LCD
bool Elevador::mostrarNaTela(string mensagem){
  lcd.print(string);
}

//Função que manda o servo para uma posição
bool Elevador::setPosServo(int pos){
  servo.write(pos);
}

// Funçao para setar o estado da maquina de estado do codigo
bool Elevador::configurarEstado(string estado){
  if estado == MOVENDO:
    Elevador.estadoAtual = MOVENDO;
    return true;

  if estado == MOVENDO:
    Elevador.estadoAtual = MOVENDO
    return true;
  return false;
}
