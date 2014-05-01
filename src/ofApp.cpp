#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	//	ofEnableAlphaBlending();
	ofBackground(0, 0, 0);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	// イメージファイル読み込み
	img.loadImage("particle32.png");
}


//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < particles.size(); i++) {
		particles[i].resetForce();
		particles[i].addForce(0, 0.1);
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255, 255, 255);
	
	// 画面左上にメッセージを表示
	string message = "current particle num =" + ofToString(particles.size(), 0);
	ofDrawBitmapString(message, 20, 20);
	

	// 粒子バージョン
	for (int i = 0; i < particles.size(); i++) {
		
		// 画像を使わない
		particles[i].draw();
		
		// 画像を使う
//		float posx = particles[i].pos.x - 16;
//		float posy = particles[i].pos.y - 16;
//		img.draw(posx, posy);
		
	}

	
//	曲線バージョン
//	ofNoFill();
//	ofBeginShape();
//	
//	for (int i = 0; i < particles.size(); i++) {
//		ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
//	}
//	ofEndShape();
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// 'c'キーでパーティクルを全消去
	if (key == 'c') {
		particles.clear();
	}
	
	// 'f'キーでフルスクリーン表示
	if (key == 'f') {
		ofToggleFullscreen();
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	// マウスをドラッグするとパーティクルが追加される
	
	Particle myParticle;
	
	//初期化
	float vx = ofRandom(-3,3);
	float vy = ofRandom(-3,3);
	
	myParticle.setInitialCondition(x, y, vx, vy);
	particles.push_back(myParticle);
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < NUM; i++) {
		//Particleをインスタンス化　⇒　myParticle
		Particle myParticle;
		
		//初期化
		float vx = ofRandom(-10,10);
		float vy = ofRandom(-10,10);
		
		myParticle.setInitialCondition(x, y, vx, vy);
		
		//作成したオブジェクトを配列の末尾に追加
		particles.push_back(myParticle);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}





