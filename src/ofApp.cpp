#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    players.resize(VID_COUNT);
    frames.resize(VID_COUNT);
    for(int i=0 ; i < VID_COUNT ; i++) {
        players[i].load("v" + ofToString(i+1) + ".mp4");
        players[i].setVolume(0);
        frames[i].load("frames/v" + ofToString(i+1) + ".jpg");
    }
    
    randomiseVids();
}

//--------------------------------------------------------------
void ofApp::update(){
    players[index1].update();
    players[index2].update();
    players[index3].update();
    
    if(isShuffling) {
        
        if(shuffleCounter > SHUFFLE_LENGTH) {
            isShuffling = false;
            shuffleCounter = 0;
        } else {
            
            if(shuffleCounter % SHUFFLE_INC == 0) {
                
                vector<int> indices;
                for(int i=0 ; i<VID_COUNT ; i++) {
                    indices.push_back(i);
                }
                int i1 = floor(ofRandom(indices.size()));
                frameIndex1 = indices[i1];
                indices.erase(indices.begin() + i1);
                int i2 = floor(ofRandom(indices.size()));
                frameIndex2 = indices[i2];
                
                indices.erase(indices.begin() + i2);
                int i3 = floor(ofRandom(indices.size()));
                
                frameIndex3 = indices[i3];
            }
            
            shuffleCounter++;
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    if(isShuffling) {
        frames[frameIndex1].draw(0, 0, 320, 240);
        frames[frameIndex2].draw(320, 0, 320, 240);
        frames[frameIndex3].draw(640, 0, 320, 240);
    } else {
        players[index1].draw(0, 0, 320, 240);
        players[index2].draw(320, 0, 320, 240);
        players[index3].draw(640, 0, 320, 240);
    }
    
}

//--------------------------------------------------------------
void ofApp::randomiseVids() {
    
    // stop previous ones
    players[index1].stop();
    players[index2].stop();
    players[index3].stop();
    
    // set new indices
    vector<int> indices;
    for(int i=0 ; i<VID_COUNT ; i++) {
        indices.push_back(i);
    }
    int i1 = floor(ofRandom(indices.size()));
    
    index1 = indices[i1];
    
    indices.erase(indices.begin() + i1);
    int i2 = floor(ofRandom(indices.size()));
    
    index2 = indices[i2];
    
    indices.erase(indices.begin() + i2);
    int i3 = floor(ofRandom(indices.size()));
    
    index3 = indices[i3];
    
    // start new ones
    players[index1].play();
    players[index2].play();
    players[index3].play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        isShuffling = true;
        randomiseVids();
    } else if(key == 's') {
        isShuffling = !isShuffling;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
