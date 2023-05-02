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
    void MovePM(int num_direction, bool move);
    void SetFrame( int num_frame);

private:
    Sprite *spr_PacMan;
    Texture *txtr_PacMan;


};


#endif //PAC_MAN_PAC_MAN_H
