#ifndef PANTALLAPASARNIVEL_H_INCLUDED
#define PANTALLAPASARNIVEL_H_INCLUDED
#include <SFML/Graphics.hpp>

class PantallaPasarNivel{
    private:
        sf::Text texto;
        sf::Font fuente;
        sf::RenderWindow& ventana;
        sf::Texture fondoTexture;
        sf::Sprite fondoSprite;
        bool jugarProximoNivel=false;
    public:
        PantallaPasarNivel(sf::RenderWindow& vent);
        void dibujar();
        void manejarEntrada();

        bool isJugarProximoNivel(){
            return jugarProximoNivel;
        }
        void reset(){
            jugarProximoNivel=false;
        }

};

#endif
