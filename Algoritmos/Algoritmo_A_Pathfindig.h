//
// Created by yonathanms on 19/05/23.
//

#ifndef PAC_MAN_ALGORITMO_A_PATHFINDIG_H
#include "iostream"
#include "SFML/Graphics.hpp"
#include "vector"
#define PAC_MAN_ALGORITMO_A_PATHFINDIG_H

using namespace std;
using namespace sf;

class Algoritmo_A_Pathfindig {
public:
    Algoritmo_A_Pathfindig();
    void Set_CeldasMapa (vector <Vector2i>  celdas_jugables);

private:

    struct atributos_de_celdas{
        int F;
        int H;
        int G;
    };

    vector <Vector2i> Celdas_Mapa;
    vector <int> Open_List;
    vector <int> Closed_List;
    vector <int> Ruta;

};


#endif //PAC_MAN_ALGORITMO_A_PATHFINDIG_H
