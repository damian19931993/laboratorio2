#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "Jugador2.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>

class Archivo {
private:
    char nombre[30];
public:
    Archivo(); // Constructor predeterminado
    Archivo(const char *n); // Constructor con nombre de archivo

    int contarRegistros();
    int nivelJugador();
    bool grabarArchivo(Jugador2 obj);
    void mostrarTodosJugadores(const char* filename = "records.dat");
    int leerPuntajeJugador();
    Jugador2 leerRegistro(int pos);
};

#endif // ARCHIVO_H_INCLUDED
