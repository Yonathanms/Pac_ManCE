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

    ///posiciones donde se puede mover
    //celda x
    vPosicionCelda_x = {0,1,2,3,4,5,6,7,8,9,10,11,14,15,16,17,18,19,20,21,22,23,24,25,0,5,11,14,20,25,
                        0,5,11,14,20,25,0,5,11,14,20,25,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                        17,18,19,20,21,22,23,24,25,0,5,8,17,20,25,0,5,8,17,20,25,0,1,2,3,4,5,8,9,
                        10,11,14,15,16,17,20,21,22,23,24,25,5,11,14,20,5,11,14,20,5,8,9,10,11,12,13,14,
                        15,16,17,20,5,8,12,13,17,20,5,8,10,11,12,13,14,15,17,20,0,1,2,3,4,5,6,7,8,10,11,
                        12,13,14,15,17,18,19,20,21,22,23,24,25,5,8,10,11,12,13,14,15,17,20,5,8,17,20,5,
                        8,9,10,11,12,13,14,15,16,17,20,5,8,17,20,5,8,17,20,0,1,2,3,4,5,6,7,8,9,10,11,14,
                        15,16,17,18,19,20,21,22,23,24,25,0,5,11,14,20,25,0,5,11,14,20,25,0,1,2,5,6,7,8,9,
                        10,11,12,13,14,15,16,17,18,19,20,23,24,25,2,5,8,17,20,23,2,5,8,17,20,23,0,1,2,3,
                        4,5,8,9,10,11,14,15,16,17,20,21,22,23,24,25,0,11,14,25,0,11,14,25,0,1,2,3,4,5,6,7,
                        8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    //celda y
    vPosicionCelda_y = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    //celdas x y y
    while (vPosicionCelda_xy.size() != 318){
        vPosicionCelda_xy.push_back({98+30*vPosicionCelda_x[0] ,103+30*vPosicionCelda_y[0]});
        vPosicionCelda_x.erase(vPosicionCelda_x.begin());
       // cout << vPosicionCelda_xy[0].x<<vPosicionCelda_xy[0].y << endl;
        if (vPosicionCelda_x[0]>=vPosicionCelda_x[1]){
            vPosicionCelda_xy.push_back({98+30*vPosicionCelda_x[0] ,103+30*vPosicionCelda_y[0]});
            vPosicionCelda_x.erase(vPosicionCelda_x.begin());
            vPosicionCelda_y.erase(vPosicionCelda_y.begin());
        }
    }

    SetFrame(0);
    num_vidasPM = 3;
}

Sprite Pac_Man::GetSprPacman() {
    return *spr_PacMan;
}



///metodo que divide es sprite del pacman en sprites mas pequenos
void Pac_Man::SetFrame( int num_frame) {
    IntRect coordenadas(num_frame*40,0,40,40);
    spr_PacMan->setTextureRect(coordenadas);
}


bool Pac_Man::PuedeMoverse(const Vector2i & posicionActual, const vector<Vector2i>& celdasPermitidas, Vector2i coordenadas_move) {
    Vector2i nuevaPosicion = posicionActual + coordenadas_move;
    for (const auto& celda : celdasPermitidas) {
        if (nuevaPosicion == celda) {
           // cout <<"v resultante=  "<< nuevaPosicion.x<<"x ,"<<nuevaPosicion.y<<"y"<< endl;
           // cout <<"v contenido en vPosiciones_xy =  "<< celda.x<<"x ,"<<celda.y<<"y"<< endl;
            return true;
        } else{
           // cout <<"v resultante error =  "<< nuevaPosicion.x<<"x ,"<<nuevaPosicion.y<<"y"<< endl;
           // cout <<"v contenido en vPosiciones_xy error =  "<< celda.x<<"x ,"<<celda.y<<"y"<< endl;
        }
    }
    return false;
}



void Pac_Man::MovePM(int num_direction) {

    if (num_direction == 0) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},vPosicionCelda_xy, {0, -30}) == true) {
            spr_PacMan->move(0, -30);
            spr_PacMan->setRotation(270.0);
            spr_PacMan->setScale(1.0f, 1.0f);
        }
    }

    if (num_direction == 1) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},vPosicionCelda_xy, {0, 30}) == true) {
            spr_PacMan->move(0, 30);
            spr_PacMan->setRotation(90.0);
            spr_PacMan->setScale(1.0f, 1.0f);
           // cout << "posicion pacman " << spr_PacMan->getPosition().x << "x ," << spr_PacMan->getPosition().y << "y"
                // << endl;
        }
    }

    if (num_direction == 2) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {-30, 0}) == true) {
            spr_PacMan->move(-30, 0);
            spr_PacMan->setRotation(180.0);
            spr_PacMan->setScale(1.0f, -1.0f);
        }
    }

    if (num_direction == 3) {
        if (PuedeMoverse({static_cast<int>(spr_PacMan->getPosition().x), static_cast<int>(spr_PacMan->getPosition().y)},
                         vPosicionCelda_xy, {30, 0}) == true) {
            spr_PacMan->move(30, 0);
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

void Pac_Man::SetNewPosition_PM(bool kill, vector<Vector2i> Posiciones, int num_celdas) {
    if (kill == false){
       int indice_posrandom = rand()% num_celdas;
       cout << indice_posrandom << "= num random 1"<<endl;
       spr_PacMan->setPosition(Posiciones[indice_posrandom].x,Posiciones[indice_posrandom].y);
    }
}






