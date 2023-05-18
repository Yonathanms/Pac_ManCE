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
    Sprite GetSprt_killFtsm1();
    void  SetFrameFtsm1(bool vulnerabilidad);
    void RespawnFtsm1(bool Ftsm_herido,Clock relojinicial,Vector2f coord_posFtsm1,  int num_random);
    void SetCeldasPosicionesFtsm1(vector<Vector2i> celdas);
    void MoveFtsm1(bool PU_activo, Vector2f posPM);
    bool PuedeMoverse(const Vector2i &posicionActual, const vector<Vector2i> &celdasPermitidas, Vector2i coordenadas_move);
private:

    Time *tiempo_FrameFtsm1;
    Clock *reloj_FrameFtsm1;

    Time *tiempo_spawnFtsm1;

    Sprite *sprt_ftsm1;
    Texture *txtr_ftsm1;

    Sprite *sprt_killftsm1;
    Texture *txtr_killftsm1;

    vector <Vector2i> vPosicionesCelda_xy;
    int num_frameFtsm1;
    int direccion_move;

};


#endif //PAC_MAN_FANTASMA1_H
