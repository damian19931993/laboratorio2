#include "DarNombreJugador.h"
#include<iostream>
using namespace std;

DarNombreJugador::DarNombreJugador(sf::RenderWindow& vent)
    : ventana(vent), nombreIngresado(false) {
    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }
    textoInstruccion.setFont(fuente);
    textoInstruccion.setString("Ingrese su nombre y presione enter");
    textoInstruccion.setCharacterSize(30);
    textoInstruccion.setFillColor(sf::Color::White);
    textoInstruccion.setPosition(100,100);
    textoNombre.setFont(fuente);
    textoNombre.setString("");
    textoNombre.setCharacterSize(30);
    textoNombre.setFillColor(sf::Color::White);
    textoNombre.setPosition(100,200);
}

void DarNombreJugador::manejarEntrada(){
 sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::TextEntered) {
            if (evento.text.unicode == '\b') { // Backspace
                if (!nombreJugador.empty()) {
                    nombreJugador.pop_back();
                }
            } else if (evento.text.unicode == '\r') { // Enter
                if (!nombreJugador.empty()) {
                    nombreIngresado = true;
                }
            } else {
                nombreJugador += static_cast<char>(evento.text.unicode);
            }
            textoNombre.setString(nombreJugador);
        }
    }
}

void DarNombreJugador::dibujar(){
    ventana.clear();
    ventana.draw(textoInstruccion);
    ventana.draw(textoNombre);
    ventana.display();
}

bool DarNombreJugador::esNombreIngresado(){
    return nombreIngresado;
}

void DarNombreJugador::resetNombreIngresado(){
    nombreIngresado=false;
    nombreJugador.clear();
    textoNombre.setString("");
}



