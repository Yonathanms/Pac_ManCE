//
// Created by yonathanms on 25/04/23.
//

#ifndef PAC_MAN_NIVEL1_H
#include "SFML/Graphics.hpp"
#include "../View-Controller/Pac_Man.h"
#include "../View-Controller/Fantasma1.h"
#include "vector"
#include "stdlib.h"
#define PAC_MAN_NIVEL1_H

using namespace sf;

class Nivel1: public Pac_Man, public Fantasma1{
public:
    Nivel1();
    void Renderizar();
    void Ciclar();
    void Eventos();
    void Colisiones();
    void SetFramePU(int num_frames);
    void Power_up(bool mostrar);
    void Poder_Activo(bool poderactivo);





private:
    RenderWindow *Vtn_Nivel1;
    Event *events;

    Time *tiempoFramePU;
    Clock *relojFramePU;
    Time *tiempoPoderactivo;
    Clock *relojPoderactivo;


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
    vector <Vector2i> vPosiciones;
    vector <int> vPosicion_punto_x;
    vector <int> vPosicion_punto_y;
    vector <int> vPos_xPU;
    vector <int> vPos_yPU;

    int indice_posicion;
    int num_puntuacion_total;
    int num_framePM;
    int num_framePU;
    int pos_xPU;
    int pos_yPU;
    int num_comparacionPU;
    bool movePM;
    bool MostrarPU;
    bool VulnerabilidadFtsm1;
};


#endif //PAC_MAN_NIVEL1_H
