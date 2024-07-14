#ifndef NIVEL_H_INCLUDED
#define NIVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Piso.h"
#include "Obstaculo.h"
#include "PuertaBlanca.h"
#include "Moneda.h"

class Nivel {
protected:
    sf::RenderWindow& ventana;
    Jugador jugador;
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
    int numObstaculos;
    int numMonedas;
    bool gameOver;
    bool gameOverResolved;

public:
    Nivel(sf::RenderWindow& vent, int numObst, int numMonedas);
    ~Nivel();

    Jugador getJugador(){
        return jugador;
    }
    void manejarEntrada();
    void actualizar();
    void dibujar();
    void eventos();
};

#endif // NIVEL1_H_INCLUDED
