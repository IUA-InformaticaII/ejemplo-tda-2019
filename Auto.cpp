//
// Created by martin on 13/9/19.
//

#include "Auto.h"

Auto::Auto(Texture *tex, int x, int y) {
    spt.setTexture(*tex);
    ancho = tex->getSize().x;
    alto = tex->getSize().y;

    this->x = x;
    this->y = y;

    velX = 0;
    velY = 0;
}

void Auto::dibujar(RenderWindow *w) {
    spt.setPosition(x, y);
    w->draw(spt);
}

void Auto::acelerar() {
    y += -5;
}

void Auto::frenar() {
    y += 5;
}

void Auto::girar(char dire) {
    if (dire == 'i')
        x += -5;
    else if (dire == 'd')
        x += 5;
}

int Auto::getMedioX() {
    return x + ancho / 2;
}

int Auto::getY() {
    return y;
}
