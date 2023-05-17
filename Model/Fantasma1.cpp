//
// Created by yonathanms on 12/05/23.
//

#include "../View-Controller/Fantasma1.h"

Fantasma1::Fantasma1() {

    tiempo_FrameFtsm1 = new Time;
    reloj_FrameFtsm1 = new Clock;

    tiempo_spawnFtsm1 = new Time;
    reloj_spawnFtsm1 = new Clock;

    sprt_ftsm1 = new Sprite;
    txtr_ftsm1 = new Texture;
    //txtr_ftsm1->loadFromFile("../Recursos/Fantasma1.png");
    sprt_ftsm1->setTexture(*txtr_ftsm1);
    sprt_ftsm1->setOrigin(19,19);
    sprt_ftsm1->setPosition(518,493);

    sprt_killftsm1 = new Sprite;
    txtr_killftsm1 = new Texture;
    txtr_killftsm1->loadFromFile("../Recursos/FtsmKill.png");
    sprt_killftsm1->setTexture(*txtr_killftsm1);
    sprt_killftsm1->setOrigin(19,19);



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
                   // cout << "FRAME FTSM2= " << num_frameFtsm1 << endl;
                   // cout<<"soy fantasma 2"<<endl;
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

///falta terminar esta funcion
void Fantasma1::RespawnFtsm1(bool kill_ftsm, Vector2i PosFtsm, vector <Vector2i> PosCeldas, int num_celdas) {
    *tiempo_spawnFtsm1 = reloj_spawnFtsm1->getElapsedTime();
    if (kill_ftsm == true) {
        cout << reloj_spawnFtsm1 << " reloj" << endl;
        cout << tiempo_spawnFtsm1->asSeconds() << " tiempo" << endl;
        if (tiempo_spawnFtsm1->asSeconds() <= 5) {
            sprt_killftsm1->setPosition(PosFtsm.x, PosFtsm.y);
            sprt_ftsm1->setPosition(-100, -100);
        }
        if (tiempo_spawnFtsm1->asSeconds() >= 5) {
            int indice_random = rand() % num_celdas;
            sprt_killftsm1->setPosition(-100, -100);
            sprt_ftsm1->setPosition(PosCeldas[indice_random].x, PosCeldas[indice_random].y);
        }
    } else{
        reloj_spawnFtsm1->restart();
    }
}

