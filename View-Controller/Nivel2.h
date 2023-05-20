//
// Created by yonathanms on 19/05/23.
//

#ifndef PAC_MAN_NIVEL2_H
#include "SFML/Graphics.hpp"
#include "../View-Controller/Pac_Man.h"
#include "../View-Controller/Fantasma1.h"
#include "vector"
#define PAC_MAN_NIVEL2_H

using namespace sf;

class Nivel2: public Pac_Man, public Fantasma1 {

public:

    Nivel2(int puntos_obtenidos);
    void Renderizar();
    void Ciclar();
    void Eventos();
    void Colisiones();
    void SetFramePU(int num_frames);
    void Power_up(bool mostrar);
    void Poder_Activo(bool poderactivo);
    void Direccion_MovePacMan(int num_direction);

private:
    RenderWindow *Vtn_Nivel1;
    Event *events;

    Time *tiempoFramePU;
    Clock *relojFramePU;
    Time *tiempoPoderactivo;
    Clock *relojPoderactivo;
    Clock *reloj_spawnFtsm;
    Time *tiempo_movePM;
    Clock *reloj_movePM;


    Sprite *sprt_fondoV1;
    Texture *txtr_fondoV1;

    Sprite *sprt_punto1;
    Texture *txtr_punto1;

    Sprite *sprt_PM_vidas;
    Texture *txtr_PM_vidas;

    Sprite *sprt_PowerUp;
    Texture *txtr_PowerUp;

    Font *fuente;
    Text *txt_Puntajetxt;
    Text *txt_Puntajeint;
    Text *txt_Vidastxt;
    Text *txt_Vidasint;

    Vector2f coord_posFtsm1;

    vector <Sprite> vSprites;
    vector <Vector2i> vPosiciones_puntos;
    vector <Vector2i> vPosiciones_celdas;
    vector <int> vPosicion_punto_x;
    vector <int> vPosicion_punto_y;
    vector <int> vPosicion_celda_x;
    vector <int> vPosicion_celda_y;
    vector <int> vPos_xPU;
    vector <int> vPos_yPU;

    int num_direccionPM;
    int num_validarmovimientoPM;
    int indice_posicion;
    int num_puntuacion_total;
    int num_framePM;
    int num_framePU;
    int pos_xPU;
    int pos_yPU;
    int indice_randomSpawnFtsm1;
    int num_comparacionPU;
    bool MostrarPU;
    bool VulnerabilidadFtsm1;
    bool Tiempo_SpawnFtsm1;
};



#endif //PAC_MAN_NIVEL2_H
