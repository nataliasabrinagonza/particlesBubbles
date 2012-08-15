#pragma once
#include "ofMain.h"

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

class demoParticle{

	public:
		demoParticle();

		void reset();
		void update();
		void draw(ofImage* burbuja);
		void limite();
		void choca();
		bool estaViva();

		ofPoint pos;
		ofPoint vel;
		ofPoint frc;
		ofColor color;
		float	hCycle;
		int vida,vidaInicial;

		ofBlendMode blendMode;

		float drag;
		float scale;

		bool seMueve;

		vector <ofPoint> * attractPoints;
};
