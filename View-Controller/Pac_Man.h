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
    bool PuedeMoverse(const Vector2i &posicionActual, const vector<Vector2i> &celdasPermitidas, Vector2i coordenadas_move);
    int Reduccion_VidasPM(bool defensa);
    int Get_NumVidasPM();
    void SetNewPosition_PM(bool kill);
    void SetCeldasPosiciones(vector<Vector2i> celdas);

private:
    Sprite *spr_PacMan;
    Texture *txtr_PacMan;
    vector <Vector2i> vPosicionCelda_xy;

    int num_vidasPM;

};


#endif //PAC_MAN_PAC_MAN_H
