#ifndef NIVEL2_H_INCLUDED
#define NIVEL2_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Jugador.h"

class Nivel2 : public Nivel{
    private:
        sf::RectangleShape rectangulo;
    public:
        Nivel2(sf::RenderWindow& vent,Jugador& jug);
        void manejarEntrada();
        void actualizar();
        void dibujar();
        void eventos();
        void dibujarRectangulo();
};
#endif
