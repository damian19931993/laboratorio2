#include "Nivel3.h"

#include<iostream>
#include <string.h>
using namespace std;

Nivel3::Nivel3(sf::RenderWindow& vent,Jugador& jug): Nivel(vent,jug,2,4,2){
    obstaculos[0] = Obstaculo(150, 300, 450);
    obstaculos[1] = Obstaculo(150, 500, 450);
    int posicionesX[] = { 200, 350, 450,550 };
    int posicionesY[] = { 400, 400, 400,400 };
    setMonedas(posicionesX, posicionesY, 4);
    fuegos[0]=Fuego(600,375);
    fuegos[1]=Fuego(1000,375);


}

void Nivel3::dibujar(){
    Nivel::dibujar();
}

void Nivel3::manejarEntrada(){
    Nivel::manejarEntrada();
}

void Nivel3::eventos(){
    Nivel::eventos();
}
