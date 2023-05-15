//
// Created by yonathanms on 28/04/23.
//

#include "../View-Controller/Pac_Man.h"

Pac_Man::Pac_Man() {
    spr_PacMan = new Sprite;
    txtr_PacMan = new Texture;

    txtr_PacMan->loadFromFile("../Recursos/FramesPacman.png");
    spr_PacMan->setTexture(*txtr_PacMan);
    spr_PacMan->setPosition(174.8f,938.2f);
    spr_PacMan->setOrigin(20.0,20.0);

    ///posiciones donde se puede mover
    //celda x
    vPosicionCelda_x = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    //celda y
    vPosicionCelda_y = {10};
    //celdas x y y
    while (vPosicionCelda_xy.size() != 13){
        vPosicionCelda_x.erase(vPosicionCelda_x.begin());
        vPosicionCelda_xy.push_back({static_cast<float>(118+28.4*vPosicionCelda_x[0]) ,static_cast<float>(143+28.4*vPosicionCelda_y[0])});
        if (vPosicionCelda_x[0]>vPosicionCelda_x[1]){
            vPosicionCelda_y.erase(vPosicionCelda_y.begin());
        }

    }

    SetFrame(0);

    indicevPos_xy = 0;

   // for (int i = 0; i < vPosicionCelda_xy.size(); ++i) {
       // cout<<vPosicionCelda_xy[i].x<<","<<vPosicionCelda_xy[i].y<<endl;
    //}
}

Sprite Pac_Man::GetSprPacman() {
    return *spr_PacMan;
}



//void Pac_Man::MovePM(int num_direction, bool move) {
  //  if (num_direction == 0 and move == true) {
    //    spr_PacMan->move(0.0, -7.1);
      //  spr_PacMan->setRotation(270.0);
        //spr_PacMan->setScale(1.0f, 1.0f);
       // cout << "x= " << spr_PacMan->getPosition().x<< endl;
        //cout << "y= " << spr_PacMan->getPosition().y<< endl;
   // }

//    if (num_direction == 1 and move == true) {
  //      spr_PacMan->move(0.0, 7.1);
    //    spr_PacMan->setRotation(90.0);
      //  spr_PacMan->setScale(1.0f, 1.0f);
       // cout << "x= " << spr_PacMan->getPosition().x<< endl;
        //cout << "y= " << spr_PacMan->getPosition().y<< endl;
    //}

    //if (num_direction == 2 and move == true) {
      //  spr_PacMan->move(-7.1, 0.0);
        //spr_PacMan->setRotation(180.0);
        //spr_PacMan->setScale(1.0f, -1.0f);
        //cout << "x= " << spr_PacMan->getPosition().x<< endl;
       // cout << "y= " << spr_PacMan->getPosition().y<< endl;
    //}

    //if (num_direction == 3 and move == true) {
      //  spr_PacMan->move(7.1, 0.0);
        //spr_PacMan->setRotation(0.0);
        //spr_PacMan->setScale(1.0f, 1.0f);
        //cout << "x= " << spr_PacMan->getPosition().x<< endl;
       // cout << "y= " << spr_PacMan->getPosition().y<< endl;
    //}

    //if (move == false){
      //  if (num_direction == 0 or num_direction == 1 or num_direction == 2 or num_direction == 3) {
        //    if (num_direction == 0) {
               // spr_PacMan->move(0.0, +10.0);
          //  }
           // if(num_direction == 1){
             //   spr_PacMan->move(0.0, -10.0);
            //}
            //if(num_direction == 2){
              //  spr_PacMan->move(+10.0, 0.0);
            //}
            //if(num_direction == 3){
      //          spr_PacMan->move(-10.0, 0.0);
            //}
    //    }
  //  }
//}

///metodo que divide es sprite del pacman en sprites mas pequenos
void Pac_Man::SetFrame( int num_frame) {
    IntRect coordenadas(num_frame*40,0,40,40);
    spr_PacMan->setTextureRect(coordenadas);
}


void Pac_Man::MovePM2(int num_direction, Vector2f posPMxs) {
    if (num_direction==3){
        if(ValidarExistencia(posPMxs)== true){
            cout<<"se encontro la coordenada"<<endl;
            spr_PacMan->move(28.4f,0.0f);
        }
    }
}

bool Pac_Man::ValidarExistencia(Vector2f pos_PM) {
    for (const auto& vector : vPosicionCelda_xy) {
        if (vector.x - pos_PM.x >= 0.0f) {
            cout<<"Perro hijueputa"<<vPosicionCelda_xy[2].x<<endl;
            return true; // El Vector2f se encuentra en la lista
        }
    }
    cout<<GetPosPacman().x<<"cabron"<<endl;
    return false; // El Vector2f no se encuentra en la lista
}

Vector2f Pac_Man::GetPosPacman() {
    return spr_PacMan->getPosition();
}




