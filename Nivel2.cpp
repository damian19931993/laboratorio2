#include "Nivel2.h"

Nivel2::Nivel2(sf::RenderWindow& vent,Jugador& jug): Nivel(vent,jug,1,2){
    obstaculos[0] = Obstaculo(150, 300, 450); // Inicializar el primer obstáculo

    int posicionesX[] = { 200, 350};
    int posicionesY[] = { 400, 400};
    setMonedas(posicionesX, posicionesY, 2);

    rectangulo.setSize(sf::Vector2f(50,50));
    rectangulo.setFillColor(sf::Color::Cyan);
    rectangulo.setPosition(350,150);
}

void Nivel2::dibujar(){
    Nivel::dibujar();
}

void Nivel2::manejarEntrada(){
    Nivel::manejarEntrada();
}

void Nivel2::eventos(){
    Nivel::eventos();
}
void Nivel2::dibujarRectangulo(){
    ventana.draw(rectangulo);
}
