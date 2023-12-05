/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

Este programa está basado en el popular Juego Tower Blaster, el cual consiste en ganarle a la Torre Rival de la Maquina acumulando el mayor número de consecutivos para una Torre de diez posiciones de tu Torre Persona, pero ten mucho cuidado porque si sale el número 48 a la Maquina automáticamente perdiste, aunque para ser las cosas justas si te sale el 12 ganaste

En esta parte del programa encontrarás el menú para comenzar el Juego, donde debes de elegir 1 si quieres conocer las reglas y pormenores del Juego, 2 para comenzar a jugar, 3 para conocer los creadores de este maravilloso reto y 4 para salir. Así que sin más preámbulo ánimo y mucha suerte-

*/

#include <iostream>
#include <string>
#include "Juego.h"

using namespace std;

int main(){
    int option;
    string aux;

    Juego juego = Juego();

    do{
        cout<<"\n------ BIENVENIDO A TOWER BLASTER ------\n"
            <<"[1] Instrucciones del juego\n"
            <<"[2] Comenzar partida\n"
            <<"[3] Creadores\n"
            <<"[4] Salir del juego\n"
            <<"Seleccione una opcion: ";
        getline(cin, aux);
        option = stoi(aux);

        switch (option){
            case 1:
                juego.instruccionesJuego();
                break;
            case 2:
                cout<<"\n------ COMENZANDO PARTIDA ------"<<endl;
                juego.comenzarPartida();
                break;
            case 3:
                juego.creadoresJuego();
                break;
            case 4:
                break;
            default:
                cout<<"Seleccione una opcion valida\n\n";
            }
    } while (option != 4 );

    return 0;
}