//
// Created by yonathanms on 25/04/23.
//

#include <iostream>
#include "../View-Controller/Nivel1.h"


Nivel1::Nivel1() {
    Vtn_Nivel1 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel1->setFramerateLimit(60);

    events = new Event;

    txtr_fondoV1 = new Texture;
    sprt_fondoV1 = new Sprite;


    txtr_fondoV1->loadFromFile("../Recursos/FondoVtn1.png");
    sprt_fondoV1->setTexture(*txtr_fondoV1);
   //textpm->loadFromFile("../Recursos/FramesPacman.png");
    //pacman2->setTexture(*textpm);
  //  pacman2->setScale(2.0, 2.0);
   // pacman2->setPosition(100,150);


    movePM = true;
    num_framePM = 0;

    Ciclar();

}

void Nivel1::Renderizar() {
    Vtn_Nivel1->clear();

    Vtn_Nivel1->draw(*sprt_fondoV1);
    Vtn_Nivel1->draw(GetSprPacman());
    //Vtn_Nivel1->draw(*pacman2);

    Vtn_Nivel1->display();
}

void Nivel1::Ciclar() {
    while (Vtn_Nivel1->isOpen()){
        Colisiones();
        Eventos();
        Renderizar();


    }
}

void Nivel1::Eventos() {
    while (Vtn_Nivel1->pollEvent(*events)) {
        switch (events->type) {
            case Event::Closed:
                Vtn_Nivel1->close();
                cout << "Ventana facil cerrada de forma exitosa" << endl;
                exit(1);

            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::W)) {
                    MovePM(0, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }

                }
                else if (Keyboard::isKeyPressed(Keyboard::S)){
                    MovePM(1, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::A)) {
                    MovePM(2, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)){
                    MovePM(3, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
        }
    }
}

void Nivel1::Colisiones() {

   // if (GetSprPacman().getGlobalBounds().intersects(pacman2->getGlobalBounds())){
       // movePM = false;
       // cout<<"colisiono"<<GetSprPacman().getPosition().x<<endl;
   // }
   // else{
       // movePM = true;
  //  }

}

void Nivel1::barreras() {
    

}
