#include <SFML/Graphics.hpp>
#include <iostream>

#include "Auto.h"

using namespace sf;

int main(int argc, char *argv[]) {
    RenderWindow w(VideoMode(640, 480), "Ejemplo de SFML");
    Texture tAuto, tBala;
    Sprite sBala;

    // Cargo textura del auto y lo asigno al jugador.
    tAuto.loadFromFile("auto.png");
    Auto player(&tAuto, 640 / 2, 480 / 2);

    int xBala = 100;
    int yBala = 130;
    bool dibujarBala = false;

    w.setFramerateLimit(30);

    tBala.loadFromFile("bala.png");
    sBala.setTexture(tBala);
    sBala.setPosition(50, 50);

    while (w.isOpen()) {
        Event e;
        while (w.pollEvent(e)) {
            if (e.type == Event::Closed)
                w.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.girar('i');
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.girar('d');
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player.acelerar();
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            player.frenar();
        }

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (!dibujarBala) {
                dibujarBala = true;
                yBala = player.getY() - 16;
                xBala = player.getMedioX() - 7 / 2;
            }

        }
        w.clear(Color(255, 255, 255, 255));
        player.dibujar(&w);

        if (dibujarBala) {
            sBala.setPosition(xBala, yBala);
            yBala = yBala - 10;
            w.draw(sBala);
            if (yBala < 0)
                dibujarBala = false;
        }

        w.display();
    }
    return 0;
}