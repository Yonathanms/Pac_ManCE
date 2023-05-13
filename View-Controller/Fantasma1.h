//
// Created by yonathanms on 12/05/23.
//

#ifndef PAC_MAN_FANTASMA1_H
#include "SFML/Graphics.hpp"
#include "iostream"
#include "numeric"
#include "vector"
#define PAC_MAN_FANTASMA1_H

using namespace sf;
using namespace std;

class Fantasma1 {
public:
    Fantasma1();
    Sprite GetFtsm1();
private:

    Sprite *sprt_ftsm1;
    Texture *txtr_ftsm1;

};


#endif //PAC_MAN_FANTASMA1_H
