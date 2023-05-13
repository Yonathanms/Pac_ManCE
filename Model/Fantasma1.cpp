//
// Created by yonathanms on 12/05/23.
//

#include "../View-Controller/Fantasma1.h"

Fantasma1::Fantasma1() {

    sprt_ftsm1 = new Sprite;
    txtr_ftsm1 = new Texture;
    txtr_ftsm1->loadFromFile("../Recursos/Fantasma1.png");
    sprt_ftsm1->setTexture(*txtr_ftsm1);
    sprt_ftsm1->setOrigin(19,19);
    sprt_ftsm1->setPosition(100,200);
}

Sprite Fantasma1::GetFtsm1() {
    return *sprt_ftsm1;
}
