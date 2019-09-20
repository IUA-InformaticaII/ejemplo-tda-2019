#ifndef AUTO_H
#define AUTO_H

#include <SFML/Graphics.hpp>

using namespace sf;


class Auto {
private:
    int x;
    int y;
    int velX;
    int velY;
    int ancho;
    int alto;
    Sprite spt;

public:
    Auto(Texture *tex, int x, int y);

    void mover();

    void dibujar(RenderWindow *w);

    void acelerar();

    void frenar();

    void girar(char dire);


    // Agregadas

    int getMedioX();

    int getY();


};


#endif //AUTO_H
