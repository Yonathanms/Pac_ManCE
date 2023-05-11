//
// Created by yonathanms on 25/04/23.
//

#include <iostream>
#include "../View-Controller/Nivel1.h"


Nivel1::Nivel1() {
    Vtn_Nivel1 = new RenderWindow(VideoMode(950,1000),"Nivel 1");
    Vtn_Nivel1->setFramerateLimit(60);

    events = new Event;

    txtr_fondoV1 = new Texture;
    sprt_fondoV1 = new Sprite;
    txtr_fondoV1->loadFromFile("../Recursos/FondoVtn1.png");
    sprt_fondoV1->setTexture(*txtr_fondoV1);
    sprt_fondoV1->setPosition(75,100);

    sprt_punto1 = new Sprite;
    txtr_punto1 = new Texture;
    txtr_punto1->loadFromFile("../Recursos/punto7.png");
    sprt_punto1->setTexture(*txtr_punto1);
   // sprt_punto1->setPosition(104,128);
    movePM = true;
    num_framePM = 0;

    vSprites = {5,*sprt_punto1};
    y = 0;

    for (auto& sprt_punto1 : vSprites){
        sprt_punto1.setPosition(104,y);
        y += 100;
    }
    barreras();
    Ciclar();

}

void Nivel1::Renderizar() {
    Vtn_Nivel1->clear();

    Vtn_Nivel1->draw(*sprt_fondoV1);


    for (auto& sprt_punto1 : vSprites){
        Vtn_Nivel1->draw(sprt_punto1);
    }

    Vtn_Nivel1->draw(GetSprPacman());

    Vtn_Nivel1->display();
}

void Nivel1::Ciclar() {
    while (Vtn_Nivel1->isOpen()){
        Colisiones();
        Eventos();
        Renderizar();


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
                    MovePM(0, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }

                }
                else if (Keyboard::isKeyPressed(Keyboard::S)){
                    MovePM(1, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::A)) {
                    MovePM(2, movePM);
                    SetFrame(num_framePM);
                    num_framePM++;
                    if(num_framePM==5){
                        num_framePM = 0;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)){
                    MovePM(3, movePM);
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

    if (GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_1->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_2->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_3->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_4->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_5->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_6->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_7->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_8->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_9->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_10->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_11->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_12->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_13->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_14->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_15->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_16->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_17->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_18->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_19->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_20->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_21->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_22->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_23->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_24->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_25->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_26->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_27->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_28->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_29->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_30->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_31->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_32->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_33->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_34->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_35->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_36->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_37->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_38->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_39->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_40->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_41->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_42->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_43->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_44->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_45->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_46->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_47->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_48->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_49->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_50->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_51->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_52->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_53->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_54->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_55->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_56->getGlobalBounds()) or
        GetSprPacman().getGlobalBounds().intersects(rctngl_Barrera1_57->getLocalBounds())){
        movePM = false;
        cout<<"colisiono"<<GetSprPacman().getPosition().x<<endl;
    }
    else{
        movePM = true;
    }

    for (int i = 0; i < vSprites.size(); ++i) {
        if (GetSprPacman().getGlobalBounds().intersects(vSprites[i].getGlobalBounds())){
            vSprites[i].setPosition(-100,-100);
        }
    }
}

void Nivel1::barreras() {
    rctngl_Barrera1_1 = new RectangleShape;
    rctngl_Barrera1_2 = new RectangleShape;
    rctngl_Barrera1_3 = new RectangleShape;
    rctngl_Barrera1_4 = new RectangleShape;
    rctngl_Barrera1_5 = new RectangleShape;
    rctngl_Barrera1_6 = new RectangleShape;
    rctngl_Barrera1_7 = new RectangleShape;
    rctngl_Barrera1_8 = new RectangleShape;
    rctngl_Barrera1_9 = new RectangleShape;
    rctngl_Barrera1_10 = new RectangleShape;
    rctngl_Barrera1_11 = new RectangleShape;
    rctngl_Barrera1_12 = new RectangleShape;
    rctngl_Barrera1_13 = new RectangleShape;
    rctngl_Barrera1_14 = new RectangleShape;
    rctngl_Barrera1_15 = new RectangleShape;
    rctngl_Barrera1_16 = new RectangleShape;
    rctngl_Barrera1_17 = new RectangleShape;
    rctngl_Barrera1_18 = new RectangleShape;
    rctngl_Barrera1_19 = new RectangleShape;
    rctngl_Barrera1_20 = new RectangleShape;
    rctngl_Barrera1_21 = new RectangleShape;
    rctngl_Barrera1_22 = new RectangleShape;
    rctngl_Barrera1_23 = new RectangleShape;
    rctngl_Barrera1_24 = new RectangleShape;
    rctngl_Barrera1_25 = new RectangleShape;
    rctngl_Barrera1_26 = new RectangleShape;
    rctngl_Barrera1_27 = new RectangleShape;
    rctngl_Barrera1_28 = new RectangleShape;
    rctngl_Barrera1_29 = new RectangleShape;
    rctngl_Barrera1_30 = new RectangleShape;
    rctngl_Barrera1_31 = new RectangleShape;
    rctngl_Barrera1_32 = new RectangleShape;
    rctngl_Barrera1_33 = new RectangleShape;
    rctngl_Barrera1_34 = new RectangleShape;
    rctngl_Barrera1_35 = new RectangleShape;
    rctngl_Barrera1_36 = new RectangleShape;
    rctngl_Barrera1_37 = new RectangleShape;
    rctngl_Barrera1_38 = new RectangleShape;
    rctngl_Barrera1_39 = new RectangleShape;
    rctngl_Barrera1_40 = new RectangleShape;
    rctngl_Barrera1_41 = new RectangleShape;
    rctngl_Barrera1_42 = new RectangleShape;
    rctngl_Barrera1_43 = new RectangleShape;
    rctngl_Barrera1_44 = new RectangleShape;
    rctngl_Barrera1_45 = new RectangleShape;
    rctngl_Barrera1_46 = new RectangleShape;
    rctngl_Barrera1_47 = new RectangleShape;
    rctngl_Barrera1_48 = new RectangleShape;
    rctngl_Barrera1_49 = new RectangleShape;
    rctngl_Barrera1_50 = new RectangleShape;
    rctngl_Barrera1_51 = new RectangleShape;
    rctngl_Barrera1_52 = new RectangleShape;
    rctngl_Barrera1_53 = new RectangleShape;
    rctngl_Barrera1_54 = new RectangleShape;
    rctngl_Barrera1_55 = new RectangleShape;
    rctngl_Barrera1_56 = new RectangleShape;
    rctngl_Barrera1_57 = new RectangleShape;


    rctngl_Barrera1_1->setPosition(150,175);
    rctngl_Barrera1_1->setSize(Vector2f (79,50));

    rctngl_Barrera1_2->setPosition(718,175);
    rctngl_Barrera1_2->setSize(Vector2f (79,50));

    rctngl_Barrera1_3->setPosition(292,175);
    rctngl_Barrera1_3->setSize(Vector2f (107,50));

    rctngl_Barrera1_4->setPosition(548,175);
    rctngl_Barrera1_4->setSize(Vector2f (107,50));

    rctngl_Barrera1_5->setPosition(80,102);
    rctngl_Barrera1_5->setSize(Vector2f (783,10));

    rctngl_Barrera1_6->setPosition(463,120);
    rctngl_Barrera1_6->setSize(Vector2f (20,103));

    rctngl_Barrera1_7->setPosition(151,289);
    rctngl_Barrera1_7->setSize(Vector2f (76,21));

    rctngl_Barrera1_8->setPosition(720,289);
    rctngl_Barrera1_8->setSize(Vector2f (75,21));

    rctngl_Barrera1_9->setPosition(292,289);
    rctngl_Barrera1_9->setSize(Vector2f (21,189));

    rctngl_Barrera1_10->setPosition(379,289);
    rctngl_Barrera1_10->setSize(Vector2f (189,21));

    rctngl_Barrera1_11->setPosition(633,289);
    rctngl_Barrera1_11->setSize(Vector2f (21,189));

    rctngl_Barrera1_12->setPosition(379,628);
    rctngl_Barrera1_12->setSize(Vector2f (189,21));

    rctngl_Barrera1_13->setPosition(379,799);
    rctngl_Barrera1_13->setSize(Vector2f (189,21));

    rctngl_Barrera1_14->setPosition(292,544);
    rctngl_Barrera1_14->setSize(Vector2f (21,104));

    rctngl_Barrera1_15->setPosition(633,544);
    rctngl_Barrera1_15->setSize(Vector2f (21,104));

    rctngl_Barrera1_16->setPosition(293,714);
    rctngl_Barrera1_16->setSize(Vector2f (104,21));

    rctngl_Barrera1_17->setPosition(550,714);
    rctngl_Barrera1_17->setSize(Vector2f (104,21));

    rctngl_Barrera1_18->setPosition(207,714);
    rctngl_Barrera1_18->setSize(Vector2f (21,104));

    rctngl_Barrera1_19->setPosition(719,714);
    rctngl_Barrera1_19->setSize(Vector2f (21,104));

    rctngl_Barrera1_20->setPosition(463,628);
    rctngl_Barrera1_20->setSize(Vector2f (21,104));

    rctngl_Barrera1_21->setPosition(463,800);
    rctngl_Barrera1_21->setSize(Vector2f (21,104));

    rctngl_Barrera1_22->setPosition(463,289);
    rctngl_Barrera1_22->setSize(Vector2f (21,104));

    rctngl_Barrera1_23->setPosition(293,373);
    rctngl_Barrera1_23->setSize(Vector2f (104,21));

    rctngl_Barrera1_24->setPosition(293,800);
    rctngl_Barrera1_24->setSize(Vector2f (21,104));

    rctngl_Barrera1_25->setPosition(550,373);
    rctngl_Barrera1_25->setSize(Vector2f (104,21));

    rctngl_Barrera1_26->setPosition(633,800);
    rctngl_Barrera1_26->setSize(Vector2f (21,104));

    rctngl_Barrera1_27->setPosition(151,884);
    rctngl_Barrera1_27->setSize(Vector2f (244,21));

    rctngl_Barrera1_28->setPosition(550,884);
    rctngl_Barrera1_28->setSize(Vector2f (244,21));

    rctngl_Barrera1_29->setPosition(88,800);
    rctngl_Barrera1_29->setSize(Vector2f (51,21));

    rctngl_Barrera1_30->setPosition(806,800);
    rctngl_Barrera1_30->setSize(Vector2f (51,21));

    rctngl_Barrera1_31->setPosition(151,714);
    rctngl_Barrera1_31->setSize(Vector2f (51,21));

    rctngl_Barrera1_32->setPosition(744,714);
    rctngl_Barrera1_32->setSize(Vector2f (51,21));

    rctngl_Barrera1_33->setPosition(80,970);
    rctngl_Barrera1_33->setSize(Vector2f (783,10));

    rctngl_Barrera1_34->setPosition(77,102);
    rctngl_Barrera1_34->setSize(Vector2f (10,260));

    rctngl_Barrera1_35->setPosition(77,640);
    rctngl_Barrera1_35->setSize(Vector2f (10,328));

    rctngl_Barrera1_36->setPosition(859,102);
    rctngl_Barrera1_36->setSize(Vector2f (10,260));

    rctngl_Barrera1_37->setPosition(859,640);
    rctngl_Barrera1_37->setSize(Vector2f (10,328));

    rctngl_Barrera1_38->setPosition(218,373);
    rctngl_Barrera1_38->setSize(Vector2f (10,104));

    rctngl_Barrera1_39->setPosition(218,544);
    rctngl_Barrera1_39->setSize(Vector2f (10,104));

    rctngl_Barrera1_40->setPosition(718,373);
    rctngl_Barrera1_40->setSize(Vector2f (10,104));

    rctngl_Barrera1_41->setPosition(718,544);
    rctngl_Barrera1_41->setSize(Vector2f (10,104));

    rctngl_Barrera1_42->setPosition(77,373);
    rctngl_Barrera1_42->setSize(Vector2f (128,10));

    rctngl_Barrera1_43->setPosition(77,470);
    rctngl_Barrera1_43->setSize(Vector2f (128,10));

    rctngl_Barrera1_44->setPosition(77,640);
    rctngl_Barrera1_44->setSize(Vector2f (128,10));

    rctngl_Barrera1_45->setPosition(77,543);
    rctngl_Barrera1_45->setSize(Vector2f (128,10));

    rctngl_Barrera1_46->setPosition(718,373);
    rctngl_Barrera1_46->setSize(Vector2f (128,10));

    rctngl_Barrera1_47->setPosition(718,543);
    rctngl_Barrera1_47->setSize(Vector2f (128,10));

    rctngl_Barrera1_48->setPosition(718,640);
    rctngl_Barrera1_48->setSize(Vector2f (128,10));

    rctngl_Barrera1_49->setPosition(718,470);
    rctngl_Barrera1_49->setSize(Vector2f (128,10));

    rctngl_Barrera1_50->setPosition(718,470);
    rctngl_Barrera1_50->setSize(Vector2f (128,10));

    rctngl_Barrera1_51->setPosition(77,470);
    rctngl_Barrera1_51->setSize(Vector2f (10,72));

    rctngl_Barrera1_52->setPosition(859,470);
    rctngl_Barrera1_52->setSize(Vector2f (10,72));

    rctngl_Barrera1_53->setPosition(376,460);
    rctngl_Barrera1_53->setSize(Vector2f (10,104));

    rctngl_Barrera1_54->setPosition(560,460);
    rctngl_Barrera1_54->setSize(Vector2f (10,104));

    rctngl_Barrera1_55->setPosition(376,458);
    rctngl_Barrera1_55->setSize(Vector2f (61,10));

    rctngl_Barrera1_56->setPosition(376,556);
    rctngl_Barrera1_56->setSize(Vector2f (184,10));

    rctngl_Barrera1_57->setPosition(504,458);
    rctngl_Barrera1_57->setSize(Vector2f (61,10));
}

void Nivel1::puntos(RenderWindow, Sprite, Vector2f) {

}


