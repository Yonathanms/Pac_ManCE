//
// Created by yonathanms on 25/04/23.
//

#include "../View-Controller/Ventana_Principal.h"
#include "../View-Controller/Nivel2.h"

Ventana_Principal::Ventana_Principal() {

    VentanaPrincipal = new RenderWindow(VideoMode(950, 1000), "Hola xd");
    VentanaPrincipal->setFramerateLimit(60);

    events = new Event;

    btnJugar = new RectangleShape;
    btnJugar ->setSize(Vector2f(150,50));
    btnJugar ->setPosition(400,450);
    btnJugar ->setFillColor(Color::Green);

    Ciclar();
}

void Ventana_Principal::Eventos() {
    while (VentanaPrincipal->pollEvent(*events)) {
        switch (events->type) {
            case Event::Closed:
                VentanaPrincipal->close();
                std::cout << "Ventana facil cerrada de forma exitosa" << std::endl;
                exit(1);

            case Event::MouseButtonPressed:
                Vector2i posicionmouse = Mouse::getPosition(*VentanaPrincipal);

                if (posicionmouse.x >= btnJugar->getPosition().x &&
                    posicionmouse.x <= btnJugar->getPosition().x + btnJugar->getSize().x &&
                    posicionmouse.y >= btnJugar->getPosition().y &&
                    posicionmouse.y <= btnJugar->getPosition().y + btnJugar->getSize().y) {
                    std::cout << "hola ventana nueva de modo facil xd" << std::endl;
                    VentanaPrincipal->close();
                    Nivel2(2500);

                }
        }

    }
}

void Ventana_Principal::Ciclar() {
    while (VentanaPrincipal->isOpen()){
        Eventos();
        Renderizar();
    }
}

void Ventana_Principal::Renderizar() {
    VentanaPrincipal->clear();

    VentanaPrincipal->draw(*btnJugar);

    VentanaPrincipal->display();
}




