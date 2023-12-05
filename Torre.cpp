/*
Integrantes:
Ricardo de Jesus Zapata Cruz    zapata.ricardo@correounivalle.edu.co      202323291-2724
Mauricio Andrés Teherán Bertel  mauricio.teheran@correounivalle.edu.co    202324545-2724
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Torre.h"

using namespace std;

/* Este es el constructor respectivo de la clase Torre */
Torre::Torre(){
    srand(time(NULL));
    for(int i=0; i<50; i++){
        numeros[i] = i+1;}
}

/* Este metodo asigna valores del 1 al 50 sin repetir en cada bloque de la torre */
void Torre::crearTorre(){
    int index;
    for(int i=0; i<10;i++){
        do{
            index = numeros[rand() % 50];
        } while (index == 0);
        torre[i] = index;
        numeros[index-1] = 0;
    }
}

/* Este metodo retorna un valor de la torre, en la posicion recibida por parametro, como un string */
string Torre::mostrarValor(int pos){
    if(torre[pos] < 10)
        return "0" + to_string(torre[pos]);
    else
        return to_string(torre[pos]);
}

/* Este metodo intercambia un valor que recibe por parametro por un valor que esta en la torre creada, en la posicion que tambien recibe por parametro, y retorna el numero que previamente estaba en esea posicion de la torre */
int Torre::intercambiarValor(int pos, int numeroJuego){
    int numeroAnterior = torre[pos];
    torre[pos] = numeroJuego;
    return numeroAnterior;
}

/* Este metodo verifica si, dada una posicion de la torre, el valor en esa posicion tiene una seguidilla (33-34-35 por ejemplo), tanto hacia arriba como hacia abajo del mismo, retorna la suma de los numeros de la seguidilla (102 en el ejemplo anterior) */
int Torre::numerosSeguidos(int posicion){
    int sumatoria = 0;
    int pos = posicion;
    while(torre[pos] == (torre[pos-1] + 1) && pos-1 >= 0){
        sumatoria += torre[pos-1];
        pos--; 
    }
    pos = posicion;
    while(torre[pos] == (torre[pos+1] - 1) && pos+1 < 10){
        sumatoria += torre[pos+1];
        pos++;
    }
    if(sumatoria > 0){
        sumatoria += torre[posicion];
    }
    return sumatoria;
}

/* Este metodo verifica si la torre se encuentra ordenada de manera descendente, comparando todos los valores desde el primero hasta el penultimo, si encuentra que alguno no esta ordenado retorna false, en caso contrario retorna true */
bool Torre::comprobarVictoria(){
    for(int i=0; i<9; i++){
        if(torre[i] >= torre[i+1])
            return false;  
    } return true;
}

/* Este metodo retorna un valor de la torre en una cierta posicion */
int Torre::casillaTorre(int posicion){
    return torre[posicion];
}

/* Este es el destructor respectivo de la clase Torre */
Torre::~Torre(){}