#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>


class MenuPrincipal {
private:
    sf::Font fuente;
    sf::Text textoBienvenida;
    sf::Text botonJugar;
    sf::Text botonRecords;
    sf::RenderWindow& ventana;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    sf::Text textoPartidas;
    bool botonJugarPresionado;
    bool botonRecordsPresionado;
    bool botonContinuarPartidaPresionado;

public:
    MenuPrincipal(sf::RenderWindow& vent);
    void manejarEntrada();
    void dibujar();
    bool esBotonJugarPresionado() ;
    bool esBotonRecordsPresionado() const;
    bool esBotonContinuarPartidaPresionado() const;
    void resetBotones();
};

#endif // MENUPRINCIPAL_H_INCLUDED
