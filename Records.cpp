#include "Records.h"
#include<iostream>
#include <string.h>
using namespace std;

Records::Records(sf::RenderWindow& vent) : ventana(vent), irAMenu(false) {
    if (!fondoTexture.loadFromFile("fondo2.jpg")) {
        std::cerr << "Error al cargar la imagen de fondo" << std::endl;
    }
    fondoSprite.setTexture(fondoTexture);
    fuente.loadFromFile("fuentes/Roboto-Black.ttf");
    texto.setFont(fuente);
    texto.setCharacterSize(25);
    texto.setPosition(10, 25);
    texto.setString("RECORDS: ");
}

void Records::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::TextEntered) {
            if (evento.text.unicode == '\r') {
                irAMenu = true;
            }
        }
    }
}

void Records::dibujar(Archivo& archi) {
    ventana.clear();
    ventana.draw(fondoSprite);
    ventana.draw(texto);

    int tam = archi.contarRegistros();
    if (tam <= 0) {
        sf::Text noRecords("No hay registros para mostrar.", fuente, 20);
        noRecords.setPosition(10, 60);
        ventana.draw(noRecords);
    } else {
        float yPosition = 60;
        for (int i = 0; i < tam; ++i) {
            Jugador2 jugador = archi.leerRegistro(i);
            sf::Text nombreText(jugador.getNombre(), fuente, 20);
            nombreText.setPosition(10, yPosition);
            ventana.draw(nombreText);

            sf::Text puntosText(to_string(jugador.getPuntos()), fuente, 20);
            puntosText.setPosition(300, yPosition);
            ventana.draw(puntosText);

            yPosition += 30; // Ajusta esto según el espacio que quieras entre los registros
        }
    }

    ventana.display();
}
