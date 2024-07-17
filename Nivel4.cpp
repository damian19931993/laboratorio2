#include "Nivel4.h"

#include<iostream>
#include <string.h>
using namespace std;

Nivel4::Nivel4(sf::RenderWindow& vent,Jugador& jug): Nivel(vent,jug,3,4,4){
    obstaculos[0] = Obstaculo(150, 300, 450);
    obstaculos[1] = Obstaculo(150, 500, 450);
    obstaculos[2] = Obstaculo(150,700,450);
    int posicionesX[] = { 200, 350, 450,550 };
    int posicionesY[] = { 400, 400, 400,400 };
    setMonedas(posicionesX, posicionesY, 4);
    fuegos[0]=Fuego(600,375);
    fuegos[1]=Fuego(800,375);
    fuegos[2]=Fuego(1000,375);
    fuegos[3]=Fuego(1200,375);

}

void Nivel4::dibujar(){
    Nivel::dibujar();
}

void Nivel4::manejarEntrada(){
    Nivel::manejarEntrada();
}

void Nivel4::eventos(){
    Nivel::eventos();
}
