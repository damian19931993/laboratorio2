#ifndef NIVEL_H_INCLUDED
#define NIVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Piso.h"
#include "Obstaculo.h"
#include "PuertaBlanca.h"
#include "Moneda.h"
#include "Fuego.h"

class Nivel {
protected:
    sf::RenderWindow& ventana;
    sf::RectangleShape rectangulo;
    Jugador& jugador;
    sf::Text textoVidas;
    sf::Text textoPuntos;
    sf::Text textoGameOver;
    sf::Font fuente;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    Piso piso;
    Obstaculo* obstaculos;
    PuertaBlanca puerta;
    Moneda* monedas;
    Fuego* fuegos;
    int numObstaculos;
    int numMonedas;
    int numFuegos;
    bool gameOver;
    bool gameOverResolved;

public:
    Nivel(sf::RenderWindow& vent,Jugador& jug, int numObst, int numMonedas, int numFuegos);
    ~Nivel();

    Jugador& getJugador(){
        return jugador;
    }
    void manejarEntrada();
    void actualizar();
    void dibujar();
    void eventos();
    void setMonedas(const int posicionesX[], const int posicionesY[], int numMonedas);

    void dibujarRectangulo();
};

#endif
