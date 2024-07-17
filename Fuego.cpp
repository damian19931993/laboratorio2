#include "Fuego.h"
#include<iostream>
#include <string.h>
using namespace std;

Fuego::Fuego(){
}

Fuego::Fuego(float xx, float yy) : x(xx), y(yy){
    forma.setRadius(5);
    forma.setFillColor(sf::Color::Cyan);
    forma.setPosition(x,y);
}

void Fuego::dibujar(sf::RenderWindow& ventana) {

        ventana.draw(forma);

}

void Fuego::desaparecer() {
    visible = false;
    forma.setPosition(-100, -100); // Mover la moneda fuera de la ventana visible
}

sf::FloatRect Fuego::getBounds() const {
    return forma.getGlobalBounds();
}

bool Fuego::isVisible() const {
    return visible;
}

void Fuego::mover(){
    forma.move(-0.050f,0);
}

void Fuego::setFuegos(float posX,float posY){
    x=posX;
    y=posY;
    forma.setPosition(x,y);
}
