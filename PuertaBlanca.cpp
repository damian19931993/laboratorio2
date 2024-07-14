#include "PuertaBlanca.h"
#include<iostream>
#include <string.h>
using namespace std;

PuertaBlanca::PuertaBlanca(){
}

PuertaBlanca::PuertaBlanca(float x, float y, float ancho, float alto){
    puerta.setSize(sf::Vector2f(ancho,alto));
    puerta.setFillColor(sf::Color::White);
    puerta.setPosition(x,y);
}

void PuertaBlanca::dibujar(sf::RenderWindow& ventana){
    ventana.draw(puerta);
}

sf::FloatRect PuertaBlanca::getBounds() const {
    return puerta.getGlobalBounds(); // Retornar los límites globales del rectángulo
}

sf::Vector2f PuertaBlanca::getPosition() const {
    return puerta.getPosition(); // Devolver la posición del rectángulo
}

