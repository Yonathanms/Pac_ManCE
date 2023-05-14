//
// Created by yonathanms on 28/04/23.
//

#include "../View-Controller/Pac_Man.h"

Pac_Man::Pac_Man() {
    spr_PacMan = new Sprite;
    txtr_PacMan = new Texture;

    txtr_PacMan->loadFromFile("../Recursos/FramesPacman.png");
    spr_PacMan->setTexture(*txtr_PacMan);
    spr_PacMan->setPosition(472,596);
    spr_PacMan->setOrigin(20.0,20.0);

    SetFrame(0);


}

Sprite Pac_Man::GetSprPacman() {
    return *spr_PacMan;
}

void Pac_Man::MovePM(int num_direction, bool move) {
    if (num_direction == 0 and move == true) {
        spr_PacMan->move(0.0, -8.0);
        spr_PacMan->setRotation(270.0);
        spr_PacMan->setScale(1.0f, 1.0f);
       // cout << "x= " << spr_PacMan->getPosition().x<< endl;
        //cout << "y= " << spr_PacMan->getPosition().y<< endl;
    }

    if (num_direction == 1 and move == true) {
        spr_PacMan->move(0.0, 8.0);
        spr_PacMan->setRotation(90.0);
        spr_PacMan->setScale(1.0f, 1.0f);
       // cout << "x= " << spr_PacMan->getPosition().x<< endl;
        //cout << "y= " << spr_PacMan->getPosition().y<< endl;
    }

    if (num_direction == 2 and move == true) {
        spr_PacMan->move(-8.0, 0.0);
        spr_PacMan->setRotation(180.0);
        spr_PacMan->setScale(1.0f, -1.0f);
       // cout << "x= " << spr_PacMan->getPosition().x<< endl;
       // cout << "y= " << spr_PacMan->getPosition().y<< endl;
    }

    if (num_direction == 3 and move == true) {
        spr_PacMan->move(8.0, 0.0);
        spr_PacMan->setRotation(0.0);
        spr_PacMan->setScale(1.0f, 1.0f);
        //cout << "x= " << spr_PacMan->getPosition().x<< endl;
       // cout << "y= " << spr_PacMan->getPosition().y<< endl;
    }

    if (move == false){
        if (num_direction == 0 or num_direction == 1 or num_direction == 2 or num_direction == 3) {
            if (num_direction == 0) {
                spr_PacMan->move(0.0, +10.0);
            }
            if(num_direction == 1){
                spr_PacMan->move(0.0, -10.0);
            }
            if(num_direction == 2){
                spr_PacMan->move(+10.0, 0.0);
            }
            if(num_direction == 3){
                spr_PacMan->move(-10.0, 0.0);
            }
        }
    }
}

///metodo que divide es sprite del pacman en sprites mas pequenos
void Pac_Man::SetFrame( int num_frame) {
    IntRect coordenadas(num_frame*40,0,40,40);
    spr_PacMan->setTextureRect(coordenadas);
}


