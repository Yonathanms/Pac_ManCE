//
// Created by yonathanms on 19/05/23.
//

#include "Algoritmo_A_Pathfindig.h"

Algoritmo_A_Pathfindig::Algoritmo_A_Pathfindig() {

    Open_List.resize(10);

    for (int i = 0; i < 10; i++){
        atributos_de_celdas atributos;
        atributos.F = i;
        atributos.H = i +1;
        atributos.G = i -1;

      //  Open_List.push_back(atributos);
    }
//Open_List[0].F = 0;

}


