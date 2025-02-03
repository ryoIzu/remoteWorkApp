//
//  led.hpp
//  loadTest_0624
//
//  Created by mplusplus on 2016/06/24.
//
//

#ifndef led_hpp
#define led_hpp

#include "ofMain.h"

class led{
private:
    
    bool dragFlag;
    
    ofTrueTypeFont myfont;
    
public:
    unsigned short int front;  //0=front,1=back
    float x;
    float y;
    bool hover;
    unsigned short int ID;
    
    int ledID;
    unsigned short int deviceID;
    unsigned short int lineID;
    unsigned short int dancerID;
    unsigned short int light_down;
    bool maskLED;
    
    led(unsigned short int _ID, unsigned short int _dancerID, unsigned short int _ledID, unsigned short int _deviceID, unsigned short int _lineID, float _x, float _y, unsigned short int _frontback, unsigned short int _light_down);
    string leddata();
    
    unsigned short int clicked(int mousex, int mousey);
    void hovered(int mousex, int mousey);
    void dragged(int mousex, int mousey);
    void detail(int arrow);
    void dancerDragged(int movex, int movey);
    void released();
    void draw();
    void draw2();
    void drawID();
    void groupHovered(int x1, int y1, int x2, int y2);
    void addX(int _x);
    void addY(int _y);
    
};


#endif /* led_hpp */

