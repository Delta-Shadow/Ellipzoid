#include <iostream>

#include "canvas.h"
#include "circle.h"

using namespace std;

// Function Prototypes
int insertCircle(Circle*);
void attachCircle( Circle* a, Circle* b);

// Global Variables
const int MaxNumOfCircles = 5;
int numOfCircles = 0;

// Global Arrays
Circle* circles[MaxNumOfCircles];

int main() {
    Canvas ctx(800, 600);

    float vertices[8] = {200, 100, 200, 500, 600, 100, 600, 500};
    //float vertices[6] = {400, 100, 600, 500, 200, 500};
    //float vertices[4] = {200, 300, 600, 300};

    Circle c1(400, 300, 100, 1);
    c1.setPath(vertices, 4, 1);
    insertCircle(&c1);

    //Circle c2(0, 0, 50, 0.5);
    //attachCircle(&c2, &c1);
    //insertCircle(&c2);

    while (ctx.isOpen()) {
        ctx.handleEvents();

        //ctx.cls();

        for (int i = 0; i < numOfCircles; i++) {
            circles[i]->update();
            ctx.draw( circles[i]->getGeometry() );
        }

        ctx.blit();
    }

    return 0;
}

int insertCircle(Circle* c) {
    if (numOfCircles < MaxNumOfCircles) {
        circles[numOfCircles] = c;
        numOfCircles++;
        return 0;
    } else {
        return 1;
    }
}

void attachCircle( Circle* a, Circle* b) {
    a->setParent( b );
};
