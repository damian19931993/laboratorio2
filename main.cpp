#include <SFML/Graphics.hpp>
#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel.h"
#include "Jugador.h"
#include "PantallaGameOver.h"
#include "PantallaPasarNivel.h"
#include<iostream>
#include <string.h>
using namespace std;

int main() {
    // Crear la ventana de renderizado
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Juego con SFML");

    // Crear el objeto MenuPrincipal
    MenuPrincipal menu(ventana);
    Jugador jugador(0, 400);
    DarNombreJugador darNombreJugador(ventana);
    Nivel1 nivel1(ventana,jugador);
    Nivel2 nivel2(ventana,jugador);
    PantallaGameOver pantallaGameOver(ventana);
    PantallaPasarNivel pantallaPasarNivel(ventana);

    bool enMenuPrincipal=true;
    bool enDarNombreJugador=false;
    bool habilitarNivel1=false;
    bool habilitarNivel2=false;
    bool gameOver=false;
    bool habilitarSiguienteNivel=false;
    bool jugarProximoNivel=false;



    while (ventana.isOpen()) {
            cout<<jugador.getVidas();

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
                jugador.setVidas(2);

            }
        }

        if(habilitarNivel1 && !gameOver){

            nivel1.manejarEntrada();
            nivel1.dibujar();
            nivel1.eventos();
        }



        if(jugador.isSiguienteNivel()){
            habilitarSiguienteNivel=true;
            jugador.setTrampaActiva(false);
            jugador.setAnimacionTrampa(false);
        }

        if(habilitarSiguienteNivel){
            habilitarNivel1=false;
            pantallaPasarNivel.dibujar();
            pantallaPasarNivel.manejarEntrada();
            if(pantallaPasarNivel.isJugarProximoNivel()){
                habilitarNivel2=true;
                pantallaPasarNivel.reset();
                habilitarSiguienteNivel=false;
                jugador.setSiguienteNivel(false);
            }
        }


        if(habilitarNivel2 & !gameOver){

            nivel2.manejarEntrada();
            nivel2.dibujar();
            nivel2.eventos();
            nivel2.dibujarRectangulo();
        }



        if(jugador.getVidas()==0){
            gameOver=true;
        }


        if (gameOver){
            habilitarNivel1 = false;
            pantallaGameOver.setPuntos(jugador.getPuntos());
            pantallaGameOver.dibujar();
            pantallaGameOver.manejarEntrada();
            if (pantallaGameOver.isIrAmenu()) {
                enMenuPrincipal = true;
                enDarNombreJugador = false;
                habilitarSiguienteNivel = false;
                jugarProximoNivel = false;
                jugador.setVidas(-1);
                jugador.setPuntos(0);
                gameOver=false;
                pantallaGameOver.resetIrAmenu();
                int posicionesX[] = { 200, 350, 450 };
                int posicionesY[] = { 400, 400, 400 };

                nivel1.setMonedas(posicionesX, posicionesY, 3);//estudia el metodo
            }
        }


    }

    return 0;
}
