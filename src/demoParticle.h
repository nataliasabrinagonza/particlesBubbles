#pragma once
#include "ofMain.h"

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
