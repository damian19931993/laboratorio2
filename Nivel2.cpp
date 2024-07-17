#include "Nivel2.h"

#include<iostream>
#include <string.h>
using namespace std;

Nivel2::Nivel2(sf::RenderWindow& vent,Jugador& jug): Nivel(vent,jug,1,2,0){
    obstaculos[0] = Obstaculo(150, 475, 450); // Inicializar el primer obstáculo

    int posicionesX[] = { 200, 350};
    int posicionesY[] = { 400, 400};
    setMonedas(posicionesX, posicionesY, 2);

}

void Nivel2::dibujar(){
    Nivel::dibujar();
}

void Nivel2::manejarEntrada(){
    Nivel::manejarEntrada();
}

void Nivel2::eventos(){
    Nivel::eventos();
}
