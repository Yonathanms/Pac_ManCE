//
// Created by yonathanms on 19/05/23.
//

#include "../View-Controller/Nivel2.h"

Nivel2::Nivel2(int puntos_obtenidos) {
    Vtn_Nivel1 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel1->setFramerateLimit(60);

    tiempo_movePM = new Time;
    reloj_movePM = new Clock;
    tiempoFramePU = new Time;
    relojFramePU = new Clock;
    tiempoPoderactivo = new Time;
    relojPoderactivo = new Clock;
    reloj_spawnFtsm = new Clock;

    num_puntuacion_total = 0;

    events = new Event;

    txtr_PowerUp = new Texture;
    sprt_PowerUp = new Sprite;
    txtr_PowerUp->loadFromFile("../Recursos/powerup1.png");
    sprt_PowerUp->setTexture(*txtr_PowerUp);
    sprt_PowerUp->setPosition(-146,-230);
    sprt_PowerUp->setOrigin(17,17);

    txtr_PM_vidas = new Texture;
    sprt_PM_vidas = new Sprite;
    txtr_PM_vidas->loadFromFile("../Recursos/PacManKill.png");
    sprt_PM_vidas->setTexture(*txtr_PM_vidas);
    sprt_PM_vidas->setPosition(695,14);



    txtr_fondoV1 = new Texture;
    sprt_fondoV1 = new Sprite;
    txtr_fondoV1->loadFromFile("../Recursos/FondoVtn1.png");
    sprt_fondoV1->setTexture(*txtr_fondoV1);
    sprt_fondoV1->setPosition(52,57);

    sprt_punto1 = new Sprite;
    txtr_punto1 = new Texture;
    txtr_punto1->loadFromFile("../Recursos/punto.png");
    sprt_punto1->setTexture(*txtr_punto1);
    sprt_punto1->setOrigin(10.0,10.0);

    fuente = new Font();
    fuente->loadFromFile("../Recursos/DSChocolade.ttf");

    txt_Puntajetxt = new Text;
    txt_Puntajetxt->setFont(*fuente);
    txt_Puntajetxt->setString("Puntaje:");
    txt_Puntajetxt->setPosition(160,10);
    txt_Puntajetxt->setLetterSpacing(1.5);
    txt_Puntajetxt->setScale(1.2,1.2);

    txt_Puntajeint = new Text;
    txt_Puntajeint->setFont(*fuente);
    txt_Puntajeint->setString(to_string(num_puntuacion_total));
    txt_Puntajeint->setPosition(320,10);
    txt_Puntajeint->setLetterSpacing(2);
    txt_Puntajeint->setScale(1.2 , 1.2);
    txt_Puntajeint->setFillColor(Color :: Yellow);

    txt_Vidastxt = new Text;
    txt_Vidastxt->setFont(*fuente);
    txt_Vidastxt->setString("Vidas:");
    txt_Vidastxt->setPosition(500,10);
    txt_Vidastxt->setLetterSpacing(1.5);
    txt_Vidastxt->setScale(1.2,1.2);

    txt_Vidasint = new Text;
    txt_Vidasint->setFont(*fuente);
    txt_Vidasint->setString(to_string(Get_NumVidasPM()) + " x");
    txt_Vidasint->setPosition(620,10);
    txt_Vidasint->setLetterSpacing(1.5);
    txt_Vidasint->setScale(1.2,1.2);
    txt_Vidasint->setFillColor(Color :: Yellow);

    MostrarPU = false;
    VulnerabilidadFtsm1 = false;
    Tiempo_SpawnFtsm1 = false;
    num_framePM = 0;
    num_framePU = 0;
    num_comparacionPU = 0;
    indice_randomSpawnFtsm1 = 0;
    indice_posicion = 0;
    coord_posFtsm1 = {-20.0,-20.0};
    vPos_xPU = {0,25};
    vPos_yPU = {0,28};

    vSprites = {252,*sprt_punto1};

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vPosicion_punto_x = {1,2,3,4,5,6,7,8,9,10,11,14,15,16,17,18,19,20,21,22,23,24,0,5,11,14,20,25,
                         0,5,11,14,20,25,0,5,11,14,20,25,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                         17,18,19,20,21,22,23,24,25,0,5,8,17,20,25,0,5,8,17,20,25,0,1,2,3,4,5,8,9,
                         10,11,14,15,16,17,20,21,22,23,24,25,5,20,5,20,5,20,5,20,5,20,0,1,2,3,4,5,
                         20,21,22,23,24,25,5,20,5,20,5,20,5,20,5,20,0,1,2,3,4,5,6,7,8,9,10,11,14,15,
                         16,17,18,19,20,21,22,23,24,25,0,5,11,14,20,25,0,5,11,14,20,25,0,1,2,5,6,7,8,
                         9,10,11,12,13,14,15,16,17,18,19,20,23,24,25,2,5,8,17,20,23,2,5,8,17,20,23,
                         0,1,2,3,4,5,8,9,10,11,14,15,16,17,20,21,22,23,24,25,0,11,14,25,0,11,14,25,
                         1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};  ///representan las columnas donde apareceran los puntos

    vPosicion_punto_y = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28}; ///representan las filas donde apareceran los puntos

    while (vPosiciones_puntos.size() != 252){

        vPosiciones_puntos.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
        vPosicion_punto_x.erase(vPosicion_punto_x.begin());
        if (vPosicion_punto_x[0]>=vPosicion_punto_x[1]){
            vPosiciones_puntos.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
            vPosicion_punto_x.erase(vPosicion_punto_x.begin());
            vPosicion_punto_y.erase(vPosicion_punto_y.begin());
        }
    }

    ///////////
    vPosicion_celda_x = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
                         3,9,16,22,  3,9,16,22};
    ///celda y
    vPosicion_celda_y = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    ///celdas x y y
    while (vPosiciones_celdas.size() != 306){
        vPosiciones_celdas.push_back({98+30*vPosicion_celda_x[0] ,103+30*vPosicion_celda_y[0]});
        vPosicion_celda_x.erase(vPosicion_celda_x.begin());
        if (vPosicion_celda_x[0]>=vPosicion_celda_x[1]){
            vPosiciones_celdas.push_back({98+30*vPosicion_celda_x[0] ,103+30*vPosicion_celda_y[0]});
            vPosicion_celda_x.erase(vPosicion_celda_x.begin());
            vPosicion_celda_y.erase(vPosicion_celda_y.begin());
        }
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    SetCeldasPosicionesFtsm1(vPosiciones_celdas);
    SetCeldasPosiciones(vPosiciones_celdas);
    Ciclar();

}

void Nivel2::Renderizar() {

}

void Nivel2::Ciclar() {

}

void Nivel2::Eventos() {

}

void Nivel2::Colisiones() {

}

void Nivel2::SetFramePU(int num_frames) {

}

void Nivel2::Power_up(bool mostrar) {

}

void Nivel2::Poder_Activo(bool poderactivo) {

}

void Nivel2::Direccion_MovePacMan(int num_direction) {

}
