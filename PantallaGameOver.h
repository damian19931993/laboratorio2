#ifndef PANTALLAGAMEOVER_H_INCLUDED
#define PANTALLAGAMEOVER_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>


class PantallaGameOver{
    private:
        sf::Font fuente;
        sf::Text texto;
        sf::Text textoPuntos;
        int puntos;
        sf::RenderWindow& ventana;
        sf::Texture fondoTexture;
        sf::Sprite fondoSprite;

    public:
        PantallaGameOver(sf::RenderWindow& vent);
        void setPuntos(int p){
            puntos = p;
            textoPuntos.setString("Puntos: " + std::to_string(puntos));
        }
        void dibujar();

};
#endif
