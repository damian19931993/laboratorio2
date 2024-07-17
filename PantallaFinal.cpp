#include "PantallaFinal.h"
#include<iostream>
#include <string.h>
using namespace std;

PantallaFinal::PantallaFinal(sf::RenderWindow& vent): ventana(vent){

     if (!fondoTexture.loadFromFile("fondo2.jpg")) {
            std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        }
        fondoSprite.setTexture(fondoTexture);
        fuente.loadFromFile("fuentes/Roboto-Black.ttf");
        texto.setFont(fuente);
        texto.setCharacterSize(25);
        texto.setPosition(10,25);
        texto.setString("Presione enter para ir al menu principal");

}


    void PantallaFinal::dibujar() {
    ventana.clear();

    ventana.draw(fondoSprite);
    ventana.draw(texto);
    ventana.display();
}

void PantallaFinal::manejarEntrada(){
 sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::TextEntered) {
             if (evento.text.unicode == '\r') {
                irAMenu=true;
            }
        }
    }
}




