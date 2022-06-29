// Elevador.cpp
#include "Elevador.h"

// O construtor é chamado quando eu declaro o meu objeto
Elevador::Elevador() {
  estadoAtual = PARADO;
  // Declaração dos andares
  P0.piso   = 0;
  P0.nome   ="P0";
  P0.altura = 0;

  P1.piso   = 1;
  P1.nome   = "P1";
  P1.altura = 30;

  P2.piso   = 2;
  P2.nome   ="P2";
  P2.altura = 60;

  andarAtual = P0;
  andarDestino = P1;
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
  pinButtonTroca = PINO_BOTAO_TROCA;
  pinMode(pinButtonTroca,INPUT_PULLUP); // Set the Tilt Switch as an input

  // Configuração do botão
  pinButtonGo = PINO_BOTAO_GO;
  pinMode(pinButtonGo,INPUT_PULLUP); // Set the Tilt Switch as an input
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
  LiquidCrystal *lcd = new LiquidCrystal(pinRs,
                          pinEn,
                          pinD4,
                          pinD5,
                          pinD6,
                          pinD7);
  // LIGA LCD
  lcd->begin(pinLCDBacklight, pinVDD);
  lcd->print("LOVE IN THE ELEVATOR");
};

//Função para ler distância utilizando sonar
int Elevador::lerSonar(){
  int distance;
  long duration;
  digitalWrite(pinTrigSensor, LOW);
  delayMicroseconds(2);

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

bool Elevador::lerBotaoTroca(){
   int digitalVal = digitalRead(pinButtonTroca); // Take a reading
   if(HIGH == digitalVal){
     mostrarNaTela("TROCOU ANDAR");
     // TROCAR ANDARES
     return true;}
   else{
    // DISPLAY ANDARES
     return false;}
}

bool Elevador::lerBotaoGo(){
   int digitalVal = digitalRead(pinButtonGo); // Take a reading
   if(HIGH == digitalVal and andarAtual.piso != andarDestino.piso){
     estadoAtual = MOVENDO;
     return true;}
   else{
    // DISPLAY ANDARES
     return false;}
}

bool Elevador::lerBotoes(){
   if(lerBotaoGo()){
    estadoAtual = MOVENDO;
    mostrarNaTela("GO");
    return true;
   }
   else if(lerBotaoTroca()){
    // DISPLAY ANDARES
    return true;}

  else{
    // DISPLAY ANDARES
    return false;
  }
   }

String Elevador::displayAndares(){
  //String andar_atual = ANDAR_ATUAL
}

//Função para ler estado atual
String Elevador::lerEstado() {
  return estadoAtual;
}

//Função para mostrar em dispositivo LCD
void Elevador::mostrarNaTela(String mensagem){
  this->lcd->print(mensagem);
}

//Função que manda o servo para uma posição
bool Elevador::setPosServo(int pos){
  servo.write(pos);
}

// Funçao para setar o estado da maquina de estado do codigo
bool Elevador::configurarEstado(String estado){
  if(estadoAtual == MOVENDO){
    estadoAtual = MOVENDO;
    return true;}

  if(estadoAtual == MOVENDO){
    estadoAtual = MOVENDO;
    return true;}

  return false;
}
