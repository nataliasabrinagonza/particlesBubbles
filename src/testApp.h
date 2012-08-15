#pragma once

#include "ofMain.h"
#include "demoParticle.h"

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

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector <demoParticle> p;
		vector <ofPoint> attractPoints;
		vector <ofPoint> attractPointsWithMovement;

		ofImage burbuja;
		ofBlendMode blendMode;
};
