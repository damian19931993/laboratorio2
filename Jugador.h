#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include "Obstaculo.h"
#include "Piso.h"
#include "PuertaBlanca.h"
#include "Moneda.h"

class Piso;

class Jugador {
private:
    sf::CircleShape forma;
    float x;
    float y;
    char nombre[30];
    bool quieto;
    bool caminandoAdelante;
    bool caminandoAtras;
    bool saltandoAdelante;
    bool saltandoAtras;
    bool cayendo;
    bool saltando;
    bool jugadorCayo=false;
    float velocidadSalto;
    float velocidadSaltoHorizontal;
    float velocidadMovimiento;
    float velocidadCaida;
    bool gameOver;
    int vidas;
    int puntos;

    sf::RectangleShape trampa;
    bool trampaActiva;
    bool animacionTrampa;
    float alturaActualTrampa;
    const float alturaMaxTrampa=200;
    const float velocidadAperturaTrampa = 0.03;

public:
    Jugador(float xx, float yy);

    void setSize(float ancho, float altura);

    void setForma(const sf::CircleShape& f) { forma = f; }
    void setX(float xx) { x = xx; }
    void setY(float yy) { y = yy; }
    void setNombre(const char* n) { strncpy(nombre, n, sizeof(nombre) - 1); nombre[sizeof(nombre) - 1] = '\0'; }
    void setQuieto(bool q) { quieto = q; }
    void setCaminandoAdelante(bool ca) { caminandoAdelante = ca; }
    void setCaminandoAtras(bool cat) { caminandoAtras = cat; }
    void setSaltando(bool s) { saltando = s; }
    void setSaltandoAdelante(bool sa) { saltandoAdelante = sa; }
    void setSaltandoAtras(bool sat) { saltandoAtras = sat; }
    void setCayendo(bool c) { cayendo = c; }
    void setVelocidadSalto(float vs) { velocidadSalto = vs; }
    void setVelocidadSaltoHorizontal(float vsh) { velocidadSaltoHorizontal = vsh; }
    void setVelocidadMovimiento(float vm) { velocidadMovimiento = vm; }
    void setVelocidadCaida(float vc) { velocidadCaida = vc; }



    sf::CircleShape getForma() const { return forma; }

    sf::RectangleShape& getForma();
    void activarTrampa();
    void actualizarTrampa(); // Método para actualizar la animación de la trampa
    bool isTrampaActiva();


    float getX() const { return x; }
    float getY() const { return y; }
    const char* getNombre() const { return nombre; }
    bool isQuieto() const { return quieto; }
    bool isCaminandoAdelante() const { return caminandoAdelante; }
    bool isCaminandoAtras() const { return caminandoAtras; }
    bool isSaltando() const { return saltando; }
    bool isSaltandoAdelante() const { return saltandoAdelante; }
    bool isSaltandoAtras() const { return saltandoAtras; }
    bool isCayendo() const { return cayendo; }
    float getVelocidadSalto() const { return velocidadSalto; }
    float getVelocidadSaltoHorizontal() const { return velocidadSaltoHorizontal; }
    float getVelocidadMovimiento() const { return velocidadMovimiento; }
    float getVelocidadCaida() const { return velocidadCaida; }
    float getVidas() const {
        return vidas;
    }
    bool isJugadorCayo() const {
        return jugadorCayo;
    }

    bool isGameOver(){
        return gameOver;
    }

    float getPuntos()const {
        return puntos;
    }

    void dibujar(sf::RenderWindow& ventana);
    void cmd();
    bool seChocan(Obstaculo obstaculo, PuertaBlanca puerta);
    bool seChocaPuerta(PuertaBlanca puerta);
    bool seChocaConMoneda(Moneda& moneda);
    void caer();
    void setearJugador();
    void dibujarTrampa(sf::RenderWindow& ventana);
};

#endif // JUGADOR_H_INCLUDED
