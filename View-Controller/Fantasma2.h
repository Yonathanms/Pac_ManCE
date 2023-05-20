//
// Created by yonathanms on 19/05/23.
//

#ifndef PAC_MAN_FANTASMA2_H
#include "SFML/Graphics.hpp"
#include "iostream"
#include "numeric"
#include "vector"
#define PAC_MAN_FANTASMA2_H

using namespace sf;
using namespace std;

class Fantasma2 {
public:
    Fantasma2();
    Sprite GetFtsm2();
    Sprite GetSprt_killFtsm2();
    void  SetFrameFtsm2(bool vulnerabilidad);
    void RespawnFtsm2(bool Ftsm_herido,Clock relojinicial,Vector2f coord_posFtsm1,  int num_random);
    void SetCeldasPosicionesFtsm2(vector<Vector2i> celdas);
    void MoveFtsm2(bool PU_activo, Vector2f posPM);
    bool PuedeMoverseFtsm2(const Vector2i &posicionActual, const vector<Vector2i> &celdasPermitidas, Vector2i coordenadas_move);
private:

    Time *tiempo_FrameFtsm2;
    Clock *reloj_FrameFtsm2;

    Time *tiempo_spawnFtsm2;

    Sprite *sprt_ftsm2;
    Texture *txtr_ftsm2;

    Sprite *sprt_killftsm2;
    Texture *txtr_killftsm2;

    vector <Vector2i> vPosicionesCelda_xy;
    int num_frameFtsm2;
    int direccion_move;

};


#endif //PAC_MAN_FANTASMA2_H