#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "led.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool gHide;
    bool mHide;
    bool eHide;
    ofParameter<int> dancerID;
    ofParameter<int> deviceID;
    ofParameter<int> ledID;
    ofParameter<float> ledx;
    ofParameter<float> ledy;
    
    //panel edit gui (mouse over led) --------------------------------------------------------------
    ofParameter<int>  lineID;
    ofxPanel gui;
    ofxButton xplus;
    ofxButton xminus;
    ofxButton yplus;
    ofxButton yminus;
    ofxButton nextLED;
    ofxButton prevLED;
    ofParameter<bool> useDevice;
    ofParameter<bool> useLine;
    ofParameter<bool> useDancer;
    bool setDeviceHover;
    ofParameter<int> multix;
    ofParameter<int> multiy;
    ofParameter<int> multiRotate;
    ofxButton invertLine;
    ofxButton refx;
    ofxButton refy;
    ofxLabel deleteLabel;
    ofxButton copyDevice;
    ofxButton copyDancer;
    ofxButton deleteLED;
    ofxButton deleteLine;
    ofxButton deleteDevice;
    ofxButton deleteDancer;
    ofxButton changeIDs;
    
    //add for mask
    ofxButton maskLED;
    void maskLEDBtn();
    bool isSave;
    int textSaveCount = 250;
    bool isAutoSave = false;
    bool isLoadLayout = false;
    
    //panel menu --------------------------------------------------------------
    ofxPanel menu;
    ofParameter<int> scene;
    ofxButton saveScene;
    ofxButton saveLED;
    ofxButton loadLED;  //load
    
    //panel edit  --------------------------------------------------------------
    ofParameter<bool> editMode;
    ofxPanel edit;
    ofxButton newLED;
    ofParameter<int> multiple;
    ofxButton newMultiple;
    ofParameter<bool> condensedPitch;
    ofParameter<float> diameter;
    ofxButton newCircle;
    ofxButton newPanel_v1;
    ofxButton newPanel_v2;
    ofxButton newSmallPanel;
    ofxButton newTriangle;
    ofxButton newKaminariPanel;
    ofxButton new8x24LEDsPanel;
    ofxButton new8x32LEDsSmallPanel;
    ofxButton new15x15Panel;
    
    // add 2017 6.16 front back-------------
    ofxButton draw_all_0;
    void draw_AllPressed_0();
    ofxButton draw_all_1;
    void draw_AllPressed_1();
    bool bdraw_all = false;
    ofParameter<bool> front;
    ofParameter<bool> back;
    void front_pressed(bool & front);
    void back_pressed(bool & back);
    
    // add 2017 6.27------------------------
    ofxButton change_front;
    void changed_front();
    ofxButton change_back;
    void changed_back();
    
    vector<led> leds;
    vector<led> preLeds;
    vector<ofRectangle> dancers;
    ofxButton alignDancer;
    ofParameter<int> alignSpace;
    int dparam;
    
    ofxButton oneLiner;
    ofParameter<bool> refImgOn;
    ofxButton twoThree;
    
    unsigned int controlledID;
    unsigned int prevID;
    int clickedX;
    int clickedY;
    int controlledDevice;
    int controlledDancer;
    int controlledLine;
    bool saveImg;
    
    void incrementXP();
    void incrementXM();
    void incrementYP();
    void incrementYM();
    int maxLEDID();
    int maxDeviceID();
    int maxLineID();
    void createNewLED();
    void createMultiple();
    void createCircle();
    void createPanel_v1();
    void createPanel_v2();
    void createSmallPanel();
    void createKaminariPanel();
    void createTriangle();
    void create8x24LEDsPanel();
    void create8x32LEDsSmallPanel();
    void create15x15Panel();
    void cpDevice();
    void cpDancer();
    void reflectX();
    void reflectY();
    void createDancers();
    void rmLED();
    void rmLine();
    void rmDevice();
    void rmDancer();
    void saveImage();
    void saveLayout();
    void loadLEDLayout();//0-99
    void oneLine();
    void selectNext();
    void selectPrev();
    void invertLEDLine();
    void changeID();
    
    ofImage img;
    ofImage editImage;
    ofImage sceneImage;
    ofImage square;
    ofImage squareEmpty;
    ofImage refImg;
    ofImage frontImg;
    ofImage backImg;
    ofImage allImg;
    
    ofTrueTypeFont myfont;
    ofTrueTypeFont saveFont;
    ofTrueTypeFont font_frontback;
    int maxScene;
    int maxSound;
    
    int work;
    int work_s;
    
    unsigned short int front_back = 0;
    int dancer_counter = 0;
    
    //2020.06.29 add ysik
    bool push_command = false;
    bool push_s = false;
    
};



