//
// Created by yonathanms on 25/04/23.
//

#include <iostream>
#include "../View-Controller/Nivel1.h"


Nivel1::Nivel1() {
    Vtn_Nivel1 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel1->setFramerateLimit(60);

    tiempoFramePU = new Time;
    relojFramePU = new Clock;
    tiempoPoderactivo = new Time;
    relojPoderactivo = new Clock;
    tiempo_spawnFtsm = new Time;
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
 //   sprt_PM_vidas->setOrigin(20,20);


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
    coord_posFtsm1 = {-20.0,-20.0};

    vSprites = {252,*sprt_punto1};

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

    while (vPosiciones.size() != 252){

      //vPosicion_punto_x.erase(vPosicion_punto_x.begin());
      vPosiciones.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
      vPosicion_punto_x.erase(vPosicion_punto_x.begin());
      if (vPosicion_punto_x[0]>=vPosicion_punto_x[1]){
          vPosiciones.push_back({98+30*vPosicion_punto_x[0] ,103+30*vPosicion_punto_y[0]});
          vPosicion_punto_x.erase(vPosicion_punto_x.begin());
          vPosicion_punto_y.erase(vPosicion_punto_y.begin());
          }
    }


    vPos_xPU = {0,25};
    vPos_yPU = {0,28};
    indice_posicion = 0;


    /// posiciona todos los puntos del mapa con el vector de posiciones
    for (auto& sprt_punto1 : vSprites ){
        if(indice_posicion<252){
            sprt_punto1.setPosition(vPosiciones[indice_posicion].x,vPosiciones[indice_posicion].y);
            indice_posicion += 1;
        }
    }

    Ciclar();

}

void Nivel1::Renderizar() {
    Vtn_Nivel1->clear();

    Vtn_Nivel1->draw(*sprt_fondoV1);


    for (auto& sprt_punto1 : vSprites){
        Vtn_Nivel1->draw(sprt_punto1);
    }

    Vtn_Nivel1->draw(*txt_Puntajetxt);
    Vtn_Nivel1->draw(*txt_Puntajeint);
    Vtn_Nivel1->draw(*txt_Vidastxt);
    Vtn_Nivel1->draw(*sprt_PowerUp);
    Vtn_Nivel1->draw(*txt_Vidasint);
    Vtn_Nivel1->draw(*sprt_PM_vidas);
  //  Vtn_Nivel1->draw(GetSprt_killFtsm1());
    Vtn_Nivel1->draw(GetFtsm1());
    Vtn_Nivel1->draw(GetSprt_killFtsm1());
    Vtn_Nivel1->draw(GetSprPacman());


    Vtn_Nivel1->display();
}

void Nivel1::Ciclar() {
    while (Vtn_Nivel1->isOpen()){
        Colisiones();
        Eventos();
        SetFramePU(num_framePU);
        Power_up(MostrarPU);
        SetFrameFtsm1(VulnerabilidadFtsm1);
      //  cout<< "Vulnerabilidad " << VulnerabilidadFtsm1 << endl;
        //cout<<"Tiempo poder activo= "<<tiempoPoderactivo->asSeconds()<<" segundos"<<endl;
       // cout<<"Reloj poder activo= "<<relojPoderactivo->getElapsedTime().asSeconds()<<" segundos"<<endl;
        Poder_Activo(VulnerabilidadFtsm1);
        RespawnFtsm1(Tiempo_SpawnFtsm1,*reloj_spawnFtsm, coord_posFtsm1 ,vPosiciones, indice_randomSpawnFtsm1 );
        Renderizar();
        txt_Vidasint->setString(to_string(Get_NumVidasPM()) + " x"); ///actualiza el numero de vidas



    }
}

void Nivel1::Eventos() {
    while (Vtn_Nivel1->pollEvent(*events)) {
        switch (events->type) {
            case Event::Closed:
                Vtn_Nivel1->close();
                cout << "Ventana facil cerrada de forma exitosa" << endl;
                exit(1);

            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::W)) {
                   // MovePM(0, movePM);
                    MovePM(0);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }



                }
                else if (Keyboard::isKeyPressed(Keyboard::S)){
                    MovePM(1);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::A)) {
                    MovePM(2);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)){
                    MovePM(3);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
        }
    }
}

void Nivel1::Colisiones() {

    /// funcion que elimina los puntos del vector segun el pacman los va comiendo, una vez no hayan puntos en el mapa, termina el nivel
    for (int i = 0; i < vSprites.size(); ++i) {
        if (GetSprPacman().getGlobalBounds().intersects(vSprites[i].getGlobalBounds())) {

            if(vSprites.size()>0){
                num_comparacionPU+=10;
                vSprites.erase(vSprites.begin() + i);
                txt_Puntajeint->setString(to_string(num_puntuacion_total+=10));
              //  cout << "num_comparacion = " << num_comparacionPU << " eliminado" << endl;
                //cout << vSprites.size() << endl;

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
                Vtn_Nivel1->close();
            }
        }
    }

    if (GetSprPacman().getGlobalBounds().intersects(sprt_PowerUp->getGlobalBounds())){
        MostrarPU = false;
        VulnerabilidadFtsm1 = true;
        num_comparacionPU = 0;
        relojPoderactivo->restart();
       // cout<< "Vulnerabilidad " << VulnerabilidadFtsm1 << endl;


    }
    ////////// esta funcion determina lo que sucede si interaccionan el pacman y el fantasma
    if (GetSprPacman().getGlobalBounds().intersects((GetFtsm1().getGlobalBounds()))){
        if(VulnerabilidadFtsm1 == false){
            if(Reduccion_VidasPM(VulnerabilidadFtsm1) > 0){
                cout << "xd"<<endl;
                SetNewPosition_PM(VulnerabilidadFtsm1, vPosiciones,252);
            } else{
                cout<< "GAME OVER"<<endl;
                Vtn_Nivel1->close();
            }
        }else{
            Tiempo_SpawnFtsm1 = true;
            reloj_spawnFtsm->restart();
            indice_randomSpawnFtsm1= rand()% vPosiciones.size();
            coord_posFtsm1 = {GetFtsm1().getPosition().x,GetFtsm1().getPosition().y};
            RespawnFtsm1(Tiempo_SpawnFtsm1,*reloj_spawnFtsm, coord_posFtsm1 , vPosiciones, indice_randomSpawnFtsm1);
            cout<<"Totalmente inmune" << endl;
            VulnerabilidadFtsm1 = false;
        }
    }
}


///esta funcion recorre los sprites del power up y lo actualiza por tiempo definido
void Nivel1::SetFramePU(int num_frames) {
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
void Nivel1::Power_up(bool mostrar) {
    if (mostrar == false){
        sprt_PowerUp->setPosition(-100,-100);
    }else{
        sprt_PowerUp->setPosition({static_cast<float>(98+30*vPos_xPU[pos_xPU]),static_cast<float>(103+30*vPos_yPU[pos_yPU])});
    }
}

/// Mantiene el poder de comer fantasmas por un tiempo establecido
void Nivel1::Poder_Activo(bool poderactivo) {
    if(poderactivo== true){
        *tiempoPoderactivo = relojPoderactivo->getElapsedTime();
        if (tiempoPoderactivo->asSeconds()>=12){
           // cout<<"holaaaaaa"<<endl;
            VulnerabilidadFtsm1 = false;
        }
    }
}




