//
// Created by yonathanms on 12/05/23.
//

#include "../View-Controller/Fantasma1.h"

Fantasma1::Fantasma1() {

    tiempo_FrameFtsm1 = new Time;
    reloj_FrameFtsm1 = new Clock;

    tiempo_spawnFtsm1 = new Time;

    sprt_ftsm1 = new Sprite;
    txtr_ftsm1 = new Texture;
    sprt_ftsm1->setTexture(*txtr_ftsm1);
    sprt_ftsm1->setOrigin(19,19);
    sprt_ftsm1->setPosition(518,493);

    sprt_killftsm1 = new Sprite;
    txtr_killftsm1 = new Texture;
    txtr_killftsm1->loadFromFile("../Recursos/FtsmKill.png");
    sprt_killftsm1->setTexture(*txtr_killftsm1);
    sprt_killftsm1->setOrigin(19,19);



    num_frameFtsm1 = 0;
    direccion_move = 0;
}

void Fantasma1::SetCeldasPosicionesFtsm1(vector<Vector2i> celdas) {
    vPosicionesCelda_xy = celdas;
}

Sprite Fantasma1::GetSprt_killFtsm1() {
    return *sprt_killftsm1;
}

Sprite Fantasma1::GetFtsm1() {
    return *sprt_ftsm1;
}

bool Fantasma1::PuedeMoverse(const Vector2i &posicionActual, const vector<Vector2i> &celdasPermitidas,Vector2i coordenadas_move) {
    Vector2i nuevaPosicion1 = posicionActual + coordenadas_move;
    Vector2i nuevaPosicion2 = posicionActual + coordenadas_move*2;
    Vector2i nuevaPosicion3 = posicionActual + coordenadas_move*3;
    Vector2i nuevaPosicion4 = posicionActual + coordenadas_move*4;
    Vector2i nuevaPosicion5 = posicionActual + coordenadas_move*5;
    Vector2i nuevaPosicion6 = posicionActual + coordenadas_move*6;
    for (const auto& celda : celdasPermitidas) {
        if (nuevaPosicion1 == celda or nuevaPosicion2 == celda or nuevaPosicion3 == celda or nuevaPosicion4 == celda or nuevaPosicion5 == celda or nuevaPosicion6 == celda) {
            return true;
        }
    }
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


void Fantasma1::RespawnFtsm1(bool Ftsm_herido,Clock relojinicial,Vector2f coord_posFtsm1,  int num_random) {
    if (Ftsm_herido == true) {
        *tiempo_spawnFtsm1 = relojinicial.getElapsedTime();
        if (tiempo_spawnFtsm1->asSeconds() < 5) {
            sprt_killftsm1->setPosition(coord_posFtsm1.x, coord_posFtsm1.y);
            cout<<sprt_killftsm1->getPosition().x<<"x ,"<<sprt_killftsm1->getPosition().y<<"y" <<endl;
            cout <<"Tiempo de carga SPAWN = "<< tiempo_spawnFtsm1->asSeconds() <<"segundos"<< endl;
            sprt_ftsm1->setPosition(-100,-100);
        }
        if(tiempo_spawnFtsm1->asSeconds() > 5.1 and tiempo_spawnFtsm1->asSeconds()<5.3){
            cout <<"Tiempo de carga SPAWN = "<< tiempo_spawnFtsm1->asSeconds() <<"segundos"<< endl;
            sprt_killftsm1->setPosition(-100,-100);
            sprt_ftsm1->setPosition(vPosicionesCelda_xy[num_random].x,vPosicionesCelda_xy[num_random].y);
        }
    }
}

void Fantasma1::MoveFtsm1(bool PU_activo, Vector2f posPM) {
    if (PU_activo == true){

    } else{
        if (direccion_move == 0){
            if (PuedeMoverse({static_cast<int>(sprt_ftsm1->getPosition().x), static_cast<int>(sprt_ftsm1->getPosition().y)}, vPosicionesCelda_xy,
                             {0,-5})){
                sprt_ftsm1->move(0,-5);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 1){
            if (PuedeMoverse({static_cast<int>(sprt_ftsm1->getPosition().x), static_cast<int>(sprt_ftsm1->getPosition().y)}, vPosicionesCelda_xy,
                             {5,0})){
                sprt_ftsm1->move(5,0);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 2){
            if (PuedeMoverse({static_cast<int>(sprt_ftsm1->getPosition().x), static_cast<int>(sprt_ftsm1->getPosition().y)}, vPosicionesCelda_xy,
                             {0,5})){
                sprt_ftsm1->move(0,5);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 3){
            if (PuedeMoverse({static_cast<int>(sprt_ftsm1->getPosition().x), static_cast<int>(sprt_ftsm1->getPosition().y)}, vPosicionesCelda_xy,
                             {-5,0})){
                sprt_ftsm1->move(-5,0);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
    }
}



