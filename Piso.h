#ifndef PISO_H_INCLUDED
#define PISO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Jugador.h"


class Jugador;

class Piso {
private:
    sf::RectangleShape forma;
    sf::RectangleShape trampa;
    bool trampaActiva;
    bool animacionTrampa;
    float alturaActualTrampa;
    const float alturaMaxTrampa=200;
    const float velocidadAperturaTrampa = 0.03;


public:
    Piso(float ancho, float altura);
    void setColor(const sf::Color& color);
    void setPosition(float x, float y);
    sf::RectangleShape& getForma();
    void setSize(float ancho, float altura);
    void dibujar(sf::RenderWindow& ventana);
    void activarTrampa(const Jugador& jugador);
    void actualizar(const Jugador& jugador); // Método para actualizar la animación de la trampa
    bool isTrampaActiva();
    void reiniciarTrampa();
};

#endif // PISO_H_INCLUDED
