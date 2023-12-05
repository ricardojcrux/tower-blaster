/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Maquina.h"

using namespace std;

/* Este es el constructor por defecto de la clase Maquina */
Maquina::Maquina(){
    srand(time(NULL));
}

/* Este es un constructor que recibe un parametro index, el cual es el que usaremos, al que ademas anexamos la llamada a la clase Jugador, al ser de esta clase de la cual se hereda */
Maquina::Maquina(int index):Jugador(index){}

int Maquina::turnoJugador(int numeroJuego){
    int pos = this->comprobarMatch(numeroJuego);
    int numeroCambiado = numeroJuego;

    cout<<"La maquina juega con el numero: "<<numeroJuego<<endl;
    
    if(pos == 0 || numeroJuego == 48){
        numeroJuego = rand() % 50 + 1;
        cout<<"La maquina genero otro numero: "<<numeroJuego<<endl;

        pos = this->comprobarMatch(numeroJuego);

        if(pos == 0)
            cout<<"La maquina termina su turno"<<endl;

    } if(pos != 0 || numeroJuego == 12){
        numeroCambiado = torre[index].intercambiarValor(pos, numeroJuego);

        cout<<"La maquina cambio el "<<numeroCambiado<<" por el "<<numeroJuego<<endl;
    }

    return numeroCambiado;
}

/* Este metodo comprueba si la maquina tiene entre los valores de su torre el numero 48 o el numero 12, comodines de la partida, y retorna el numero de victoria correspondiente */
int Maquina::preVictoria(){
    int victoria = 0;

    for(int i=0; i<10; i++){
        if(torre[index].casillaTorre(i) == 48)
            victoria += 2;
        else if(torre[index].casillaTorre(i) == 12)
            victoria += 1;
    }
    return victoria;
}

/* Este metodo tiene un algoritmo con el cual la maquina podra jugar de una manera logica con el fin de ganar la partida */
int Maquina::comprobarMatch(int numeroJuego){
    for(int i=1; i<9; i++){
        if((numeroJuego < torre[index].casillaTorre(i+1)) && (numeroJuego > torre[index].casillaTorre(i-1)))
            return i;
    } return 0;
}

/* Este es el destructor respectivo de la clase Maquina */
Maquina::~Maquina(){}
