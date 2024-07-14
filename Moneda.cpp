#include "Moneda.h"
#include<iostream>
#include <string.h>
using namespace std;

Moneda::Moneda(){
}

Moneda::Moneda(float xx, float yy) : x(xx), y(yy){
    forma.setRadius(5);
    forma.setFillColor(sf::Color::Yellow);
    forma.setPosition(x,y);
}

void Moneda::dibujar(sf::RenderWindow& ventana) {

        ventana.draw(forma);

}

void Moneda::desaparecer() {
    visible = false;
    forma.setPosition(-100, -100); // Mover la moneda fuera de la ventana visible
}

sf::FloatRect Moneda::getBounds() const {
    return forma.getGlobalBounds();
}

bool Moneda::isVisible() const {
    return visible;
}
