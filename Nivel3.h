#ifndef NIVEL3_H_INCLUDED
#define NIVEL3_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Jugador.h"

class Nivel3 : public Nivel{
    public:
        Nivel3(sf::RenderWindow& vent,Jugador& jug);
        void manejarEntrada();
        void actualizar();
        void dibujar();
        void eventos();
};
#endif
