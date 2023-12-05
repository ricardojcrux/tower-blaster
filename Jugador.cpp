/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724

- Tiene como parametro un index, y un array int de puntaje y un array Torre de torre
- Su constructor recibe un parametro index, con el fin de usar un espacio del array para cada jugador.
- el metodo torreAleatoria() llena la torre de valores aleatorios, mientras mostrarTorre() nos la muestra en pantalla.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Jugador.h"

using namespace std;

/* Este es el constructor por defecto de la clase Jugador */
Jugador::Jugador(){
    srand(time(NULL));
}

/* Este es un constructor que recibe un parametro index, el cual es el que usaremos */
Jugador::Jugador(int index){
    this->index = index;
    torre[index] = Torre();
    puntaje[index] = 0;
}

/* Este metodo crea la torre basado en una lista de numeros, con el fin de no repetir ninguno */
void Jugador::torreAleatoria(){
    torre[index].crearTorre();
    puntaje[index] = 0;
}

/* Este metodo permite mostrar las torres del juego, ocultando los valores de la torre de la maquina */
void Jugador::mostrarTorre(){
    cout<<"\n|- MAQUINA -|\t\t|- JUGADOR -|\n";

    for(int i=0; i<10;i++)   
        cout<<"     |**|\t\t     |"<<torre[index].mostrarValor(i)<<"|\n";
    cout<<endl;

    if(puntaje[index] > 0)
        cout<<"PUNTAJE: "<<puntaje[index]<<endl<<endl; 
}

/* Este metodo le da la opcion al usuario de tomar o no su turno, con el fin de cambiar un numero de su torre por el numero en juego, y retorna ese numero que estaba en la torre anteriormente */
int Jugador::turnoJugador(int numeroJuego){
    string cambiarBloque, aux;
    int option = 1;

    do{
        cout<<"Desea cambiar un bloque? (S o N): ";
        getline(cin, cambiarBloque);
    } while (cambiarBloque != "S" && cambiarBloque != "N");

    if(cambiarBloque == "S"){
        do{
            if(option != 1 && option !=2)
                cout<<"Digite una opcion valida\n";

            cout<<"\n[1] Seleccionar el numero "<< numeroJuego <<endl
                <<"[2] Deseo generar otro numero\n"
                <<"Elija una opcion: ";
            getline(cin, aux);

            if(aux >= "0" && aux <= "9")
                option = stoi(aux);
            else
                option = 0;
                
        } while (option != 1 && option != 2);

        switch (option){
            case 1:
                numeroJuego = this->intercambiarValor(numeroJuego);
                break;
            case 2:
                numeroJuego = this->menuAleatorio(numeroJuego);
                break;
        }
    }else{cout<<"Haz cedido tu turno\n";}
    return numeroJuego;
}

/* Este metodo recibe un int numeroJuego que reemplazará por un numero en la torre segun la posicion que haya sido indicada, para luego retornar el numero que previamente estaba en esa posicion */
int Jugador::intercambiarValor(int numeroJuego){
    string aux;
    int pos;
    do{
        cout<<"\nDigite la posicion a intercambiar: ";
        getline(cin, aux);

        if((aux >= "0" && aux <= "9") || aux == "10")
            pos = stoi(aux) - 1;
        else
            pos = -1;

    } while (pos < 0 || pos > 9);

    int numeroCambiado = torre[index].intercambiarValor(pos, numeroJuego);

    cout<<"Cambiaste el "<<numeroCambiado<<" por el "<<numeroJuego<<endl;

    int puntajeTurno = torre[index].numerosSeguidos(pos);

    if(puntajeTurno > 0){
        cout<<"Conseguiste "<<puntajeTurno<<" puntos en este turno\n";
        puntaje[index] += puntajeTurno;
    }
    return numeroCambiado;
}

/* Este metodo se ejecuta cuando el usuario no desea el numero en juego, por lo tanto, se le dio la opcion de generar un numero aleatorio y el accedió. Retorna el numeroJuego que fue cambiado */
int Jugador::menuAleatorio(int numeroJuego){
    int option = 1;
    int numeroAleatorio = rand() % 50 + 1;
    string aux;

    do{
        if(option != 1 && option !=2)
            cout<<"Digite una opcion valida\n";
            
        cout<<"\n[1] Seleccionar el numero "<< numeroAleatorio <<endl
            <<"[2] Terminar mi turno\n"
            <<"Elija una opcion: ";
            getline(cin, aux);

            if(aux >= "0" && aux <= "9")
                option = stoi(aux);
            else
                option = 0;

        } while (option != 1 && option != 2);

    switch (option){
        case 1:
            numeroJuego = this->intercambiarValor(numeroAleatorio);
            break;
        case 2:
            cout<<"\nTu turno ha terminado\n";
            numeroJuego = numeroAleatorio;
            break;
        }
    return numeroJuego;
}

/* Este metodo se encarga de comprobar la victoria del jugador (Maquina o Persona), retorna un valor int que determina quien es el ganador */
int Jugador::comprobarVictoria(){
    if(torre[index].comprobarVictoria())
        return (index+1);
    return 0;
}

/* Este metodo muestra la torre del jugador una vez finalizada la partida. */
void Jugador::torreVictoria(){
    for(int i=0; i<10;i++){   
        if(torre[index].mostrarValor(i) == "48" || torre[index].mostrarValor(i) == "12")
            cout<<"["<<torre[index].mostrarValor(i)<<"] ";
        else
            cout<<" "<<torre[index].mostrarValor(i)<<"  ";}

    cout<<"Puntaje: "<<puntaje[index]<<endl;
}

/* Este metodo retorna el puntaje una vez finalizado el juego */
int Jugador::puntajeFinal(){
    return puntaje[index];
}

/* Este es el destructor respectivo de la clase Jugador */
Jugador::~Jugador(){}