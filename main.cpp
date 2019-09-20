#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main(int argc, char *argv[]) {
    RenderWindow w(VideoMode(640, 480), "Ejemplo de SFML");
    Texture t;
    Sprite s;

    w.setFramerateLimit(30);

    t.loadFromFile("auto.png");
    s.setTexture(t);
    s.setPosition(100, 130);

    while (w.isOpen()) {
        Event e;
        while (w.pollEvent(e)) {
            if (e.type == Event::Closed)
                w.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            std::cout << "Izq" << std::endl;
        }
        s.setPosition(100, 130);
        w.clear(Color(255, 255, 255, 255));
        w.draw(s);
        w.display();
    }
    return 0;
}