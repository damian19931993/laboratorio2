#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include <SFML/Graphics.hpp>

class Obstaculo{
    private:
    sf::RectangleShape forma;

    public:
    Obstaculo();
    Obstaculo(float pisoAltura, float x, float y);
    void setColor(const sf::Color& color);
    void setPosition(float x, float y);
    sf::FloatRect getBounds() const;
    void setSize(float ancho, float altura);
    void dibujar(sf::RenderWindow& ventana);
    sf::Vector2f getPosition() const;
};
#endif
