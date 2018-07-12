#pragma once

#include "ofMain.h"

#define VID_COUNT 12
#define SHUFFLE_LENGTH 120
#define SHUFFLE_INC 3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVideoPlayer myPlayer1;
        ofVideoPlayer myPlayer2;
        ofVideoPlayer myPlayer3;
    
        vector<ofImage> frames;
        vector<ofVideoPlayer> players;
        int index1;
        int index2;
        int index3;
    
        int frameIndex1;
        int frameIndex2;
        int frameIndex3;
    
        void randomiseVids();
    
        bool isShuffling;
        int shuffleCounter;
		
};
