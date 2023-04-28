//
// Created by yonathanms on 25/04/23.
//

#ifndef PAC_MAN_VENTANA_PRINCIPAL_H
#include "SFML/Graphics.hpp"
#include "iostream"
#define PAC_MAN_VENTANA_PRINCIPAL_H

using namespace sf;


class Ventana_Principal {

public:
    Ventana_Principal();
    void Eventos();
    void Ciclar();
    void Renderizar();
private:
    RenderWindow *VentanaPrincipal;
    Event *events;

    RectangleShape *btnJugar;


};


#endif //PAC_MAN_VENTANA_PRINCIPAL_H
