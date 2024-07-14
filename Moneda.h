#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

#include <SFML/Graphics.hpp>

class Moneda{
    private:
        sf::CircleShape forma;
        float x;
        float y;
        bool visible;

    public:
        Moneda();
        Moneda(float xx,float yy);

        void dibujar(sf::RenderWindow& ventana);
        void desaparecer();
        sf::FloatRect getBounds() const;
        bool isVisible() const;

};
#endif
