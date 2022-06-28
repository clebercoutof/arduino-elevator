#include "Elevador.h"//INCLUSÃO DA BIBLIOTECA NECESSÁRIA

//Objeto Elevador
Elevador elevador;

void setup (){
  //Essa função liga os sensores, o visor e escreve uma mensagem
  elevador.configurarElevador();
  Serial.begin(9600);
}

void loop(){
  int testPos = 10;
  String testMessage = "A MENSAGEM";

  // Por padrão o estado atual sempre começa em parado, essa função deve ficar em loop lendo o botão
  if(elevador.estadoAtual == PARADO){
    elevador.lerBotao();
    elevador.lerSonar();
    elevador.setPosServo(testPos);
    elevador.mostrarNaTela(testMessage);

    // elevador.estadoWaitingForInput();
    // mostrar SELEÇÃO
    };

  if(elevador.estadoAtual == MOVENDO){
    // elevador.estadoMoving();
    // função mover
  };

  };
