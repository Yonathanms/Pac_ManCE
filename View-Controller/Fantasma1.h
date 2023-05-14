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
    void  SetFrameFtsm1(bool vulnerabilidad);
private:

    Time *tiempo_FrameFtsm1;
    Clock *reloj_FrameFtsm1;

    Sprite *sprt_ftsm1;
    Texture *txtr_ftsm1;

    int num_frameFtsm1;

};


#endif //PAC_MAN_FANTASMA1_H
