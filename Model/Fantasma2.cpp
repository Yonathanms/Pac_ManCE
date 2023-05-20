//
// Created by yonathanms on 19/05/23.
//

#include "../View-Controller/Fantasma2.h"

Fantasma2::Fantasma2() {

    tiempo_FrameFtsm2 = new Time;
    reloj_FrameFtsm2 = new Clock;

    tiempo_spawnFtsm2 = new Time;

    sprt_ftsm2 = new Sprite;
    txtr_ftsm2 = new Texture;
    sprt_ftsm2->setTexture(*txtr_ftsm2);
    sprt_ftsm2->setOrigin(19,19);
    sprt_ftsm2->setPosition(518,493);

    sprt_killftsm2 = new Sprite;
    txtr_killftsm2 = new Texture;
    txtr_killftsm2->loadFromFile("../Recursos/FtsmKill.png");
    sprt_killftsm2->setTexture(*txtr_killftsm2);
    sprt_killftsm2->setOrigin(19,19);



    num_frameFtsm2 = 0;
    direccion_move = 0;
}

void Fantasma2::SetCeldasPosicionesFtsm2(vector<Vector2i> celdas) {
    vPosicionesCelda_xy = celdas;
}

Sprite Fantasma2::GetSprt_killFtsm2() {
    return *sprt_killftsm2;
}

Sprite Fantasma2::GetFtsm2() {
    return *sprt_ftsm2;
}

bool Fantasma2::PuedeMoverseFtsm2(const Vector2i &posicionActual, const vector<Vector2i> &celdasPermitidas,Vector2i coordenadas_move) {
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



void Fantasma2::SetFrameFtsm2(bool vulnerabilidad) {
    txtr_ftsm2->loadFromFile("../Recursos/Fantasma2.png");
    *tiempo_FrameFtsm2 = reloj_FrameFtsm2->getElapsedTime();
    if (vulnerabilidad == false) {
        if (num_frameFtsm2 <= 8) {
            if (num_frameFtsm2 < 8) {

                if (tiempo_FrameFtsm2->asMilliseconds() < 88 and tiempo_FrameFtsm2->asMilliseconds() > 75) {
                    IntRect coordenadas(num_frameFtsm2 * 38, 0, 38, 38);
                    num_frameFtsm2++;
                    sprt_ftsm2->setTextureRect(coordenadas);
                }
                if (tiempo_FrameFtsm2->asMilliseconds() > 88.1) {
                    reloj_FrameFtsm2->restart();
                }
            } else {
                num_frameFtsm2 = 0;
            }
        }
    } else {
        txtr_ftsm2->loadFromFile("../Recursos/Fantasma_cazar.png");
        if (num_frameFtsm2 <= 8) {
            if (num_frameFtsm2 < 8) {

                if (tiempo_FrameFtsm2->asMilliseconds() < 88 and tiempo_FrameFtsm2->asMilliseconds() > 75) {
                    IntRect coordenadas(num_frameFtsm2 * 38, 0, 38, 38);
                    num_frameFtsm2++;
                    sprt_ftsm2->setTextureRect(coordenadas);
                }
                if (tiempo_FrameFtsm2->asMilliseconds() > 88.1) {
                    reloj_FrameFtsm2->restart();
                }
            } else {
                num_frameFtsm2 = 0;
            }
        }
    }
}


void Fantasma2::RespawnFtsm2(bool Ftsm_herido,Clock relojinicial,Vector2f coord_posFtsm1,  int num_random) {
    if (Ftsm_herido == true) {
        *tiempo_spawnFtsm2 = relojinicial.getElapsedTime();
        if (tiempo_spawnFtsm2->asSeconds() < 5) {
            sprt_killftsm2->setPosition(coord_posFtsm1.x, coord_posFtsm1.y);
            cout<<sprt_killftsm2->getPosition().x<<"x ,"<<sprt_killftsm2->getPosition().y<<"y" <<endl;
            cout <<"Tiempo de carga SPAWN = "<< tiempo_spawnFtsm2->asSeconds() <<"segundos"<< endl;
            sprt_ftsm2->setPosition(-100,-100);
        }
        if(tiempo_spawnFtsm2->asSeconds() > 5.1 and tiempo_spawnFtsm2->asSeconds()<5.3){
            cout <<"Tiempo de carga SPAWN = "<< tiempo_spawnFtsm2->asSeconds() <<"segundos"<< endl;
            sprt_killftsm2->setPosition(-100,-100);
            sprt_ftsm2->setPosition(vPosicionesCelda_xy[num_random].x,vPosicionesCelda_xy[num_random].y);
        }
    }
}

void Fantasma2::MoveFtsm2(bool PU_activo, Vector2f posPM) {
    if (PU_activo == true){

    } else{
        if (direccion_move == 0){
            if (PuedeMoverseFtsm2({static_cast<int>(sprt_ftsm2->getPosition().x), static_cast<int>(sprt_ftsm2->getPosition().y)}, vPosicionesCelda_xy,
                                  {0,-5})){
                sprt_ftsm2->move(0,-5);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 1){
            if (PuedeMoverseFtsm2({static_cast<int>(sprt_ftsm2->getPosition().x), static_cast<int>(sprt_ftsm2->getPosition().y)}, vPosicionesCelda_xy,
                                  {5,0})){
                sprt_ftsm2->move(5,0);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 2){
            if (PuedeMoverseFtsm2({static_cast<int>(sprt_ftsm2->getPosition().x), static_cast<int>(sprt_ftsm2->getPosition().y)}, vPosicionesCelda_xy,
                                  {0,5})){
                sprt_ftsm2->move(0,5);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
        if (direccion_move == 3){
            if (PuedeMoverseFtsm2({static_cast<int>(sprt_ftsm2->getPosition().x), static_cast<int>(sprt_ftsm2->getPosition().y)}, vPosicionesCelda_xy,
                                  {-5,0})){
                sprt_ftsm2->move(-5,0);
            } else{
                direccion_move = rand()% 4-0;
            }
        }
    }
}
