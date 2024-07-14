#include "Piso.h"
#include "Jugador.h"

#include<iostream>
#include <string.h>
using namespace std;

Piso::Piso(float ancho, float altura) : trampaActiva(false), animacionTrampa(false), alturaActualTrampa(0) {
    forma.setSize(sf::Vector2f(ancho, altura)); // Establecer el tama�o del piso
    forma.setFillColor(sf::Color::Blue); // Establecer el color del piso
    // Establecer la posici�n del piso como fijo en la parte inferior de la ventana
    forma.setPosition(0.0f, 600.0f - altura);

    // Inicializar la trampa con tama�o 0
    trampa.setSize(sf::Vector2f(50, 0));
    trampa.setFillColor(sf::Color::White); // Establecer el color de la trampa
    trampa.setPosition(575, 450); // Posici�n inicial de la trampa
}

void Piso::setColor(const sf::Color& color) {
    forma.setFillColor(color);
}

void Piso::setPosition(float x, float y) {
    forma.setPosition(x, y);
}

sf::RectangleShape& Piso::getForma() {
    return forma;
}

void Piso::setSize(float ancho, float altura) {
    forma.setSize(sf::Vector2f(ancho, altura));
}

void Piso::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(forma); // Dibujar el rect�ngulo en la ventana

}


