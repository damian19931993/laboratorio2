#include "Obstaculo.h"

Obstaculo::Obstaculo() {
    // Constructor por defecto, puede dejar vacío o establecer valores por defecto
}

Obstaculo::Obstaculo(float pisoAltura, float x, float y) {
    float jugadorRadio = 15.0f; // Tamaño fijo para el jugador
    float ancho = jugadorRadio * 1.5f; // Hacer el rectángulo un poco más grande que el círculo del jugador
    float alto = jugadorRadio * 1.5f;

    // Establecer el tamaño del rectángulo
    forma.setSize(sf::Vector2f(ancho, alto));
    forma.setFillColor(sf::Color::Red); // Establecer el color del rectángulo

    // Establecer la posición del rectángulo en las coordenadas dadas
    forma.setPosition(x, y - alto); // Ajustar la posición vertical para que esté en la altura del piso
}

void Obstaculo::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(forma); // Dibujar el rectángulo en la ventana
}

sf::FloatRect Obstaculo::getBounds() const {
    return forma.getGlobalBounds(); // Devolver los límites del rectángulo
}

sf::Vector2f Obstaculo::getPosition() const {
    return forma.getPosition(); // Devolver la posición del rectángulo
}
