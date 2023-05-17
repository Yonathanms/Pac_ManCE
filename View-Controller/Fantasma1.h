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
    void RespawnFtsm1(bool kill_ftsm, Vector2i PosFtsm, vector <Vector2i> PosCeldas, int num_celdas);
private:

    Time *tiempo_FrameFtsm1;
    Clock *reloj_FrameFtsm1;

    Time *tiempo_spawnFtsm1;
    Clock *reloj_spawnFtsm1;

    Sprite *sprt_ftsm1;
    Texture *txtr_ftsm1;

    Sprite *sprt_killftsm1;
    Texture *txtr_killftsm1;

    int num_frameFtsm1;

};


#endif //PAC_MAN_FANTASMA1_H
