#include "Jugador.h"
#include "Obstaculo.h"
#include "PuertaBlanca.h"
#include<iostream>
#include <string.h>
using namespace std;
Jugador::Jugador(float xx, float yy) : x(xx), y(yy), gameOver(false), trampaActiva(false), animacionTrampa(false), alturaActualTrampa(0), puntos(0) {
    vidas=10;
    forma.setRadius(20); // Establecer el radio del círculo
    forma.setFillColor(sf::Color::Green); // Establecer el color de relleno
    forma.setPosition(x, y); // Establecer la posición inicial
    velocidadMovimiento = 0.025f; // Establecer la velocidad de movimiento
    velocidadSalto = 0; // Inicializar la velocidad de salto
    velocidadSaltoHorizontal = 1.0f; // Establecer la velocidad horizontal durante el salto
    cayendo = false; // Inicializar cayendo a false

    quieto = true; // Inicializar quieto a true
    caminandoAdelante = false; // Inicializar caminandoAdelante a false
    caminandoAtras = false; // Inicializar caminandoAtras a false
    saltando = false; // Inicializar saltando a false
    saltandoAdelante = false; // Inicializar saltandoAdelante a false
    saltandoAtras = false; // Inicializar saltandoAtras a false

    // Inicializar la trampa con tamaño 0
    trampa.setSize(sf::Vector2f(50, 0));
    trampa.setFillColor(sf::Color::White); // Establecer el color de la trampa
     // Posición inicial de la trampa

}



void Jugador::dibujarTrampa(sf::RenderWindow& ventana){

    if(trampaActiva){
        ventana.draw(trampa);
    }
}

void Jugador::dibujar(sf::RenderWindow& ventana) {
    forma.setPosition(x, y); // Asegurarse de que la posición esté actualizada
    ventana.draw(forma);
}

void Jugador::cmd() {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !cayendo) {
            forma.move(velocidadMovimiento, 0);
            caminandoAdelante = true;
            quieto = true;
        }
        else{
            caminandoAdelante=false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            forma.move(-velocidadMovimiento, 0);
            caminandoAtras = true;
            quieto = true;
        }
        else{
            caminandoAtras=false;
        }

         if(!saltando && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                saltando=true;
                velocidadSalto = 5; // Establecer la velocidad de salto inicial
            }



if (saltando) {
    saltandoAdelante = true;
    forma.move(0, -velocidadSalto * 0.1f); // Mover con una velocidad ajustada para suavidad
    if (forma.getPosition().y > 400) {
        saltando = false;
        forma.setPosition(forma.getPosition().x, 400);
        quieto = true;
    }
}

if (saltandoAdelante) {
    velocidadSalto -= 0.01f; // Aplicar una gravedad más baja para un salto más lento
    forma.move((velocidadMovimiento * 0.001f) + 0.05f, -velocidadSalto * 0.1f); // Mover con una velocidad ajustada para suavidad
    if (forma.getPosition().y > 400) {
        saltandoAdelante = false;
        forma.setPosition(forma.getPosition().x, 400);
        quieto = true;
        saltando=false;
    }
}

if (cayendo) {
        velocidadCaida += 0.00001f; // Aumentar la velocidad de caída
        forma.move(0, velocidadCaida);
        if (forma.getPosition().y > 600) { // Caer hasta el fondo de la pantalla
            trampaActiva=false;
            animacionTrampa=false;
            cayendo = false;
            vidas--;
            setearJugador(0,400);
            velocidadCaida=0.01;

        }
    }




    // Actualiza la posición x e y del jugador para que coincida con la forma
    sf::Vector2f pos = forma.getPosition();
    x = pos.x;
    y = pos.y;
}

bool Jugador::seChocan(Obstaculo obstaculo, PuertaBlanca puerta) { //REHHACER
    bool colision = forma.getGlobalBounds().intersects(obstaculo.getBounds());
    bool colision2 =forma.getGlobalBounds().intersects(puerta.getBounds());
    if (colision) {
        trampaActiva=false;
        animacionTrampa=false;
        vidas--;
        setearJugador(0,400);
    }
    if(colision2){
         siguienteNivel=true;
    }
    return colision;
}

bool Jugador::seChocaConMoneda(Moneda& moneda){
    bool colision = forma.getGlobalBounds().intersects(moneda.getBounds());
    if(colision){
        moneda.desaparecer();
        puntos++;
        cout<<puntos;
    }
    return colision;
}

bool Jugador::seChocaConFuego(Fuego& fuego){
    bool colision = forma.getGlobalBounds().intersects(fuego.getBounds());
    if(colision){
        fuego.desaparecer();
        vidas--;
        setearJugador(0,400);
    }
    return colision;
}

void Jugador::caer(float posX, float posY) {
      if (forma.getPosition().x > posX && forma.getPosition().x < (posX + 20) && forma.getPosition().y == posY) {
        cayendo = true;
    }
}

void Jugador::setearJugador(float a, float b) {


    forma.setPosition(a, b);  //HACELO DINAMICO ASI SRVE PARA TODAS LAS CLASES

}

void Jugador::activarTrampa(float n, float posicionX) {
    if (x>n && !trampaActiva) {
        if (!animacionTrampa) {
            trampaActiva = true;
            animacionTrampa = true;
            alturaActualTrampa = 0;
            trampa.setPosition(posicionX, 450);
            trampa.setSize(sf::Vector2f(50, alturaActualTrampa)); // Inicializar el tamaño de la trampa a 0

        }
    }
}

void Jugador::actualizarTrampa() {
    if (animacionTrampa) {
        if (alturaActualTrampa < alturaMaxTrampa) {
            alturaActualTrampa += velocidadAperturaTrampa;
            trampa.setSize(sf::Vector2f(50, alturaActualTrampa)); // Actualizar el tamaño de la trampa
        } else {
            animacionTrampa = false;// Detener la animación cuando se alcance el tamaño máximo

        }
    }
}

void Jugador::setVidas(int v) {
    vidas = v;
}


