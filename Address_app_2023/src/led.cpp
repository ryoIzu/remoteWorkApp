//
//  led.cpp
//  loadTest_0624
//
//  Created by mplusplus on 2016/06/24.
//
//

#include "led.hpp"

//--------------------------------------------------------------
led::led(unsigned short int _ID, unsigned short int _dancerID, unsigned short int _ledID, unsigned short int _deviceID, unsigned short int _lineID, float _x, float _y, unsigned short int _frontback, unsigned short int _light_down){
    
    ID = _ID;
    dancerID = _dancerID;
    ledID = _ledID;
    deviceID = _deviceID;
    lineID = _lineID;
    x = _x;
    y = _y;
    front = _frontback;
    light_down = _light_down;
    maskLED = false;
    
}
//--------------------------------------------------------------
unsigned short int led::clicked(int  mousex, int  mousey){
    if(ledID != -1){
        if(mousex-3 < x && mousex+3 > x){
            if(mousey-3 < y && mousey+3 > y){
                dragFlag=true;
                return ledID;
            }
        }
    }else{
        if(mousex < x +200 && mousex > x){
            if(mousey < y +20 && mousey > y){
                dragFlag=true;
                
            }
        }
    }
    return -1;
}
//--------------------------------------------------------------
void led::hovered(int  mousex, int  mousey){
    hover = false;
    if(mousex-3 < x && mousex+3 > x){
        if(mousey-3 < y && mousey+3 > y){
            hover=true;
        }
    }
}
//--------------------------------------------------------------
void led::dragged(int mousex, int mousey){
    if(dragFlag){
        x = mousex;
        y = mousey;
    }
}
//--------------------------------------------------------------
void led::detail(int arrow){
    if(hover){
        switch (arrow) {
            case 0:
                y -=1;
                break;
            case 1:
                x +=1;
                break;
            case 2:
                y+=1;
                break;
            case 3:
                x -=1;
                break;
            default:
                break;
        }
    }
}
//--------------------------------------------------------------
void led::dancerDragged(int movex, int movey){
    x = x + movex;
    y = y + movey;
}
//--------------------------------------------------------------
void led::released(){
    dragFlag = false;
}
//--------------------------------------------------------------
void led::draw(){
    if (hover) {
            ofSetColor(255,100,100,255);
            ofDrawRectangle(x-1, y-1, 3, 3);
        }else {
            if(front == false) {
                ofSetColor(255,255,255,255);
            } else if(front == true) {
                ofSetColor(0,0,0,255);
                ofDrawRectangle(x-1, y-1, 3, 3);
            }
            ofDrawRectangle(x-1, y-1, 3, 3);
        }
}
//--------------------------------------------------------------
void led::draw2(){
    if (hover) {
            ofSetColor(255,100,100);
            ofDrawRectangle(x-1, y-1, 3, 3);
        }else {
            if(front == false) {
                ofSetColor(50,50,50);
            }else if(front == true) {
                ofSetColor(0,0,0);
            }
            ofDrawRectangle(x-1,y-1, 3, 3);
        }
}
//--------------------------------------------------------------
void led::drawID(){
    if (hover) {
        ofSetColor(0,0,255,250);
    }else {
        ofSetColor(255,0,0);
    }
    char reportStr[1024];
    sprintf(reportStr, "%d-%d",deviceID,ledID);
    myfont.drawString(reportStr, x+2, y);
    
}
//--------------------------------------------------------------
string led::leddata(){
    
    string data = "";
    data += ofToString(deviceID) + "," + ofToString(ledID)  + "," + ofToString(x) + "," + ofToString(y) + "," + ofToString(front)  +"\n" ;
    return data;
    
}
//--------------------------------------------------------------
void led::groupHovered(int x1, int y1, int x2, int y2){
    if( x1 < x && x < x2 && y1 < y && y < y2){
        hover = true;
        dragFlag = true;
    }
}
//--------------------------------------------------------------
void led::addX(int _x){
    x += _x;
}
//--------------------------------------------------------------
void led::addY(int _y){
    y += _y;
}

