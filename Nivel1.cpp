#include "Nivel1.h"

Nivel1::Nivel1(sf::RenderWindow& vent,Jugador& jug): Nivel(vent,jug,2,3){
    //obstaculos[0] = Obstaculo(150, 300, 450); // Inicializar el primer obstáculo
    //obstaculos[1] = Obstaculo(150, 500, 450); // Inicializar el segundo obstáculo
    // Posiciones de las monedas para este nivel
    //int posicionesX[] = { 200, 350, 450 };
    //int posicionesY[] = { 400, 400, 400 };
    //setMonedas(posicionesX, posicionesY, 3);
}

void Nivel1::dibujar(){
    Nivel::dibujar();
}

void Nivel1::manejarEntrada(){
    Nivel::manejarEntrada();
}

void Nivel1::eventos(){
    Nivel::eventos();
}
