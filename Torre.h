/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Torre.h: 

- Esta clase tiene como objetivo manejar todo lo relacionado con las torres del juego
- Ademas, esta clase tiene una relacion de composicion con la clase Jugador, cada jugador tiene una unica torre que al finalizar el juego, se eliminará junto a él.
*/

#ifndef TORRE_H
#define TORRE_H

#include <string>

class Torre{
    private:
        int numeros[50];
        int torre[10];

    public:
        Torre();
        void crearTorre();
        std::string mostrarValor(int);
        int intercambiarValor(int, int);
        int numerosSeguidos(int);
        bool comprobarVictoria();
        int casillaTorre(int);
        ~Torre();
    
};
#else
class Torre;
#endif