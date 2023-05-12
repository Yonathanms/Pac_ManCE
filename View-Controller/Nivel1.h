//
// Created by yonathanms on 25/04/23.
//

#ifndef PAC_MAN_NIVEL1_H
#include "SFML/Graphics.hpp"
#include "../View-Controller/Pac_Man.h"
#include "vector"
#define PAC_MAN_NIVEL1_H

using namespace sf;

class Nivel1: public Pac_Man{
public:
    Nivel1();
    void Renderizar();
    void Ciclar();
    void Eventos();
    void Colisiones();
    void barreras();
    void SetFramePU(int num_frames);



private:
    RenderWindow *Vtn_Nivel1;
    Event *events;

    Time *tiempoFramePU;
    Clock *relojFramePU;

    // Rectangulos de los muros
    RectangleShape *rctngl_Barrera1_1;
    RectangleShape *rctngl_Barrera1_2;
    RectangleShape *rctngl_Barrera1_3;
    RectangleShape *rctngl_Barrera1_4;
    RectangleShape *rctngl_Barrera1_5;
    RectangleShape *rctngl_Barrera1_6;
    RectangleShape *rctngl_Barrera1_7;
    RectangleShape *rctngl_Barrera1_8;
    RectangleShape *rctngl_Barrera1_9;
    RectangleShape *rctngl_Barrera1_10;
    RectangleShape *rctngl_Barrera1_11;
    RectangleShape *rctngl_Barrera1_12;
    RectangleShape *rctngl_Barrera1_13;
    RectangleShape *rctngl_Barrera1_14;
    RectangleShape *rctngl_Barrera1_15;
    RectangleShape *rctngl_Barrera1_16;
    RectangleShape *rctngl_Barrera1_17;
    RectangleShape *rctngl_Barrera1_18;
    RectangleShape *rctngl_Barrera1_19;
    RectangleShape *rctngl_Barrera1_20;
    RectangleShape *rctngl_Barrera1_21;
    RectangleShape *rctngl_Barrera1_22;
    RectangleShape *rctngl_Barrera1_23;
    RectangleShape *rctngl_Barrera1_24;
    RectangleShape *rctngl_Barrera1_25;
    RectangleShape *rctngl_Barrera1_26;
    RectangleShape *rctngl_Barrera1_27;
    RectangleShape *rctngl_Barrera1_28;
    RectangleShape *rctngl_Barrera1_29;
    RectangleShape *rctngl_Barrera1_30;
    RectangleShape *rctngl_Barrera1_31;
    RectangleShape *rctngl_Barrera1_32;
    RectangleShape *rctngl_Barrera1_33;
    RectangleShape *rctngl_Barrera1_34;
    RectangleShape *rctngl_Barrera1_35;
    RectangleShape *rctngl_Barrera1_36;
    RectangleShape *rctngl_Barrera1_37;
    RectangleShape *rctngl_Barrera1_38;
    RectangleShape *rctngl_Barrera1_39;
    RectangleShape *rctngl_Barrera1_40;
    RectangleShape *rctngl_Barrera1_41;
    RectangleShape *rctngl_Barrera1_42;
    RectangleShape *rctngl_Barrera1_43;
    RectangleShape *rctngl_Barrera1_44;
    RectangleShape *rctngl_Barrera1_45;
    RectangleShape *rctngl_Barrera1_46;
    RectangleShape *rctngl_Barrera1_47;
    RectangleShape *rctngl_Barrera1_48;
    RectangleShape *rctngl_Barrera1_49;
    RectangleShape *rctngl_Barrera1_50;
    RectangleShape *rctngl_Barrera1_51;
    RectangleShape *rctngl_Barrera1_52;
    RectangleShape *rctngl_Barrera1_53;
    RectangleShape *rctngl_Barrera1_54;
    RectangleShape *rctngl_Barrera1_55;
    RectangleShape *rctngl_Barrera1_56;
    RectangleShape *rctngl_Barrera1_57;


    //----------
    Sprite *sprt_fondoV1;
    Texture *txtr_fondoV1;

    Sprite *sprt_punto1;
    Texture *txtr_punto1;

    Sprite *sprt_PM_vidas1;
    Sprite *sprt_PM_vidas2;
    Sprite *sprt_PM_vidas3;

    Sprite *sprt_PowerUp;
    Texture *txtr_PowerUp;

    Font *fuente;
    Text *txt_Puntajetxt;
    Text *txt_Puntajeint;

    vector <Sprite> vSprites;
    vector <Vector2f> vPosiciones;
    vector <int> vPosicion_punto_x;
    vector <int> vPosicion_punto_y;

    int indice_posicion;
    int num_puntuacion_total;
    int num_framePM;
    int num_framePU;
    bool movePM;
};


#endif //PAC_MAN_NIVEL1_H
