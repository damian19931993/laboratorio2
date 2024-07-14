#include "Nivel1.h"

Nivel1::Nivel1(sf::RenderWindow& vent): Nivel(vent,2,3){
    obstaculos[0] = Obstaculo(150, 300, 450); // Inicializar el primer obstáculo
    obstaculos[1] = Obstaculo(150, 500, 450); // Inicializar el segundo obstáculo
    monedas[0]= Moneda(200, 400);
    monedas[1]= Moneda(350, 400);
    monedas[2]= Moneda(450, 400);
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
