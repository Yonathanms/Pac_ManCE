//
// Created by yonathanms on 28/04/23.
//

#ifndef PAC_MAN_PAC_MAN_H
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
    Vector2f GetPosPacman();
    void MovePM(int num_direction, bool move);
    bool ValidarExistencia(Vector2f pos);
    void SetFrame( int num_frame);
    void MovePM2(int num_direction, Vector2f posPMxs);

private:
    Sprite *spr_PacMan;
    Texture *txtr_PacMan;

    vector <int> vPosicionCelda_x;
    vector <int> vPosicionCelda_y;
    vector <Vector2f> vPosicionCelda_xy;
   // Vector2f vectorPosActualPM;

   int indicevPos_xy;
};


#endif //PAC_MAN_PAC_MAN_H
