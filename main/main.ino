#include "Elevador.h"//INCLUSÃO DA BIBLIOTECA NECESSÁRIA

//Objeto Elevador
Elevador *elevador;

void setup (){
  //Essa função liga os sensores, o visor e escreve uma mensagem
  Serial.begin(9600);
}

void loop(){
  Elevador *elevador = new Elevador();
  elevador->configurarElevador();

  while(elevador->estadoAtual == PARADO){
    elevador->lerBotoes();}

  };
