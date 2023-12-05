/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Juego.h: 

- Esta clase tiene como objetivo la creacion del juego, y el control de las opciones del mismo.

*/

#ifndef JUEGO_H
#define JUEGO_H

#include "Maquina.h"
#include "Persona.h"

class Juego{
    private:
        Maquina maquina;
        Persona persona;

    public:
        Juego();
        void comenzarPartida();
        void torresFinales();
        void instruccionesJuego();
        void creadoresJuego();
        ~Juego();
};
#else
class Juego;
#endif