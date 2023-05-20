//
// Created by yonathanms on 19/05/23.
//

#include <iostream>
#include "../View-Controller/Nivel2.h"


Nivel2::Nivel2(int puntaje_obtenido) {
    /// funcionando
    Vtn_Nivel2 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel2->setFramerateLimit(60);

    tiempo_movePM = new Time;
    reloj_movePM = new Clock;
    tiempoFramePU = new Time;
    relojFramePU = new Clock;
    tiempoPoderactivo = new Time;
    relojPoderactivo = new Clock;
    reloj_spawnFtsm = new Clock;

    num_puntuacion_total = puntaje_obtenido;

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
    txtr_fondoV1->loadFromFile("../Recursos/FondoVtn2.png");
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
    VulnerabilidadFtsm = false;
    Tiempo_SpawnFtsm1 = false;
    Tiempo_SpawnFtsm2 = false;
    num_framePM = 0;
    num_framePU = 0;
    num_comparacionPU = 0;
    indice_randomSpawnFtsm1 = 0;
    coord_posFtsm1 = {-20.0,-20.0};
    coord_posFtsm2 = {-20.0,-20.0};

    vSprites = {200,*sprt_punto1};

    vPosicion_punto_x = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
                         3,9,16,22,  3,9,16,22,  3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
                         21,22,  3,5,10,15,20,22,  0,1,2,3,5,10,15,20,22,23,24,25,  3,5,10,15,20,
                         22,  3,5,6,7,18,19,20,22,  3,5,20,22,  3,5,20,22,  3,5,20,22,  3,5,20,22,
                         3,5,20,22,
                         3,5,20,22,
                         3,5,8,17,20,22,
                         3,5,8,17,20,22,
                         3,5,8,17,20,22,
                         0,1,2,3,5,8,9,10,11,12,13,14,15,16,17,20,22,23,24,25,
                         3,5,8,11,14,17,20,22,
                         3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,
                         3,5,7,18,20,22,
                         3,5,7,18,20,22,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};  ///representan las columnas donde apareceran los puntos


    vPosicion_punto_y = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};  ///representan las filas donde apareceran los puntos

    while (vPosiciones_puntos.size() != 200){

        vPosiciones_puntos.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
        vPosicion_punto_x.erase(vPosicion_punto_x.begin());
        if (vPosicion_punto_x[0]>=vPosicion_punto_x[1]){
            vPosiciones_puntos.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
            vPosicion_punto_x.erase(vPosicion_punto_x.begin());
            vPosicion_punto_y.erase(vPosicion_punto_y.begin());
        }
    }

    ///////////
    vPosicion_celda_x = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,3,9,16,22,3,9,16,22,
                         3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
                         3,5,10,15,20,22,0,1,2,3,5,10,15,20,22,23,24,25,
                         3,5,10,15,20,22,
                         3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,  3,5,8,12,13,17,20,22,
                         3,5,8,12,13,17,20,22,3,5,8,12,13,17,20,22,
                         3,5,8,12,13,17,20,22,3,5,8,17,20,22,3,5,8,9,10,11,12,13,14,15,16,17,20,22,3,5,8,17,20,22,5,8,17,20,22,3,5,8,17,20,22,
                         0,1,2,3,5,8,9,10,11,12,13,14,15,16,17,20,22,23,24,25,
                         3,5,8,11,14,17,20,22,
                         3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,
                         3,5,7,18,20,22,
                         3,5,7,18,20,22,
                         3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    //celda y
    vPosicion_celda_y = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    //celdas x y y
    while (vPosiciones_celdas.size() != 237){
        vPosiciones_celdas.push_back({98+30*vPosicion_celda_x[0] ,103+30*vPosicion_celda_y[0]});
        vPosicion_celda_x.erase(vPosicion_celda_x.begin());
        // cout << vPosicionCelda_xy[0].x<<vPosicionCelda_xy[0].y << endl;
        if (vPosicion_celda_x[0]>=vPosicion_celda_x[1]){
            vPosiciones_celdas.push_back({98+30*vPosicion_celda_x[0] ,103+30*vPosicion_celda_y[0]});
            vPosicion_celda_x.erase(vPosicion_celda_x.begin());
            vPosicion_celda_y.erase(vPosicion_celda_y.begin());
        }
    }

    //////////


    vPos_xPU = {3,22};
    vPos_yPU = {3,25};
    indice_posicion = 0;


    /// posiciona todos los puntos del mapa con el vector de posiciones
    for (auto& sprt_punto1 : vSprites ){
        if(indice_posicion<200){
            sprt_punto1.setPosition(vPosiciones_puntos[indice_posicion].x,vPosiciones_puntos[indice_posicion].y);
            indice_posicion += 1;
        }
    }
    SetCeldasPosicionesFtsm2(vPosiciones_celdas);
    SetCeldasPosicionesFtsm1(vPosiciones_celdas);
    SetCeldasPosiciones(vPosiciones_celdas);
    Ciclar();

}

void Nivel2::Renderizar() {
    Vtn_Nivel2->clear();

    Vtn_Nivel2->draw(*sprt_fondoV1);


    for (auto& sprt_punto1 : vSprites){
        Vtn_Nivel2->draw(sprt_punto1);
    }

    Vtn_Nivel2->draw(*txt_Puntajetxt);
    Vtn_Nivel2->draw(*txt_Puntajeint);
    Vtn_Nivel2->draw(*txt_Vidastxt);
    Vtn_Nivel2->draw(*sprt_PowerUp);
    Vtn_Nivel2->draw(*txt_Vidasint);
    Vtn_Nivel2->draw(*sprt_PM_vidas);
    Vtn_Nivel2->draw(GetFtsm1());
    Vtn_Nivel2->draw(GetFtsm2());
    Vtn_Nivel2->draw(GetSprt_killFtsm1());
    Vtn_Nivel2->draw(GetSprt_killFtsm2());
    Vtn_Nivel2->draw(GetSprPacman());


    Vtn_Nivel2->display();
}

void Nivel2::Ciclar() {
    while (Vtn_Nivel2->isOpen()){
        Colisiones();
        Eventos();
        MovePM(num_direccionPM);

        *tiempo_movePM = reloj_movePM->getElapsedTime();
        if (tiempo_movePM->asMilliseconds() > 40) {
            SetFrame(num_framePM);
            num_framePM++;
            if (num_framePM == 5) {
                num_framePM = 0;
            }
        }if(tiempo_movePM->asMilliseconds() > 41){
            reloj_movePM->restart();
        }
        Direccion_MovePacMan(num_validarmovimientoPM);
        SetFramePU(num_framePU);
        Power_up(MostrarPU);
        SetFrameFtsm1(VulnerabilidadFtsm);
        SetFrameFtsm2(VulnerabilidadFtsm);
        Poder_Activo(VulnerabilidadFtsm);
        RespawnFtsm1(Tiempo_SpawnFtsm1,*reloj_spawnFtsm, coord_posFtsm1 ,indice_randomSpawnFtsm1 );
        RespawnFtsm2(Tiempo_SpawnFtsm2,*reloj_spawnFtsm2, coord_posFtsm1, indice_randomSpawnFtsm2);
        MoveFtsm1(false, GetSprPacman().getPosition());
        MoveFtsm2(false, GetSprPacman().getPosition());
        Renderizar();
        txt_Vidasint->setString(to_string(Get_NumVidasPM()) + " x"); ///actualiza el numero de vidas



    }
}

void Nivel2::Eventos() {
    while (Vtn_Nivel2->pollEvent(*events)) {
        switch (events->type) {
            case Event::Closed:
                Vtn_Nivel2->close();
                cout << "Ventana facil cerrada de forma exitosa" << endl;
                exit(1);

            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::W)) {
                    num_validarmovimientoPM = 0;
                }
                else if (Keyboard::isKeyPressed(Keyboard::S)){
                    num_validarmovimientoPM = 1;
                }
                else if (Keyboard::isKeyPressed(Keyboard::A)) {
                    num_validarmovimientoPM = 2;
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)){
                    num_validarmovimientoPM = 3;
                }
        }
    }
}

void Nivel2::Colisiones() {

    /// funcion que elimina los puntos del vector segun el pacman los va comiendo, una vez no hayan puntos en el mapa, termina el nivel
    for (int i = 0; i < vSprites.size(); ++i) {
        if (GetSprPacman().getGlobalBounds().intersects(vSprites[i].getGlobalBounds())) {

            if(vSprites.size()>0){
                num_comparacionPU+=10;
                vSprites.erase(vSprites.begin() + i);
                txt_Puntajeint->setString(to_string(num_puntuacion_total+=10));

                if (num_comparacionPU==200){
                    pos_xPU = rand() % 2-0;
                    pos_yPU = rand() % 2-0;
                    MostrarPU = true;
                }

                if(num_comparacionPU>200){
                    MostrarPU = true;
                }
            }

            if (vSprites.size() == 0){
                cout<< "Ventana cerrada con exito" <<endl;
                Vtn_Nivel2->close();
            }
        }
    }

    if (GetSprPacman().getGlobalBounds().intersects(sprt_PowerUp->getGlobalBounds())){
        MostrarPU = false;
        VulnerabilidadFtsm = true;
        num_comparacionPU = 0;
        relojPoderactivo->restart();


    }
    ////////// esta funcion determina lo que sucede si interaccionan el pacman y el fantasma
    if (GetSprPacman().getGlobalBounds().intersects((GetFtsm1().getGlobalBounds()))){
        if(VulnerabilidadFtsm == false){
            if(Reduccion_VidasPM(VulnerabilidadFtsm) > 0){
                cout << "xd"<<endl;
                SetNewPosition_PM(VulnerabilidadFtsm);
            } else{
                cout<< "GAME OVER"<<endl;
                Vtn_Nivel2->close();
            }
        }else{
            num_comparacionPU+=50;
            txt_Puntajeint->setString(to_string(num_puntuacion_total+=50));
            Tiempo_SpawnFtsm1 = true;
            reloj_spawnFtsm->restart();
            indice_randomSpawnFtsm1= rand()% vPosiciones_puntos.size();
            coord_posFtsm1 = {GetFtsm1().getPosition().x,GetFtsm1().getPosition().y};
            RespawnFtsm1(Tiempo_SpawnFtsm1,*reloj_spawnFtsm, coord_posFtsm1 , indice_randomSpawnFtsm1);
            cout<<"Totalmente inmune" << endl;
        }
    }

    ////////// esta funcion determina lo que sucede si interaccionan el pacman y el fantasma2
    if (GetSprPacman().getGlobalBounds().intersects((GetFtsm2().getGlobalBounds()))){
        if(VulnerabilidadFtsm == false){
            if(Reduccion_VidasPM(VulnerabilidadFtsm) > 0){
                cout << "xd"<<endl;
                SetNewPosition_PM(VulnerabilidadFtsm);
            } else{
                cout<< "GAME OVER"<<endl;
                Vtn_Nivel2->close();
            }
        }else{
            num_comparacionPU+=50;
            txt_Puntajeint->setString(to_string(num_puntuacion_total+=50));
            Tiempo_SpawnFtsm2 = true;
            reloj_spawnFtsm2->restart();
            indice_randomSpawnFtsm2= rand()% vPosiciones_puntos.size();
            coord_posFtsm2 = {GetFtsm2().getPosition().x,GetFtsm2().getPosition().y};
            RespawnFtsm2(Tiempo_SpawnFtsm2,*reloj_spawnFtsm2, coord_posFtsm2 , indice_randomSpawnFtsm2);
            cout<<"Totalmente inmune" << endl;
        }
    }
}


///esta funcion recorre los sprites del power up y lo actualiza por tiempo definido
void Nivel2::SetFramePU(int num_frames) {
    *tiempoFramePU = relojFramePU->getElapsedTime();
    if (num_frames <= 8){
        if (num_frames<8){

            if(tiempoFramePU->asMilliseconds()<36 and tiempoFramePU->asMilliseconds() > 17.0){
                IntRect coordenadas(num_frames*33.75,0,33.75,33.75);
                num_framePU++;
                sprt_PowerUp->setTextureRect(coordenadas);
            }
            if(tiempoFramePU->asMilliseconds()>36.1){
                relojFramePU->restart();
            }
        } else{
            num_framePU = 0;
        }
    }
}

/// oculta y mestra el sprite del power up
void Nivel2::Power_up(bool mostrar) {
    if (mostrar == false){
        sprt_PowerUp->setPosition(-100,-100);
    }else{
        sprt_PowerUp->setPosition({static_cast<float>(98+30*vPos_xPU[pos_xPU]),static_cast<float>(103+30*vPos_yPU[pos_yPU])});
    }
}

/// Mantiene el poder de comer fantasmas por un tiempo establecido
void Nivel2::Poder_Activo(bool poderactivo) {
    if(poderactivo== true){
        *tiempoPoderactivo = relojPoderactivo->getElapsedTime();
        if (tiempoPoderactivo->asSeconds()>=10){
            VulnerabilidadFtsm = false;
        }
    }
}

void Nivel2::Direccion_MovePacMan(int num_direction) {
    if (num_direction == 0){
        Vector2i coordenadas_move = {0,-5};
        Vector2i nuevaPosicion = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*1};
        Vector2i nuevaPosicion2 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*2};
        Vector2i nuevaPosicion3 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*3};
        Vector2i nuevaPosicion4 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*4};
        Vector2i nuevaPosicion5 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*5};
        Vector2i nuevaPosicion6 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*6};

        for (const auto& celda : vPosiciones_celdas){
            if (nuevaPosicion == celda or nuevaPosicion2 == celda or nuevaPosicion3 == celda or nuevaPosicion4 == celda or nuevaPosicion5 == celda or nuevaPosicion6 == celda){
                num_direccionPM = 0;
            }
        }
    }
    if (num_direction == 1){
        Vector2i coordenadas_move = {0,5};
        Vector2i nuevaPosicion = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*1};
        Vector2i nuevaPosicion2 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*2};
        Vector2i nuevaPosicion3 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*3};
        Vector2i nuevaPosicion4 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*4};
        Vector2i nuevaPosicion5 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*5};
        Vector2i nuevaPosicion6 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*6};

        for (const auto& celda : vPosiciones_celdas){
            if (nuevaPosicion == celda or nuevaPosicion2 == celda or nuevaPosicion3 == celda or nuevaPosicion4 == celda or nuevaPosicion5 == celda or nuevaPosicion6 == celda){
                num_direccionPM = 1;
            }
        }
    }
    if (num_direction == 2){
        Vector2i coordenadas_move = {-5,0};
        Vector2i nuevaPosicion = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*1};
        Vector2i nuevaPosicion2 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*2,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*2};
        Vector2i nuevaPosicion3 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*3,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*3};
        Vector2i nuevaPosicion4 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*4,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*4};
        Vector2i nuevaPosicion5 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*5,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*5};
        Vector2i nuevaPosicion6 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*6,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*6};

        for (const auto& celda : vPosiciones_celdas){
            if (nuevaPosicion == celda or nuevaPosicion2 == celda or nuevaPosicion3 == celda or nuevaPosicion4 == celda or nuevaPosicion5 == celda or nuevaPosicion6 == celda){
                num_direccionPM = 2;
            }
        }
    }
    if (num_direction == 3){
        Vector2i coordenadas_move = {5,0};
        Vector2i nuevaPosicion = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*1,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*1};
        Vector2i nuevaPosicion2 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*2,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*2};
        Vector2i nuevaPosicion3 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*3,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*3};
        Vector2i nuevaPosicion4 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*4,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*4};
        Vector2i nuevaPosicion5 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*5,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*5};
        Vector2i nuevaPosicion6 = {static_cast<int>(GetSprPacman().getPosition().x) + coordenadas_move.x*6,static_cast<int>(GetSprPacman().getPosition().y) + coordenadas_move.y*6};

        for (const auto& celda : vPosiciones_celdas){
            if (nuevaPosicion == celda or nuevaPosicion2 == celda or nuevaPosicion3 == celda or nuevaPosicion4 == celda or nuevaPosicion5 == celda or nuevaPosicion6 == celda){
                num_direccionPM = 3;
            }
        }
    }
}
