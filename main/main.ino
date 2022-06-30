#include "Elevador.h"//INCLUSÃO DA BIBLIOTECA NECESSÁRIA

bool ELEVADOR_LIGADO = true;
//Objeto Elevador
Elevador *elevador;

void setup (){
  //Essa função liga os sensores, o visor e escreve uma mensagem
  Serial.begin(9600);
}

void loop(){
  Elevador *elevador = new Elevador();
  elevador->configurarElevador();

  // Elevador LIGADO
  while(ELEVADOR_LIGADO){
    // Loop de esperar por comandos
    while(elevador->estadoAtual == PARADO){
      elevador->lerBotoes();}
    // Loop de ir para andar
    while(elevador->estadoAtual == MOVENDO){
      elevador->irParaAndar();
    }
  }
  };
