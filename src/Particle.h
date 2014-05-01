//
//  Particle.h
//  emptyExample
//
//  Created by Naoki Kanazawa on 2014/04/27.
//
//

#pragma once
#include "ofMain.h"

class Particle {

public:
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc;
	float damping;
	
	Particle();
	~Particle();
	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition(float px, float py, float vx, float vy);
	void update();
	void draw();

};