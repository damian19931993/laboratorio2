#ifndef PANTALLAFINAL_H_INCLUDED
#define PANTALLAFINAL_H_INCLUDED
#include <SFML/Graphics.hpp>

class PantallaFinal{
    private:
        sf::Text texto;
        sf::Font fuente;
        sf::RenderWindow& ventana;
        sf::Texture fondoTexture;
        sf::Sprite fondoSprite;
        bool irAMenu=false;
    public:
        PantallaFinal(sf::RenderWindow& vent);
        void dibujar();
        void manejarEntrada();

        bool esIrMenu(){
            return irAMenu;
        }
        void reset(){
            irAMenu=false;
        }

};

#endif
