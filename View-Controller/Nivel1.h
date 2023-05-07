//
// Created by yonathanms on 25/04/23.
//

#ifndef PAC_MAN_NIVEL1_H
#include "SFML/Graphics.hpp"
#include "../View-Controller/Pac_Man.h"
#define PAC_MAN_NIVEL1_H

using namespace sf;

class Nivel1: public Pac_Man{
public:
    Nivel1();
    void Renderizar();
    void Ciclar();
    void Eventos();
    void Colisiones();
    void barreras();

private:
    RenderWindow *Vtn_Nivel1;
    Event *events;

    Sprite *sprt_fondoV1;
    Texture *txtr_fondoV1;


    int num_framePM;
    bool movePM;
};


#endif //PAC_MAN_NIVEL1_H
