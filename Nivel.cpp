#include "Nivel.h"
#include "Obstaculo.h"
#include "Moneda.h"
#include <iostream>

#include <string.h>
#include <sstream> // Incluye la biblioteca para usar std::ostringstream
using namespace std;

Nivel::Nivel(sf::RenderWindow& vent, int numObst, int numMon) : ventana(vent), jugador(0, 400),  piso(800, 150), numObstaculos(numObst), puerta(730,350,40,100), numMonedas(numMon)  {
    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }

    if (!fondoTexture.loadFromFile("fondo2.jpg")) {
        std::cerr << "Error al cargar la imagen de fondo" << std::endl;
    }


    fondoSprite.setTexture(fondoTexture);
    textoVidas.setFont(fuente);
    textoVidas.setCharacterSize(24);
    textoVidas.setFillColor(sf::Color::White);
    textoVidas.setPosition(10, 10);


    textoPuntos.setFont(fuente);
    textoPuntos.setCharacterSize(24);
    textoPuntos.setFillColor(sf::Color::White);
    textoPuntos.setPosition(10, 30);


    textoGameOver.setFont(fuente);
    textoGameOver.setString("GAME OVER\nPresione Enter para ir al menu principal");
    textoGameOver.setCharacterSize(50);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setPosition(100, 200);

    obstaculos = new Obstaculo[numObstaculos];
    monedas = new Moneda[numMonedas];
}

Nivel::~Nivel() {
    delete[] obstaculos; // Liberar la memoria del array de obstáculos
    delete[] monedas;
}

void Nivel::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (gameOver && evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
            gameOverResolved = true;
        }
    }
}

void Nivel::dibujar() {

    ventana.clear();
    ventana.draw(fondoSprite);
    ventana.draw(textoPuntos);
    ventana.draw(textoVidas);

    puerta.dibujar(ventana);
    jugador.cmd();
    piso.dibujar(ventana);
    for (int i = 0; i < numObstaculos; ++i) {
        obstaculos[i].dibujar(ventana); // Dibujar cada obstáculo
    }
    for(int i=0; i<numMonedas;i++){

        monedas[i].dibujar(ventana);
    }



    jugador.activarTrampa();
    jugador.dibujarTrampa(ventana);
    jugador.actualizarTrampa();
    jugador.caer();
    jugador.dibujar(ventana);



    std::ostringstream ss;                  //REHAAACERR
    ss << "VIDAS: " << jugador.getVidas();
    textoVidas.setString(ss.str());

       std::ostringstream s;
    s << "PUNTOS: " << jugador.getPuntos();
    textoPuntos.setString(s.str());




    ventana.display();
}

void Nivel::eventos() {
    for (int i = 0; i < numObstaculos; ++i) {
        if (jugador.seChocan(obstaculos[i], puerta)) {
        }
    }

    for(int i=0; i< numMonedas; i++){
        if(jugador.seChocaConMoneda(monedas[i])){

        }
    }
}

