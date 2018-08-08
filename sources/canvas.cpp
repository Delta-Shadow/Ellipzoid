#include "canvas.h"

Canvas::Canvas(int w, int h) {
    window.create(sf::VideoMode(w, h), "Ellipzoid", sf::Style::Default);
}

void Canvas::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

bool Canvas::isOpen() {
    return window.isOpen();
}

void Canvas::cls() {
    window.clear(sf::Color::Black);
}

void Canvas::blit() {
    window.display();
}

void Canvas::draw(sf::CircleShape* shape) {
    window.draw(*shape);
}
