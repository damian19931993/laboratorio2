#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include "Obstaculo.h"
#include "Piso.h"
#include "PuertaBlanca.h"
#include "Moneda.h"
#include "Fuego.h"

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
    bool siguienteNivel=false;
    bool habilitarGameOver=true;
    float velocidadSalto;
    float velocidadSaltoHorizontal;
    float velocidadMovimiento;
    float velocidadCaida;
    bool gameOver;
    int vidas;
    int puntos;
    int nivel;


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
    void setGameOver(bool go){
        gameOver=go;
    }
    void setVidas(int v);

    void setPuntos(int p){
        puntos=p;
    }

    void setSiguienteNivel(bool s){
        siguienteNivel=s;
    }

    void setTrampaActiva(bool t){
        trampaActiva=t;
    }

    void setAnimacionTrampa(bool a){
        animacionTrampa = a;
    }

    void setNivel(int n){
        nivel=n;
    }
    void setNombre(const std::string& n);




    sf::CircleShape getForma() const { return forma; }

    sf::RectangleShape& getForma();
    void activarTrampa(float n,float posicionX);
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
    int getVidas()  {
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

    bool isSiguienteNivel(){
        return siguienteNivel;
    }

    int getNivel(){
        return nivel;
    }
    bool seChocaConFuego(Fuego& fuego);

    void dibujar(sf::RenderWindow& ventana);
    void cmd();
    void manejarVidas();
    bool seChocan(Obstaculo obstaculo, PuertaBlanca puerta);
    bool seChocaPuerta(PuertaBlanca puerta);
    bool seChocaConMoneda(Moneda& moneda);
    void caer(float posX, float posY);
    void setearJugador(float a, float b);
    void dibujarTrampa(sf::RenderWindow& ventana);
};

#endif // JUGADOR_H_INCLUDED
