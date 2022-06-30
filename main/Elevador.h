// Elevador.h
#ifndef Elevador_h
#define Elevador_h

#include <Arduino.h>
#include <Servo.h> //INCLUSÃO DA BIBLIOTECA DE SERVO
#include <Ultrasonic.h>  //INCLUSAO DA BIBLIOTECA DE SERVO
#include <LiquidCrystal.h> // INCLUSAO BIBLIOTECA LCD

const int PINO_LCD_VDD = 2; // PINO PARA ATIVAR LCD
const int PINO_LCD_BACKLIGHT = 16; // PINO PARA ATIVAR PINO_LCD

const int PINO_LCD_RS = 5; //PINO DIGITAL UTILIZADO PELO LCD
const int PINO_LCD_ENABLE = 5; //PINO DIGITAL UTILIZADO PELO LCD
const int PINO_LCD_D4 = 5; //PINO DIGITAL UTILIZADO PELO LCD
const int PINO_LCD_D5 = 5; //PINO DIGITAL UTILIZADO PELO LCD
const int PINO_LCD_D6 = 5; //PINO DIGITAL UTILIZADO PELO LCD
const int PINO_LCD_D7 = 5; //PINO DIGITAL UTILIZADO PELO LCD

const int PINO_SERVO = 6; //PINO DIGITAL UTILIZADO PELO SERVO
const int PINO_BOTAO_TROCA = 7; //PINO DIGITAL UTILIZADO PELO BOTAO
const int PINO_BOTAO_GO = 10; //PINO DIGITAL UTILIZADO PELO BOTAO
const int PINO_INPUT_SENSOR = 8; //PINO DIGITAL UTILIZADO PELO SONAR
const int PINO_OUTPUT_SENSOR = 9; //PINO DIGITAL UTILIZADO PELO SONAR

const int SERVO_START_POSITION = 0; // POSICAO INICIAL DO SERVO

// Altura dos andares em centimetro
const int ALTURA_0 = 0;
const int ALTURA_1 = 30;
const int ALTURA_2 = 60;

const String MOVENDO = "MOVENDO";
const String PARADO = "PARADO";

//Tolerancia de altura em centimetrosc
const int TOLERANCIA_ALTURA_ANDAR = 1;

struct Andar{
  int piso;
  String nome;
  int altura;
};

class Elevador {
  // Funções que não serão acessadas pelo condigo principal
  private:
      // Declarção de variaveis internas de pinos
      int pinServo;
      int pinButtonTroca;
      int pinButtonGo;
      // Pinos Sonar
      int pinTrigSensor, pinEchoSensor;
      // Pinos LCD
      int pinRs, pinEn, pinD4, pinD5, pinD6, pinD7,pinVDD,pinLCDBacklight;

      int i_andar;
      // Funções de uso internas para configuração dos dispositivos fisicos
      bool configurarDispositivos();
      bool configurarLCD();

  public:
    // Declaração da classe
    Elevador();
    //Declaraçao dos andares
    Andar andarAtual;
    Andar andarDestino;
    Andar P0;
    Andar P1;
    Andar P2;

    int alturaAtual;
    int alturaDestino;
    LiquidCrystal *lcd;
    //Variaveis do servo
    Servo servo;
    int positionServo;
    bool setPosServo(int pos);
    //Declaraçao estado atual
    String estadoAtual;
    //Ultrasonic object
    Ultrasonic *ultrasonic; 

    //Declaração função de estados
    bool estadoWaitingForInput();
    bool estadoMoving();
    // Função que lê estado
    String lerEstado();
    // Display Andares
    String displayAndares();
    // Função que lê valor do botão
    bool lerBotaoGo();
    // Função que lê valor do botão
    bool lerBotaoTroca();
    // Função que lê valor dos botoes
    bool lerBotoes();
    // Função que lê valor do botão
    int lerSonar();
    // Função para mostrar na tela
    void mostrarNaTela(String mensagem);

    // Funçao que manda um estado
    bool configurarEstado(String estado);
    // Declaração função configurar elevador
    bool configurarElevador();
  };
  
#endif
