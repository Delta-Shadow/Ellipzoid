#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>

#include <SFML/Graphics.hpp>

class Circle {
    public:
        Circle(float _x, float _y, float _r, float _s);

        void update();

        float getX();
        float getY();
        float getRadius();

        void setParent( Circle* );

        void setPath(float[], int, float);

        sf::CircleShape* getGeometry();

    private:
        float x; float y;
        float tx; float ty;
        float px; float py;
        float vx; float vy;

        float r;
        float a;
        float angleAroundParent;
        float speed;
        float speedAroundParent;
        Circle* parent;

        float path[200];
        float numberOfVertices;
        int currentVertex;
        float speedOnPath;

        sf::CircleShape geometry;

        void switchToNextTarget();
        void calcVectors();
};

#endif
