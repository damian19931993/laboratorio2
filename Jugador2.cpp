#include "Jugador2.h"
#include <cstring>

Jugador2::Jugador2() : puntos(0) {
    nombre[0] = '\0';
}

Jugador2::Jugador2(const char* n, int p) : puntos(p) {
    strncpy(nombre, n, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}

void Jugador2::setNombre(const char* n) {
    strncpy(nombre, n, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}

const char* Jugador2::getNombre() const {
    return nombre;
}

void Jugador2::setPuntos(int p) {
    puntos = p;
}

int Jugador2::getPuntos() const {
    return puntos;
}
