#include "PantallaGameOver.h"
#include<iostream>
#include <string.h>
using namespace std;


PantallaGameOver::PantallaGameOver(sf::RenderWindow& vent) : ventana(vent) {
    if (!fondoTexture.loadFromFile("fondo2.jpg")) {
            std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        }
        fondoSprite.setTexture(fondoTexture);

        fuente.loadFromFile("fuentes/Roboto-Black.ttf");
        texto.setFont(fuente);
        texto.setString("GAME OVER. PRESIONE ENTER PARA IR AL MENU PRINCIPAL");
        texto.setCharacterSize(50);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(300,10);

        textoPuntos.setFont(fuente);
        textoPuntos.setCharacterSize(50);
        textoPuntos.setFillColor(sf::Color::White);
        textoPuntos.setPosition(300,50);

}

void PantallaGameOver::dibujar() {
    ventana.clear();
    ventana.draw(fondoSprite);
    ventana.draw(texto);
    ventana.draw(textoPuntos);
    ventana.display();
}
