//
// Created by yonathanms on 28/04/23.
//

#ifndef PAC_MAN_PAC_MAN_H
#include "cmath"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "numeric"
#include "vector"
#define PAC_MAN_PAC_MAN_H

using namespace sf;
using namespace std;

class Pac_Man {
public:
    Pac_Man();
    Sprite GetSprPacman();
    void SetFrame( int num_frame);
    void MovePM(int num_direction);

private:
    Sprite *spr_PacMan;
    Texture *txtr_PacMan;

    vector <int> vPosicionCelda_x;
    vector <int> vPosicionCelda_y;
    vector <Vector2i> vPosicionCelda_xy;
   // Vector2f vectorPosActualPM;

   int indicevPos_xy;
};


#endif //PAC_MAN_PAC_MAN_H
