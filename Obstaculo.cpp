#include "Obstaculo.h"

Obstaculo::Obstaculo() {
    // Constructor por defecto, puede dejar vac�o o establecer valores por defecto
}

Obstaculo::Obstaculo(float pisoAltura, float x, float y) {
    float jugadorRadio = 15.0f; // Tama�o fijo para el jugador
    float ancho = jugadorRadio * 1.5f; // Hacer el rect�ngulo un poco m�s grande que el c�rculo del jugador
    float alto = jugadorRadio * 1.5f;

    // Establecer el tama�o del rect�ngulo
    forma.setSize(sf::Vector2f(ancho, alto));
    forma.setFillColor(sf::Color::Red); // Establecer el color del rect�ngulo

    // Establecer la posici�n del rect�ngulo en las coordenadas dadas
    forma.setPosition(x, y - alto); // Ajustar la posici�n vertical para que est� en la altura del piso
}

void Obstaculo::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(forma); // Dibujar el rect�ngulo en la ventana
}

sf::FloatRect Obstaculo::getBounds() const {
    return forma.getGlobalBounds(); // Devolver los l�mites del rect�ngulo
}

sf::Vector2f Obstaculo::getPosition() const {
    return forma.getPosition(); // Devolver la posici�n del rect�ngulo
}
