#include "demoParticle.h"

/*  manipulationOfVideo
  *
  * Copyright 2012 Natalia sabrina Gonza
  * Todos los derechos reservados.
  *
  * La redistribución y uso , con o sin modificación, están permitidas siempre que se
  * cumpla el siguiente requisito:
  *   La redistribución del código fuente deben conservar el derecho de autor
  *
  *               * -------------------------- *
  *
  * Copyright 2012 Natalia sabrina Gonza
  * All rights reserved.
  *
  * Redistribution and use, with or without modification, are permitted provided that it
  * meets the following requirement:
  *    Redistributions of source code must retain copyright
  *
  **/

//------------------------------------------------------------------
demoParticle::demoParticle(){

    hCycle  = 200;
}

//------------------------------------------------------------------

 void demoParticle::choca( )
 {

     ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
     frc = attractPt-pos;

     //obtiene la distancia
	 float dist = frc.length();
     frc.normalize();

     // se repelen los puntos serca del mouse
	 if( dist < 90 ){
         pos += -frc * 0.1;
      }
  }


//------------------------------------------------------------------
void demoParticle::limite( ){

    //verifica si las particulas salen del limite inferior, vuelve a la parte superior
		if( pos.y + vel.y > ofGetHeight() - 15 ){

			pos.x = pos.x;
            pos.y = ofGetHeight() - 15;
            frc   = (0);
            drag  = 0;
            seMueve = false;

            if (pos.y < ofGetMouseY()){
               seMueve = true;
            }
		}

		if( pos.x + vel.x > ofGetWidth() ){
			pos.x -= ofGetWidth();
		}
}

//------------------------------------------------------------------
void demoParticle::reset(){


	pos.x = ofRandomWidth();
	pos.y = ofRandom(0, ofGetWidth() - 200);

	frc   = ofPoint(0,0,0);
	scale = ofRandom(0.1, 5.0);
	drag  = ofRandom(0.1, 0.5);

	seMueve = true;
	vida = vidaInicial = ofRandom(200,1000);

}

//------------------------------------------------------------------
void demoParticle::update(){

        if( seMueve == true){

            //simula el viento
            //frecuancia con la que se mueve en x
            //-----(0.5) num + alto, mayor velocidad en X
            frc.x = 0.5 * 0.2 + ofSignedNoise(10, pos.y * 0.04) * 0.6;
            frc.y = ofSignedNoise(10, pos.x * 0.006) * 0.09 + 0.18; //simula la nieve cayendo

            vel *= drag;
            vel += frc * 0.1; // influe en la velocidad con la que caen al = que drag

            pos += vel;//actualiza posicion
        }
}

//------------------------------------------------------------------

bool demoParticle::estaViva(){
    bool rta = true;
    if (vida <= 0)
    rta = false;
    return rta;
}

//------------------------------------------------------------------
void demoParticle::draw(ofImage* _imagen){

	if (hCycle < 255) hCycle += 0.01;
	else hCycle = 0;

	color.setHue(hCycle);
	color.setHsb(hCycle, 255, 255);

    ofSetColor(color);
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
	_imagen->draw( pos.x, pos.y, scale * 12, scale * 12);
	ofDisableBlendMode();
	ofPopStyle();

}

