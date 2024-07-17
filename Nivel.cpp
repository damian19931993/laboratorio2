#include "Nivel.h"
#include "Obstaculo.h"
#include "Moneda.h"
#include <iostream>

#include <string.h>
#include <sstream> // Incluye la biblioteca para usar std::ostringstream
using namespace std;

Nivel::Nivel(sf::RenderWindow& vent,Jugador& jug, int numObst, int numMon, int numFue) : ventana(vent), jugador(jug),  piso(800, 150), numObstaculos(numObst), puerta(730,350,40,100), numMonedas(numMon), numFuegos(numFue)  {
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
    fuegos = new Fuego[numFuegos];

    rectangulo.setSize(sf::Vector2f(100, 10));
    rectangulo.setFillColor(sf::Color::Yellow);
    rectangulo.setPosition(250,140);

}

Nivel::~Nivel() {
    delete[] obstaculos; // Liberar la memoria del array de obstáculos
    delete[] monedas;
    delete[] fuegos;
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


    if(jugador.getNivel()==1){
      jugador.activarTrampa(400,575);  //(X MAYOR A..., LA TRAMPA SE DINUJA ACA)
      jugador.dibujarTrampa(ventana);
      jugador.actualizarTrampa();
      jugador.caer(580,400); //(POS X DONDE EMPIEZA A CAER)
    }

    if(jugador.getNivel()==2){
        jugador.activarTrampa(200,350);
        jugador.dibujarTrampa(ventana);
        jugador.actualizarTrampa();
        jugador.caer(355,400);
    }


        for(int i=0; i<numFuegos; i++){
            fuegos[i].dibujar(ventana);
            fuegos[i].mover();
        }



    jugador.dibujar(ventana);

    if(jugador.getNivel()==2){
        ventana.draw(rectangulo);
    }




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

    for(int i=0; i<numFuegos; i++){
            int a=0;
        if(jugador.seChocaConFuego(fuegos[i])){
            fuegos[0]=Fuego(600 + a,375);
            a=a+400;
        }
    }
}

void Nivel::setMonedas(const int posicionesX[], const int posicionesY[], int numMonedas) {
    for (int i = 0; i < numMonedas; ++i) {
        monedas[i] = Moneda(posicionesX[i], posicionesY[i]); // Reiniciar las posiciones de las monedas
    }
}




