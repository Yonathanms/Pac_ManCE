//
// Created by yonathanms on 25/04/23.
//

#include <iostream>
#include "../View-Controller/Nivel1.h"


Nivel1::Nivel1() {
    Vtn_Nivel1 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel1->setFramerateLimit(60);
    events = new Event;


    Ciclar();

}

void Nivel1::Renderizar() {
    Vtn_Nivel1->clear();

    Vtn_Nivel1->draw(GetSprPacman());

    Vtn_Nivel1->display();
}

void Nivel1::Ciclar() {
    while (Vtn_Nivel1->isOpen()){
        Renderizar();
        Eventos();
    }
}

void Nivel1::Eventos() {
    while (Vtn_Nivel1->pollEvent(*events)) {
        switch (events->type) {
            case Event::Closed:
                Vtn_Nivel1->close();
                std::cout << "Ventana facil cerrada de forma exitosa" << std::endl;
                exit(1);

            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::W)) {
                    MovePM(0);                                /// al apretar 'w' ingresa un '1' en la funcion de movimiento de la nave
                }
                if (Keyboard::isKeyPressed(Keyboard::S)){
                    MovePM(1);                              /// al apretar 'w' ingresa un '0' en la funcion de movimiento de la nave
                }
                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    MovePM(2);                                /// al apretar 'w' ingresa un '1' en la funcion de movimiento de la nave
                }
                if (Keyboard::isKeyPressed(Keyboard::D)){
                    MovePM(3);                              /// al apretar 'w' ingresa un '0' en la funcion de movimiento de la nave
                }
        }
    }
}
