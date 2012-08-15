#include "testApp.h"

/*  particlesBubbles
  *
  * Copyright 2012 Natalia sabrina Gonza
� * Todos los derechos reservados.
� *
� * La redistribuci�n y uso , con o sin modificaci�n, est�n permitidas siempre que se
  * cumpla el siguiente requisito:
� *   La redistribuci�n del c�digo fuente deben conservar el derecho de autor
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

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);

    ofEnableAlphaBlending();

    blendMode = OF_BLENDMODE_ADD;

	int num = 150;

	p.assign(num, demoParticle());

    for(int i = 0; i < p.size(); i++){
		p[i].reset();
		burbuja.loadImage("burbuja2.png");
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0; i < p.size(); i++){
	    p[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){

    //fondo
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

    //dibuja las particulas
	for(int i = 0; i < p.size(); i++){

		p[i].draw(&burbuja);
		p[i].limite();
		p[i].choca();

	}


    //---------Nombre------(versatilidad)----------------
	ofSetColor(230);
	ofDrawBitmapString("Natalia Sabrina Gonza", ofGetWidth() - 180 , ofGetHeight() - 10);
	//-------------------------------------------------------------------------------------/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if( key == ' ' ){

        for(int i = 0; i < p.size(); i++){
            p[i].reset();
        }
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
