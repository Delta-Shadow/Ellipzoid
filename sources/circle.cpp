#include "utils.h"
#include "circle.h"

using namespace std;

Circle::Circle(float _x, float _y, float _r, float _s) {
    x = _x; y = _y;
    tx = 0; ty = 0;
    px = 0; py = 0;
    vx = 0; vy = 0;

    r = _r; 
    a = 0;
    angleAroundParent = 0;
    speed = rads(_s);
    speedAroundParent = 0.1;
    parent = NULL;

    numberOfVertices = 0;
    currentVertex = 0;
    speedOnPath = 1;

    geometry.setRadius(1);
    geometry.setPointCount(360);
    geometry.setFillColor(sf::Color::White);
    geometry.setPosition(px, py);
};

void Circle::update() {
    if (parent != NULL) {
        angleAroundParent += rads(speedAroundParent);
        x = parent->getX() + ( cos(angleAroundParent) * (r + parent->getRadius()) );
        y = parent->getY() + ( sin(angleAroundParent) * (r + parent->getRadius()) );
    } else if (numberOfVertices != 0) {
        float xDist = tx - x;
        float yDist = ty - y;
        float dist = sqrt((xDist*xDist) + (yDist*yDist));
        if (dist <= 0) {
            switchToNextTarget();
        }
        calcVectors();
        x += vx * speedOnPath;
        y += vy * speedOnPath;
    }

    a += speed;
    px = x + (cos(a) * r);
    py = y + (sin(a) * r);

    geometry.setPosition(x, y);
}

float Circle::getX() {
    return x;
}

float Circle::getY() {
    return y;
}

float Circle::getRadius() {
    return r;
}

sf::CircleShape* Circle::getGeometry() {
    return &geometry;
}

void Circle::setParent(Circle* c) {
    parent = c;
}

void Circle::setPath(float ptns[], int numOfVertices, float s) {
    if (numOfVertices > 100) numOfVertices = 100;
    numberOfVertices = numOfVertices;
    for (int i = 0; i < numOfVertices*2; i++) {
        path[i] = ptns[i];
    }
    x = path[0];
    y = path[1];
    currentVertex = 1;
    tx = path[currentVertex*2];
    ty = path[currentVertex*2 + 1];
    calcVectors();
    speedOnPath = s;
}

void Circle::switchToNextTarget() {
    currentVertex++;
    if (currentVertex > numberOfVertices - 1) {
        currentVertex = 0;
    } 
    tx = path[currentVertex*2];
    ty = path[(currentVertex*2) + 1];
}

void Circle::calcVectors() {
    float dx = tx - x;
    float dy = ty - y;
    float d = sqrt((dx*dx) + (dy*dy));
    if (d <= 0) d = 1;
    vx = dx / d;
    vy = dy / d;
}
