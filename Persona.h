/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Maquina.h: 

- Esta clase tiene como objetivo especificar metodos de Persona
- Al ser una clase hija de Jugador.h, hereda todos sus metodos.
- La relacion de esta clase es de herencia con la clase Jugador, ya que esta clase tiene los metodos y atributos que compartian tanto Maquina como Persona en el contexto del programa.
*/

#ifndef PERSONA_H
#define PERSONA_H
#include "Jugador.h"

class Persona : public Jugador{      
    public:
        Persona();
        Persona(int);
        int preVictoria();
        ~Persona();
};
#else
class Persona;
#endif