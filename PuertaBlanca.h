#ifndef PUERTABLANCA_H_INCLUDED
#define PUERTABLANCA_H_INCLUDED

#include <SFML/Graphics.hpp>

class PuertaBlanca{
    private:
        sf::RectangleShape puerta;

    public:
        PuertaBlanca();
        PuertaBlanca(float x, float y, float ancho, float alto);
        void dibujar(sf::RenderWindow& ventana);
        sf::FloatRect getBounds() const;
        sf::Vector2f getPosition() const;
};

#endif
