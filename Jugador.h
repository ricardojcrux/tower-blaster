/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Jugador.h: 

- Esta clase tiene como objetivo generalizar las caracteristicas de los jugadores Maquina y Persona
- Es la clase padre de las clases anteriormente mencionadas
- Ademas, esta clase tiene una relacion de composicion con la clase Juego, ya que necesita ser creada ahi para poder existir, y solo existe mientras el juego siga ejecutandose.
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include "Torre.h"

class Jugador{
    protected:
        int index;
        int puntaje[2];
        Torre torre[2];

    public:
        Jugador();
        Jugador(int); 
        virtual void torreAleatoria();
        virtual void mostrarTorre();
        virtual int turnoJugador(int);
        virtual int intercambiarValor(int);
        virtual int menuAleatorio(int);
        virtual int comprobarVictoria();
        virtual void torreVictoria();
        virtual int puntajeFinal();
        ~Jugador();
    
};
#else
class Jugador;
#endif