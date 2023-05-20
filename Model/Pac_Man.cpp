//
// Created by yonathanms on 28/04/23.
//

#include "../View-Controller/Pac_Man.h"

Pac_Man::Pac_Man() {
    spr_PacMan = new Sprite;
    txtr_PacMan = new Texture;

    txtr_PacMan->loadFromFile("../Recursos/FramesPacman.png");
    spr_PacMan->setTexture(*txtr_PacMan);
    spr_PacMan->setPosition(488,583);
    spr_PacMan->setOrigin(20,20);

    SetFrame(0);
    num_vidasPM = 3;
}

void Pac_Man::SetCeldasPosiciones(vector<Vector2i> celdas) {
    vPosicionCelda_xy = celdas;
}

Sprite Pac_Man::GetSprPacman() {
    return *spr_PacMan;
}



///metodo que divide es sprite del pacman en sprites mas pequenos
void Pac_Man::SetFrame( int num_frame) {
    IntRect coordenadas(num_frame*40,0,40,40);
    spr_PacMan->setTextureRect(coordenadas);
}


bool Pac_Man::PuedeMoverse( Vector2i  posicionActual,  vector<Vector2i> celdasPermitidas, Vector2i coordenadas_move) {
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



void Pac_Man::MovePM(int num_direction) {

    if (num_direction == 0) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {0, -5}) == true) {
            spr_PacMan->move(0, -5);
            spr_PacMan->setRotation(270.0);
            spr_PacMan->setScale(1.0f, 1.0f);
        }
    }

    if (num_direction == 1) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {0, 5}) == true) {
            spr_PacMan->move(0, 5);
            spr_PacMan->setRotation(90.0);
            spr_PacMan->setScale(1.0f, 1.0f);
        }
    }

    if (num_direction == 2) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {-5, 0}) == true) {
            spr_PacMan->move(-5, 0);
            spr_PacMan->setRotation(180.0);
            spr_PacMan->setScale(1.0f, -1.0f);
        }
    }

    if (num_direction == 3) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {5, 0}) == true) {
            spr_PacMan->move(5, 0);
            spr_PacMan->setRotation(0.0);
            spr_PacMan->setScale(1.0f, 1.0f);
        }
    }
}

int Pac_Man::Reduccion_VidasPM(bool defensa) {
    if (defensa == true) {
        cout << num_vidasPM << " = numero de vidas"<<endl;
        return num_vidasPM;

    }else{
        num_vidasPM--;
        cout << num_vidasPM << " = numero de vidas"<<endl;
        return num_vidasPM;
    }
}

int Pac_Man::Get_NumVidasPM() {
    return num_vidasPM;
}

void Pac_Man::SetNewPosition_PM(bool kill) {
    if (kill == false){
       int indice_posrandom = rand()% vPosicionCelda_xy.size();
       cout << indice_posrandom << "= num random 1"<<endl;
       spr_PacMan->setPosition(vPosicionCelda_xy[indice_posrandom].x,vPosicionCelda_xy[indice_posrandom].y);
    }
}












