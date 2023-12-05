/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

- Cuenta con su constructor, el cual no recibe parámetros y crea un objeto Maquina y un objeto Persona, participantes del juego
- El metodo comenzarPartida() nos da el inicio del juego
- Los metodos instruccionesJuego() y creadoresJuego() nos muestra informacion sobre como jugar y los creadores de este juego
- Finalmente torresFinales() nos muestra la pantalla final al culminar una partida del juego
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "Juego.h"

using namespace std;

/* Este es el constructor respectivo de la clase Juego */
Juego::Juego(){
    srand(time(NULL));
    maquina = Maquina(0);
    persona = Persona(1);
}

/* Este metodo crea la partida del juego, y la lleva a cabo */
void Juego::comenzarPartida(){
    maquina.torreAleatoria();
    persona.torreAleatoria();
    int victoria = 0;
    int turno = 1;
    int numeroJuego = rand() % 50 + 1;

    victoria += persona.preVictoria();
    victoria += maquina.preVictoria();

    do{
        if(victoria > 0)
            break;

        cout<<"\n------ TURNO NUMERO "<<turno<<" ------\n";
        persona.mostrarTorre();

        cout<<"Turno persona"<<endl;

        numeroJuego = persona.turnoJugador(numeroJuego);
        victoria += persona.comprobarVictoria();
        victoria += persona.preVictoria();

        if(victoria > 0)
            break;

        cout<<"\nTurno maquina\n\n";
        sleep(3);

        numeroJuego = maquina.turnoJugador(numeroJuego);
        victoria += maquina.comprobarVictoria();
        victoria += maquina.preVictoria();

        sleep(1);

        turno++;

    } while (turno <= 50);

    if(turno == 51){
        if(maquina.puntajeFinal() > persona.puntajeFinal())
            victoria = 1;
        else
            victoria = 2;
    }

    switch (victoria){
        case 1:
            cout<<"\n----- HAZ PERDIDO -----\n";
            this->torresFinales();
            break;
        case 2:
            cout<<"\n----- HAZ GANADO -----\n";
            this->torresFinales();
            break;
        default:
            this->comenzarPartida();
            break;
    }
    
}

/* Este metodo muestra el resultado final de las torres cuando la partida finaliza */
void Juego::torresFinales(){
    cout<<"\nMaquina: ";
    maquina.torreVictoria();
    cout<<"\nPersona: ";
    persona.torreVictoria();
}

/* Este metodo permite mostrar las instrucciones del juego al usuario, es decir, el como jugarlo */
void Juego::instruccionesJuego(){
    cout<<"\n------ INSTRUCCIONES DEL JUEGO ------\n";
    cout<<"El juego empieza con dos torres de 10 numeros aleatorios que estan en un rango del 1 al 50\n\n";
    sleep(2);
    cout<<"|- TORRE 1 -|\t\t|- TORRE 2 -|\n"
        <<"|- MAQUINA -|\t\t|- JUGADOR -|\n"
        <<"     |**|\t\t     |29|\n"
        <<"     |**|\t\t     |30|\n"
        <<"     |**|\t\t     |01|\n"
        <<"     |**|\t\t     |34|\n"
        <<"     |**|\t\t     |35|\n"
        <<"     |**|\t\t     |27|\n"
        <<"     |**|\t\t     |19|\n"
        <<"     |**|\t\t     |11|\n"
        <<"     |**|\t\t     |50|\n"
        <<"     |**|\t\t     |12|\n\n";
    sleep(2);
    cout<<"Nuestro objetivo es hacer que nuestra torre este ordenada de menor a mayor antes que la maquina lo logre\n"
        <<"Para ello contaremos con 50 turnos, suficientes para lograrlo\n\n";
    sleep(3);
    cout<<"------ DINAMICA DEL JUEGO ------\n";
    sleep(1);
    cout<<"Cuando sea tu primer turno se te preguntara lo siguiente: \n"
        <<"Desea cambiar un bloque? (S o N): \n"
        <<"Donde debes contestas S para si o N para no\n\n";
    sleep(3);
    cout<<"Si contestamos no, cederemos el turno a la maquina\n"
        <<"Si contestamos si, empezara nuestro turno con un numero aleatorio, y nos saldra un nuevo menu:\n\n";
    sleep(3);
    cout<<"[1] Seleccionar el numero x\n"
        <<"[2] Deseo generar otro numero\n"
        <<"Elija una opcion:\n"
        <<"Donde x es el numero generado al principio del turno\n\n";
    sleep(3);
    cout<<"Si selecciona 1 entonces cambiaremos ese numero por uno de nuestra torre\n"
        <<"Si seleccionamos 2 entonces generara un nuevo numero y nos preguntara lo siguiente:\n\n";
    sleep(3);
    cout<<"Elija una opcion:\n"
        <<"[1] Seleccionar el numero x\n"
        <<"[2] Terminar mi turno\n"
        <<"O selecciono el numero aleatorio o cedo el turno a la maquina\n\n";
    sleep(3);
    cout<<"Si elegimos un numero, el juego nos pedira que lo reemplazemos en una posicion\n\n"
        <<"Digite la posicion a intercambiar: \n"
        <<"Las posiciones se cuentan de arriba hacia abajo, comenzando desde el 1 hasta el 10\n";
    sleep(3);
    cout<<"Al intercambiar el numero, nuestro numero original entra a la torre en la posicion previamente dicha\n"
        <<"En cambio, el numero que estaba en esa posicion de la torre sale a juego.\n\n";
    sleep(3);
    cout<<"------ DATOS ADICIONALES ------\n";
    sleep(1);
    cout<<"[1] Si entre filas hay valores consecutivos (Por ejemplo 29 y 30), se sumaran esos valores a su tabla de puntos\n";
    sleep(2);
    cout<<"[2] Si sale el numero 48, el jugador a quien salga perdera directamente la partida\n";
    sleep(2);
    cout<<"[3] En cambio, si sale el numero 12, el jugador a quien salga automaticamente obtiene la victoria\n";
    sleep(2);
    cout<<"[4] Si al acabar los turnos, nadie ordena la torre, ganara quien tenga mas puntos acumulados\n\n";
    sleep(2);
    cout<<"------ DEMOSTRACION DE JUEGO -------\n\n";
    sleep(1);
    cout<<"|- TORRE 1 -|\t\t|- TORRE 2 -|\n"
        <<"|- MAQUINA -|\t\t|- JUGADOR -|\n"
        <<"     |**|\t\t     |29|\n"
        <<"     |**|\t\t     |30|\n"
        <<"     |**|\t\t     |01|\n"
        <<"     |**|\t\t     |34|\n"
        <<"     |**|\t\t     |35|\n"
        <<"     |**|\t\t     |27|\n"
        <<"     |**|\t\t     |19|\n"
        <<"     |**|\t\t     |11|\n"
        <<"     |**|\t\t     |50|\n"
        <<"     |**|\t\t     |12|\n\n";
    sleep(3);
    cout<<"Desea cambiar un bloque? (S o N): ";
    sleep(1);
    cout<<"S";
    sleep(1);
    cout<<"\n\n[1] Seleccionar el numero 36\n"
        <<"[2] Deseo generar otro numero\n"
        <<"Elija una opcion: ";
    sleep(2);
    cout<<"1";
    sleep(1);
    cout<<"\n\nDigite la posicion a intercambiar: ";
    sleep(1);
    cout<<"6";
    sleep(1);
    cout<<"\n\nCambiaste el 27 por el 36\n"
        <<"Conseguiste 105 puntos en este turno\n\n";
    sleep(2);
    cout<<"|- TORRE 1 -|\t\t|- TORRE 2 -|\n"
        <<"|- MAQUINA -|\t\t|- JUGADOR -|\n"
        <<"     |**|\t\t     |29|\n"
        <<"     |**|\t\t     |30|\n"
        <<"     |**|\t\t     |01|\n"
        <<"     |**|\t\t     |34|\n"
        <<"     |**|\t\t     |35|\n"
        <<"     |**|\t\t     |36|\n"
        <<"     |**|\t\t     |19|\n"
        <<"     |**|\t\t     |11|\n"
        <<"     |**|\t\t     |50|\n"
        <<"     |**|\t\t     |12|\n\n"
        <<"PUNTAJE: 105\n\n";
    sleep(2);
    cout<<"Y ahora la maquina jugara con el 27 que nosotros descartamos y asi seguiremos el ciclo.\n";
    sleep(2);
    cout<<"ESTAS LISTO PARA JUGAR?\n\n";
    sleep(1);
}

/* Este metodo permite mostrar los nombres de los creadores del juego */
void Juego::creadoresJuego(){
    cout<<"\nCreado por:\n"
        <<"Mauricio Andres Teheran Bertel\t202324545-2724\n"
        <<"Ricardo de Jesus Zapata Cruz\t202323291-2724\n\n";
    sleep(1);
}

/* Este es el destructor respectivo de la clase Juego */
Juego::~Juego(){}

