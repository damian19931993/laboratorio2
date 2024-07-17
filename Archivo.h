#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Jugador.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>


class Archivo{


    public:
        Archivo();
        bool cargarJugador(Jugador jugador);
        Jugador leerRegistro(int pos);

};

#endif
