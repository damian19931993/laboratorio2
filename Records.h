#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Archivo.h"

class Records {
private:
    sf::RenderWindow& ventana;
    sf::Text texto;
    sf::Font fuente;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    bool irAMenu;

public:
    Records(sf::RenderWindow& vent);
    void dibujar(Archivo& archi);
    void manejarEntrada();
    bool isIrAMenu() const { return irAMenu; }
};

#endif
