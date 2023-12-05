/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Maquina.h: 

- Esta clase tiene como objetivo especificar metodos de Maquina
- Al ser una clase hija de Jugador.h, hereda todos sus metodos.
- La relacion de esta clase es de herencia con la clase Jugador, ya que esta clase tiene los metodos y atributos que compartian tanto Maquina como Persona en el contexto del programa.
*/

#ifndef MAQUINA_H
#define MAQUINA_H
#include "Jugador.h"

class Maquina : public Jugador{
    public:
        Maquina();
        Maquina(int);
        int turnoJugador(int);
        int preVictoria();
        int comprobarMatch(int);
        ~Maquina();
};
#else
class Maquina;
#endif