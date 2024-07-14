#include <SFML/Graphics.hpp>
#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Nivel1.h"
#include "Jugador.h"
#include "PantallaGameOver.h"
#include<iostream>
#include <string.h>
using namespace std;

int main() {
    // Crear la ventana de renderizado
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Juego con SFML");

    // Crear el objeto MenuPrincipal
    MenuPrincipal menu(ventana);
    DarNombreJugador darNombreJugador(ventana);
    Nivel1 nivel1(ventana);
    Jugador jugador(0,400);
    PantallaGameOver pantallaGameOver(ventana);

    bool enMenuPrincipal=true;
    bool enDarNombreJugador=false;
    bool habilitarNivel1=false;
    bool gameOver=false;

    while (ventana.isOpen()) {

        if(enMenuPrincipal){
            menu.manejarEntrada();
            menu.dibujar();
        }

        if(menu.esBotonJugarPresionado()){
            enMenuPrincipal=false;
            enDarNombreJugador=true;
            menu.resetBotones();
        }

        if(enDarNombreJugador){
            darNombreJugador.manejarEntrada();
            darNombreJugador.dibujar();

            if(darNombreJugador.esNombreIngresado()){
                habilitarNivel1=true;
                enDarNombreJugador=false;
                darNombreJugador.resetNombreIngresado();
            }
        }

        if(habilitarNivel1 && !gameOver){
            nivel1.manejarEntrada();
            nivel1.dibujar();
            nivel1.eventos();
        }

        if(nivel1.getJugador().isGameOver()){
           gameOver=true;
        }

        if(gameOver){
            pantallaGameOver.setPuntos(nivel1.getJugador().getPuntos());
            pantallaGameOver.dibujar();
        }





    }

    return 0;
}
