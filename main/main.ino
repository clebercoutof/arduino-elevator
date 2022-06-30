#include "Elevador.h"//INCLUSÃO DA BIBLIOTECA NECESSÁRIA

//Objeto Elevador
Elevador elevador;

void setup (){
  //Essa função liga os sensores, o visor e escreve uma mensagem
  elevador.configurarElevador();
  Serial.begin(9600);
}

void loop(){
  int testPos = 200;
  String testMessage = "A MENSAGEM";

  /** while(elevador.estadoAtual == PARADO){
    elevador.lerBotoes();
  } **/
  
  // Por padrão o estado atual sempre começa em parado, essa função deve ficar em loop lendo o botão
  // Código para testes individuais dos componentes
  if(elevador.estadoAtual == PARADO){
    elevador.lerSonar();
    elevador.setPosServo(testPos);
    elevador.mostrarNaTela(testMessage);};

  if(elevador.estadoAtual == MOVENDO){
    //elevador.estadoMoving();
    //função mover
  };

  };
