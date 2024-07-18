#include <SFML/Graphics.hpp>
#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "Nivel.h"
#include "Jugador.h"
#include "PantallaGameOver.h"
#include "PantallaPasarNivel.h"
#include "PantallaFinal.h"
#include "Archivo.h"
#include "Records.h"
#include "Jugador2.h"
#include<iostream>
#include <string.h>
using namespace std;

int main() {
    // Crear la ventana de renderizado
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Juego con SFML");

    // Crear el objeto MenuPrincipal
    MenuPrincipal menu(ventana);
    Jugador jugador(0, 400);
    Jugador2 j2;

    DarNombreJugador darNombreJugador(ventana);
    Nivel1 nivel1(ventana,jugador);
    Nivel2 nivel2(ventana,jugador);
    Nivel3 nivel3(ventana,jugador);
    Nivel4 nivel4(ventana,jugador);
    PantallaGameOver pantallaGameOver(ventana);
    PantallaPasarNivel pantallaPasarNivel(ventana);
    PantallaFinal pantallaFinal(ventana);
    Archivo archivo;
    Records records(ventana);

    bool enMenuPrincipal=true;
    bool enDarNombreJugador=false;
    bool enRecords=false;
    bool habilitarNivel1=false;
    bool habilitarNivel2=false;
    bool habilitarNivel3=false;
    bool habilitarNivel4=false;
    bool habilitarPantallaFinal=false;
    bool gameOver=false;
    bool habilitarSiguienteNivel=false;
    bool jugarProximoNivel=false;
    bool hayJuego=true;
    bool habilitarArchivo=false;
    bool a=false;



    while (ventana.isOpen()) {
            cout<<archivo.contarRegistros();

        if(enMenuPrincipal){
            menu.manejarEntrada();
            menu.dibujar();
        }

        if(menu.esBotonRecordsPresionado()){
            enMenuPrincipal=false;
            enRecords=true;
        }
        if(enRecords){
            records.dibujar(archivo);
            records.manejarEntrada();
        }

        if(menu.esBotonJugarPresionado()){
            enMenuPrincipal=false;
            enDarNombreJugador=true;
            menu.resetBotones();
        }

        if(enDarNombreJugador){
            darNombreJugador.manejarEntrada();
            darNombreJugador.dibujar();
            jugador.setNombre(darNombreJugador.getNombreJugador());


            if(darNombreJugador.esNombreIngresado()){
                habilitarNivel1=true;
                enDarNombreJugador=false;
                darNombreJugador.resetNombreIngresado();
                jugador.setVidas(1);
                jugador.setPuntos(0);

            }
        }

        if(habilitarNivel1 && !gameOver){
            jugador.setNivel(1);
            nivel1.manejarEntrada();
            nivel1.dibujar();
            nivel1.eventos();
        }



        if(jugador.isSiguienteNivel() && hayJuego){
            jugador.setTrampaActiva(false);
            jugador.setAnimacionTrampa(false);
            habilitarNivel1=false;
            if(jugador.getNivel()!=4){
                pantallaPasarNivel.dibujar();
                pantallaPasarNivel.manejarEntrada();
             if(pantallaPasarNivel.isJugarProximoNivel() && jugador.getNivel()==1){
                jugador.setearJugador(250,100);
                habilitarNivel2=true;
                pantallaPasarNivel.reset();
                jugador.setSiguienteNivel(false);
            }
            if(pantallaPasarNivel.isJugarProximoNivel() && jugador.getNivel()==2){
                jugador.setearJugador(0,400);
                habilitarNivel3=true;
                pantallaPasarNivel.reset();
                jugador.setSiguienteNivel(false);
            }
            if(pantallaPasarNivel.isJugarProximoNivel() && jugador.getNivel()==3){
                jugador.setearJugador(0,400);
                habilitarNivel4=true;
                pantallaPasarNivel.reset();
                jugador.setSiguienteNivel(false);
            }
            }


            if(jugador.getNivel()==4){
                jugador.setearJugador(0,400);
                habilitarPantallaFinal=true;
                pantallaPasarNivel.reset();
                jugador.setSiguienteNivel(false);
                jugador.setNivel(1);
            }
        }

        if(habilitarNivel2 & !gameOver){
            jugador.setNivel(2);
            nivel2.manejarEntrada();
            nivel2.dibujar();
            nivel2.eventos();
            if(jugador.isSiguienteNivel()){
                habilitarNivel2=false;
            }
        }

        if(habilitarNivel3 & !gameOver){
            jugador.setNivel(3);
            nivel3.manejarEntrada();
            nivel3.dibujar();
            nivel3.eventos();
            if(jugador.isSiguienteNivel()){
                habilitarNivel3=false;
            }
        }

        if(habilitarNivel4 & !gameOver){
            jugador.setNivel(4);
            nivel4.manejarEntrada();
            nivel4.dibujar();
            nivel4.eventos();
            if(jugador.isSiguienteNivel()){
                habilitarNivel4=false;
            }
        }

        if(habilitarPantallaFinal){
            habilitarArchivo=true;
            j2.setNombre(jugador.getNombre());
            j2.setPuntos(jugador.getPuntos());
            cout<<j2.getNombre();
            cout<<j2.getPuntos();
            if(habilitarArchivo && !a){
                archivo.grabarArchivo(j2);
                a=true;
            }

            pantallaFinal.dibujar();
            pantallaFinal.manejarEntrada();
            if(pantallaFinal.esIrMenu()){
                enMenuPrincipal=true;
                pantallaFinal.reset();
                habilitarPantallaFinal=false;
            }
        }


        if(jugador.getVidas()==0){
            gameOver=true;
            habilitarArchivo=true;
        }




        if (gameOver){
            j2.setNombre(jugador.getNombre());
            j2.setPuntos(jugador.getPuntos());
            cout<<j2.getNombre();
            cout<<j2.getPuntos();
            if(habilitarArchivo && !a){
                archivo.grabarArchivo(j2);
                a=true;
            }

            habilitarNivel1 = false;
            habilitarNivel2 = false;
            habilitarNivel3 = false;
            habilitarNivel4 = false;
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
                habilitarArchivo=false;
                a=false;
                pantallaGameOver.resetIrAmenu();
                int posicionesX1[] = { 200, 350, 450 };
                int posicionesY1[] = { 400, 400, 400 };
                int posicionesX2[] = { 200, 350};
                int posicionesY2[] = { 400, 400};

                nivel1.setMonedas(posicionesX1, posicionesY1, 3);
                nivel2.setMonedas(posicionesX2, posicionesY2, 2);//estudia el metodo
            }
        }


    }

    return 0;
}
