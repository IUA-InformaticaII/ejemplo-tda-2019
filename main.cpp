#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main(int argc, char *argv[]) {
    RenderWindow w(VideoMode(640, 480), "Ejemplo de SFML");
    Texture tAuto, tBala;
    Sprite sAuto, sBala;

    int xAuto = 100;
    int yAuto = 130;
    int xBala = 100;
    int yBala = 130;
    bool dibujarBala = false;

    w.setFramerateLimit(30);

    tAuto.loadFromFile("auto.png");
    sAuto.setTexture(tAuto);
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
            std::cout << "Izq" << std::endl;
            xAuto += -5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            std::cout << "Der" << std::endl;
            xAuto += 5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            std::cout << "Up" << std::endl;
            yAuto += -5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            std::cout << "Down" << std::endl;
            yAuto += +5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if(!dibujarBala){
                dibujarBala = true;
                yBala = yAuto - 16;
                xBala = xAuto +53/2-7/2;
            }

        }
        sAuto.setPosition(xAuto, yAuto);
        w.clear(Color(255, 255, 255, 255));
        w.draw(sAuto);

        if (dibujarBala) {
            sBala.setPosition(xBala, yBala);
            yBala = yBala - 10;
            w.draw(sBala);
            if(yBala < 0)
                dibujarBala = false;
        }

        w.display();
    }
    return 0;
}