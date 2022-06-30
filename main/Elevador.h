// Elevador.h
#ifndef Elevador_h
#define Elevador_h

#include <Arduino.h>
#include <Servo.h> //INCLUSÃO DA BIBLIOTECA DE SERVO
#include <Ultrasonic.h>  //INCLUSAO DA BIBLIOTECA DE SERVO
#include <LiquidCrystal.h> // INCLUSAO BIBLIOTECA LCD
#include <AutoPID.h>

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
const int PINO_INPUT_SENSOR = 12; //PINO DIGITAL UTILIZADO PELO SONAR
const int PINO_OUTPUT_SENSOR = 13; //PINO DIGITAL UTILIZADO PELO SONAR

const int SERVO_START_POSITION = 0; // POSICAO INICIAL DO SERVO
const int SERVO_STOP_POSITION = 90; // POSICAO PARA PARAR O SERVO

// Altura dos andares em centimetro
const int ALTURA_0 = 0;
const int ALTURA_1 = 44;
const int ALTURA_2 = 85;
const int ALTURA_MAXIMA_PERIGO = 90;

const String MOVENDO = "MOVENDO";
const String PARADO = "PARADO";

//Tolerancia de altura em centimetrosc
const int TOLERANCIA_ALTURA_ANDAR = 1;

#define OUTPUT_MIN -300
#define OUTPUT_MAX 300
#define KP 1.0
#define KI 0.8
#define KD 0.5

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
      bool configurarDispositivos(); // Funçao para configurar dispositivos e portas
      bool configurarLCD();

  public:
    Elevador(); // Construtor da Classe
    Andar andarAtual; // Variavel para armazenar o Andar ATUAL
    Andar andarDestino;// Variavel para armazenar o Andar DESTINO
    Andar P0; // Variavel para armazenar os dados do PISO 0
    Andar P1; // Variavel para armazenar os dados do PISO 1 
    Andar P2; // Variavel para armazenar os dados do PISO 2

    bool setPosServo(int pos); // Set position do servo
    
    int controlePID(int sensorRead); // Função que realiza controle PID retornando o comando par ao servo
    void irParaAndar(); // Função utilizada para mover para andar
    
    String estadoAtual; //Declaraçao estado atual
    bool estadoWaitingForInput(); //Declaração função de estados

    String lerEstado(); // Função que lê estado
    String displayAndares();// Função para display Andares
    
    bool lerBotaoGo(); // Função que lê valor do botão GO
    bool lerBotaoTroca(); // Função que lê valor do botão TROCA
    bool lerBotoes();// Função que lê valor doS dois botões
    int lerSonar();// Função que lê valor do sensor utlrasom

    bool configurarElevador(); // Função utilizada para configurar um elevador
    void mostrarNaTela(String mensagem); // Função para mostrar na tela
    bool configurarEstado(String estado);// Funçao que configura um estado
  };
  
#endif
