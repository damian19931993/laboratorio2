#ifndef NIVEL4_H_INCLUDED
#define NIVEL4_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Jugador.h"

class Nivel4 : public Nivel{
    public:
        Nivel4(sf::RenderWindow& vent,Jugador& jug);
        void manejarEntrada();
        void actualizar();
        void dibujar();
        void eventos();
};
#endif
