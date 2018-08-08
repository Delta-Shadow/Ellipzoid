#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>

#include "SFML\Graphics.hpp"

class Canvas {
    public:
        Canvas(int, int);
        void handleEvents();
        bool isOpen();
        void cls();
        void blit();
        void draw(sf::CircleShape*);

    private:
        sf::RenderWindow window;
};

#endif
