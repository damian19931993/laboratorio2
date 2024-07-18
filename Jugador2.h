#ifndef JUGADOR2_H_INCLUDED
#define JUGADOR2_H_INCLUDED

#include <string>
#include <cstring>

class Jugador2 {
private:
    char nombre[30];
    int puntos;

public:
    Jugador2();
    Jugador2(const char* n, int p);

    void setNombre(const char* n);
    const char* getNombre() const;

    void setPuntos(int p);
    int getPuntos() const;
};

#endif
