#ifndef FUEGO_H_INCLUDED
#define FUEGO_H_INCLUDED

#include <SFML/Graphics.hpp>

class Fuego{
    private:
        sf::CircleShape forma;
        float x;
        float y;
        bool visible;

    public:
        Fuego();
        Fuego(float xx,float yy);

        void dibujar(sf::RenderWindow& ventana);
        void desaparecer();
        void mover();
        sf::FloatRect getBounds() const;
        bool isVisible() const;
        void setFuegos(float posX,float posY);

};
#endif
