//
// Created by yonathanms on 12/05/23.
//

#include "../View-Controller/Fantasma1.h"

Fantasma1::Fantasma1() {

    tiempo_FrameFtsm1 = new Time;
    reloj_FrameFtsm1 = new Clock;

    sprt_ftsm1 = new Sprite;
    txtr_ftsm1 = new Texture;
    //txtr_ftsm1->loadFromFile("../Recursos/Fantasma1.png");
    sprt_ftsm1->setTexture(*txtr_ftsm1);
    sprt_ftsm1->setOrigin(19,19);
    sprt_ftsm1->setPosition(518,493);

    num_frameFtsm1 = 0;
}

Sprite Fantasma1::GetFtsm1() {
    return *sprt_ftsm1;
}

void Fantasma1::SetFrameFtsm1(bool vulnerabilidad) {
    txtr_ftsm1->loadFromFile("../Recursos/Fantasma1.png");
    *tiempo_FrameFtsm1 = reloj_FrameFtsm1->getElapsedTime();
    if (vulnerabilidad == false) {
        if (num_frameFtsm1 <= 8) {
            if (num_frameFtsm1 < 8) {

                if (tiempo_FrameFtsm1->asMilliseconds() < 88 and tiempo_FrameFtsm1->asMilliseconds() > 75) {
                    IntRect coordenadas(num_frameFtsm1 * 38, 0, 38, 38);
                    num_frameFtsm1++;
                    sprt_ftsm1->setTextureRect(coordenadas);
                }
                if (tiempo_FrameFtsm1->asMilliseconds() > 88.1) {
                    reloj_FrameFtsm1->restart();
                }
            } else {
                num_frameFtsm1 = 0;
            }
        }
    } else {
        txtr_ftsm1->loadFromFile("../Recursos/Fantasma_cazar.png");
        if (num_frameFtsm1 <= 8) {
            if (num_frameFtsm1 < 8) {

                if (tiempo_FrameFtsm1->asMilliseconds() < 88 and tiempo_FrameFtsm1->asMilliseconds() > 75) {
                    IntRect coordenadas(num_frameFtsm1 * 38, 0, 38, 38);
                    num_frameFtsm1++;
                    sprt_ftsm1->setTextureRect(coordenadas);
                    cout << "FRAME FTSM2= " << num_frameFtsm1 << endl;
                    cout<<"soy fantasma 2"<<endl;
                }
                if (tiempo_FrameFtsm1->asMilliseconds() > 88.1) {
                    reloj_FrameFtsm1->restart();
                }
            } else {
            num_frameFtsm1 = 0;
            }
        }
    }
}


