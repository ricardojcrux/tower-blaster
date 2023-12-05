/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724
*/

#include <iostream>

#include "Persona.h"

using namespace std;

/* Este es el constructor por defecto de la clase Persona */
Persona::Persona(){}

/* Este es un constructor que recibe un parametro index, el cual es el que usaremos, al que ademas anexamos la llamada a la clase Jugador, al ser de esta clase de la cual se hereda */
Persona::Persona(int index):Jugador(index){}

/* Este metodo comprueba si la persona tiene entre los valores de su torre el numero 48 o el numero 12, comodines de la partida, y retorna el numero de victoria correspondiente */
int Persona::preVictoria(){
    int victoria = 0;

    for(int i=0; i<10; i++){
        if(torre[index].casillaTorre(i) == 48)
            victoria += 1;
        else if(torre[index].casillaTorre(i) == 12)
            victoria += 2;
    }
    return victoria;
}

/* Este es el destructor respectivo de la clase Persona */
Persona::~Persona(){}