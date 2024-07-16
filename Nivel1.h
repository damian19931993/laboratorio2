#ifndef NIVEL1_H_INCLUDED
#define NIVEL1_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Nivel.h"
#include "Jugador.h"

class Nivel1 : public Nivel{
    public:
        Nivel1(sf::RenderWindow& vent,Jugador& jug);
        void manejarEntrada();
        void actualizar();
        void dibujar();
        void eventos();
};
#endif
