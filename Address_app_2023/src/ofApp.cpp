#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofDisableAntiAliasing();
    
    maxScene = 70; //above the app window
    
    //set up function of ofxGui-----------------------------------------------------------------------------
    xplus.addListener(this, &ofApp::incrementXP);
    xminus.addListener(this, &ofApp::incrementXM);
    yplus.addListener(this, &ofApp::incrementYP);
    yminus.addListener(this, &ofApp::incrementYM);
    newLED.addListener(this, &ofApp::createNewLED);
    newMultiple.addListener(this, &ofApp::createMultiple);
    newPanel_v1.addListener(this, &ofApp::createPanel_v1);
    newPanel_v2.addListener(this, &ofApp::createPanel_v2);
    newSmallPanel.addListener(this, &ofApp::createSmallPanel);
    newKaminariPanel.addListener(this, &ofApp::createKaminariPanel);
    newTriangle.addListener(this, &ofApp::createTriangle);
    new8x24LEDsPanel.addListener(this, &ofApp::create8x24LEDsPanel);
    new8x32LEDsSmallPanel.addListener(this, &ofApp::create8x32LEDsSmallPanel);
    new15x15Panel.addListener(this, &ofApp::create15x15Panel);
    copyDevice.addListener(this, &ofApp::cpDevice);
    copyDancer.addListener(this, &ofApp::cpDancer);
    refx.addListener(this, &ofApp::reflectX);
    refy.addListener(this, &ofApp::reflectY);
    deleteLED.addListener(this, &ofApp::rmLED);
    deleteDevice.addListener(this, &ofApp::rmDevice);
    deleteDancer.addListener(this, &ofApp::rmDancer);
    deleteLine.addListener(this, &ofApp::rmLine);
    saveScene.addListener(this, &ofApp::saveImage);
    saveLED.addListener(this, &ofApp::saveLayout);
    loadLED.addListener(this, &ofApp::loadLEDLayout);
    newCircle.addListener(this, &ofApp::createCircle);
    oneLiner.addListener(this, &ofApp::oneLine);
    nextLED.addListener(this, &ofApp::selectNext);
    prevLED.addListener(this, &ofApp::selectPrev);
    //invertLine.addListener(this, &ofApp::invertLEDLine);
    changeIDs.addListener(this, &ofApp::changeID);
    maskLED.addListener(this, &ofApp::maskLEDBtn);
    front.addListener(this, &ofApp::front_pressed);
    back.addListener(this, &ofApp::back_pressed);
    draw_all_0.addListener(this, &ofApp::draw_AllPressed_0);
    draw_all_1.addListener(this, &ofApp::draw_AllPressed_1);
    //add 2017 6.27-----------------------------------------------------------------------------
    change_front.addListener(this, &ofApp::changed_front);
    change_back.addListener(this, &ofApp::changed_back);
    
    //set up GUI-----------------------------------------------------------------------------
    //set up Edit Address gui----------------------------------------------------------------
    gui.setup();
    gui.setBorderColor(ofColor(200,0,0));
    gui.setHeaderBackgroundColor(ofColor(200,0,0));
    gui.setFillColor(ofColor(100,0,0));
    gui.setDefaultBackgroundColor(ofColor(200,100,100));
    gui.setDefaultFillColor(ofColor(255,50,50));
    gui.setBackgroundColor(ofColor(200,100,100));
    gui.setBorderColor(ofColor(100,100,100));
    gui.add(nextLED.setup("next LED >"));
    gui.add(prevLED.setup("previous LED <"));
    gui.add(dancerID.set("Dancer ID", 0, 0, 150));
    gui.add(deviceID.set("Device ID", 0, 0, 40));
    gui.add(lineID.set("line ID", 0, 0, 300));
    gui.add(ledID.set("LED ID", 0, 0, 300));
    gui.add(changeIDs.setup("change ID"));
    gui.add(ledx.set("x", ofGetWidth()*.5, 0, ofGetWidth()));
    gui.add(ledy.set("y", ofGetHeight()*.5, 0,ofGetHeight()));
    gui.add(xplus.setup("x++"));
    gui.add(xminus.setup("x--"));
    gui.add(yplus.setup("y++"));
    gui.add(yminus.setup("y--"));
    gui.add(front.set("front",false));
    gui.add(back.set("back",false));
    gui.add(draw_all_0.setup("draw all or frontback"));
    gui.add(maskLED.setup("maskLED"));
    gui.add(useDancer.set("Select dancer",false));
    gui.add(useDevice.set("Select device",false));
    gui.add(useLine.set("Select line",false));
    gui.add(change_front.setup("change_front"));
    gui.add(change_back.setup("change back"));
    gui.add(multix.set("move x",0,-100,100));
    gui.add(multiy.set("move y",0,-100,100));
    gui.add(multiRotate.set("rotate",0,-180,180));
    gui.add(invertLine.setup("invert LedIDs of Line"));
    gui.add(refx.setup("Y axis reflect"));
    gui.add(refy.setup("X axis reflect"));
    gui.add(copyDevice.setup("copy device"));
    gui.add(copyDancer.setup("copy dancer"));
    gui.add(deleteLabel.setup("delete",""));
    gui.add(deleteLED.setup("delete this LED"));
    gui.add(deleteLine.setup("delete this Line"));
    gui.add(deleteDevice.setup("delete this Device"));
    gui.add(deleteDancer.setup("delete this Dancer"));
    
    //set up default gui-----------------------------------------------------------------------------
    menu.setup();
    menu.setBorderColor(ofColor(200,200,200));
    menu.setHeaderBackgroundColor(ofColor(100,100,100));
    menu.setFillColor(ofColor(200,200,200));
    menu.setDefaultBackgroundColor(ofColor(0,0,0));
    menu.setDefaultFillColor(ofColor(150,150,150));
    menu.setBackgroundColor(ofColor(0,0,0));
    menu.setBorderColor(ofColor(100,100,100));
    menu.add(editMode.set("Edit Mode", false));
    menu.add(scene.set("scene",0,0,maxScene -1));
    menu.add(saveScene.setup("save scene as image"));
    menu.add(saveLED.setup("save LED layout data"));
    menu.add(loadLED.setup("load scene"));
    
    //set up edit LED num & scene gui-----------------------------------------------------------------
    edit.setDefaultWidth(256);
    edit.setup();
    edit.add(editMode.set("Edit Mode", false));
    //edit.add(front.set("front",false));
    //edit.add(back.set("back",false));
    //edit.add(draw_all_1.setup("draw all or frontback"));
    edit.add(multiple.set("multiple LED",2,1,256));
    edit.add(condensedPitch.set("144 pitch",false));
    edit.add(newMultiple.setup("Create New LINE"));
    edit.add(diameter.set("diameter", 10, 1, 100));
    edit.add(newCircle.setup("Create Circle"));
    edit.add(newPanel_v1.setup("Create Panel_v1"));
    edit.add(newPanel_v2.setup("Create Panel_v2"));
    edit.add(newSmallPanel.setup("Create Small Panel"));
    edit.add(newTriangle.setup("Create Triangle"));
    edit.add(newKaminariPanel.setup("Create Kaminari Panel"));
    edit.add(new8x24LEDsPanel.setup("Create 8x24LEDs Panel"));
    edit.add(new8x32LEDsSmallPanel.setup("Create 8x32LEDs Small Panel"));
    edit.add(new15x15Panel.setup("Create 15x15 Panel"));
    edit.add(alignSpace.set("align space", 95,10,120));
    edit.add(refImgOn.set("Guid Image",false));
    
    //set up Image-----------------------------------------------------------------------------
    editImage.load("system/edit.png");
    sceneImage.load("system/scene.png");
    square.load("system/square.png");
    squareEmpty.load("system/squareEmpty.png");
    frontImg.load("system/front.png");
    backImg.load("system/back.png");
    allImg.load("system/all.png");
    
    //set up font-----------------------------------------------------------------------------
    myfont.load("system/frabk.ttf", 8);
    saveFont.load("system/frabk.ttf", 30);
    font_frontback.load("system/Quicksand-Regular.otf", 10);
    //set up refImage(ref image = guid image)
    refImg.load("refImage.png");
    
    //vlaue initialization-----------------------------------------------------------------------------
    dparam = 1;
    led l(0,0,0,0,0,100,100,front_back,0);
    leds.push_back(l);
    prevID =0;
    setDeviceHover = false;
    saveImg = false;
    
    //load Default scene-----------------------------------------------------------------------------
    loadLEDLayout();
    
    //Cursor initialization-----------------------------------------------------------------------------
    ofHideCursor();
    
    //gui initialization-----------------------------------------------------------------------------
    gHide = false;
    mHide = false;
    eHide = false;
}


//add 2017.6.16------------------------------------------------
//--------------------------------------------------------------

void ofApp::draw_AllPressed_0(){
    cout << "draw all pressed 0" << endl;
    
    if(bdraw_all == true){
        bdraw_all = false;
    }else{
        bdraw_all = true;
    }
    
}

//--------------------------------------------------------------

void ofApp::draw_AllPressed_1(){
    cout << "draw all pressed 1" << endl;
    if(bdraw_all == true){
        bdraw_all = false;
        cout << "bdraw_all 1 false" << endl;
    }else{
        bdraw_all = true;
        cout << "bdraw_all 1 true" << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::front_pressed(bool & front){
    cout << "front pressed" << endl;
    
    if(editMode){
        cout << "editMode front press" << endl;
        if(back == false){
            cout << "true" << endl;
            front_back = 0;
        }
        cout << front_back << endl;
    }else{
        cout << "NOTeditMode front press" << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::back_pressed(bool & front){
    cout << "back pressed" << endl;
    if(back == true){
        cout << "true" << endl;
        front_back = 1;
    }
    cout << front_back << endl;
    
}

//--------------------------------------------------------------
void ofApp::changed_front(){
    cout << "changed front" << endl;
    if (useLine && preLeds.size() != 0) {
        cout << "use LINE" << endl;
        if (controlledDancer == dancerID && controlledLine == lineID) {
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].lineID == controlledLine && leds[i].dancerID == controlledDancer) {
                    leds[i].front = 0;
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::changed_back(){
    cout << "changed back" << endl;
    if (useLine && preLeds.size() != 0) {
        cout << "use LINE" << endl;
        if (controlledDancer == dancerID && controlledLine == lineID) {
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].lineID == controlledLine && leds[i].dancerID == controlledDancer) {
                    leds[i].front = 1;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::maskLEDBtn(){
    leds[controlledID].maskLED = !leds[controlledID].maskLED;
    leds[controlledID].front = leds[controlledID].maskLED;
}

//--------------------------------------------------------------
void ofApp::changeID(){
    if (!useDevice && !useLine && leds.size() != 0) {
        leds[controlledID].dancerID = dancerID;
        leds[controlledID].deviceID = deviceID;
        leds[controlledID].ledID = ledID;
        leds[controlledID].front = front;
    }else if (useDevice && preLeds.size() != 0) {
        if (controlledDevice != deviceID){
            useDevice = false;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].deviceID == controlledDevice && leds[i].dancerID == controlledDancer) {
                    leds[i].deviceID = deviceID;
                }
            }
            int cnt =0;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].deviceID == deviceID && leds[i].dancerID == controlledDancer) {
                    leds[i].ledID = cnt;
                    cnt++;
                }
            }
        }else if ( controlledDancer != dancerID){
            useDevice = false;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].deviceID == controlledDevice && leds[i].dancerID == controlledDancer) {
                    leds[i].dancerID = dancerID;
                }
            }
        }
    }else if (useLine && preLeds.size() != 0) {
        if (controlledDevice != deviceID){
            useLine = false;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].lineID == controlledLine && leds[i].dancerID == controlledDancer) {
                    leds[i].deviceID = deviceID;
                }
            }
            int cnt =0;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].deviceID == controlledDevice  && leds[i].dancerID == controlledDancer) {
                    leds[i].ledID = cnt;
                    cnt++;
                }
            }
        }else if ( controlledDancer != dancerID){
            useLine = false;
            for (int i = 0 ; i < leds.size() ; i++) {
                if (leds[i].lineID == controlledLine && leds[i].dancerID == controlledDancer) {
                    leds[i].dancerID = dancerID;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::selectNext(){
    int tempID=controlledID;
    for (int i = 0 ; i < leds.size() ; i++) {
        if (leds[i].ID == controlledID +1) {
            leds[tempID].hover =false;
            tempID = i;
            leds[tempID].hover =true;
        }
    }
    controlledID = tempID;
    dancerID.set(leds[controlledID].dancerID);
    deviceID.set(leds[controlledID].deviceID);
    lineID.set(leds[controlledID].lineID);
    ledID.set(leds[controlledID].ledID);
    ledx.set(leds[controlledID].x);
    ledy.set(leds[controlledID].y);
    front.set(leds[controlledID].front);
}
//--------------------------------------------------------------
void ofApp::selectPrev(){
    int tempID=controlledID;
    for (int i = 0 ; i < leds.size() ; i++) {
        if (leds[i].ID == controlledID - 1) {
            leds[tempID].hover =false;
            tempID = i;
            leds[tempID].hover =true;
        }
    }
    controlledID = tempID;
    dancerID.set(leds[controlledID].dancerID);
    deviceID.set(leds[controlledID].deviceID);
    lineID.set(leds[controlledID].lineID);
    ledID.set(leds[controlledID].ledID);
    ledx.set(leds[controlledID].x);
    ledy.set(leds[controlledID].y);
    front.set(leds[controlledID].front);
}
//--------------------------------------------------------------
void ofApp::incrementXP(){
    if(useDevice == true || useLine == true) {
        multix++;
    }
    else {
        ledx.set(ledx+1);
    }
}
//--------------------------------------------------------------
void ofApp::incrementXM(){
    if(useDevice == true || useLine == true) {
        multix--;
    }
    else {
        ledx.set(ledx-1);
    }
}
//--------------------------------------------------------------
void ofApp::incrementYP(){
    if(useDevice == true || useLine == true) {
        multiy++;
    }
    else {
        ledy.set(ledy+1);
    }
    
}
//--------------------------------------------------------------
void ofApp::incrementYM(){
    if(useDevice == true || useLine == true) {
        multiy--;
    }
    else {
        ledx.set(ledy-1);
    }
}
//--------------------------------------------------------------
int ofApp::maxLEDID(){
    int maxID = 0;
    for (int i = 0 ; i < leds.size(); i++) {
        if (leds[i].ID > maxID ){
            maxID = leds[i].ID;
        }
    }
    return maxID;
}
//--------------------------------------------------------------
int ofApp::maxDeviceID(){
    int maxD = 0;
    for (int i = 0 ; i < leds.size(); i++) {
        if (leds[i].deviceID  > maxD ){
            maxD = leds[i].deviceID;
        }
    }
    return maxD;
}
//--------------------------------------------------------------
int ofApp::maxLineID(){
    int maxID = 0;
    for (int i = 0 ; i < leds.size(); i++) {
        if (leds[i].lineID > maxID ){
            maxID = leds[i].lineID;
        }
    }
    return maxID;
    
}
//--------------------------------------------------------------
void ofApp::createNewLED(){
    float minDistance = MAXFLOAT;
    int tempID =0;
    for (int i = 0 ; i < leds.size(); i++) {
        float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
        if ( tempDistance < minDistance) {
            minDistance = tempDistance;
            tempID =i;
        }
    }
    if ( leds.size() !=0){
        led l(maxLEDID() + 1,leds[tempID].dancerID,leds[tempID].ledID +1,maxLineID()+1,maxLineID()+1,clickedX,clickedY,front_back,0);
        leds.push_back(l);
    }else{
        led l(0,0,0,0,0,clickedX,clickedY,front_back,front);
        leds.push_back(l);
    }
}
//--------------------------------------------------------------
void ofApp::createMultiple(){
    float pitch = 3;
    if (condensedPitch) {
        //144/m LED pitch
        pitch = 1;
    }
    if ( leds.size() !=0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        for (int i =0; i < multiple ; i++){
            led l(maxLEDID() + 1,leds[tempID].dancerID,i,_devID,_linID,clickedX + i * pitch,clickedY,front_back,0);
            leds.push_back(l);
        }
    }else{
        for (int i =0; i < multiple ; i++){
            led l(i,0,i,0,0,clickedX + i * pitch,clickedY,front_back,0);
            leds.push_back(l);
        }
    }
}

//20220419 add by ueda
void ofApp::create8x24LEDsPanel(){
    float pitch = 1;
    if (condensedPitch) {
        pitch =1;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        //for (int i =0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 24; x++) {
                if(y%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 24*y,_devID,_linID,clickedX + x * pitch ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 24*y,_devID,_linID,(clickedX+23*pitch) + -(x * pitch) ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }else{
        cout << "led = 0 " << endl;
        //for (int i = 0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 24; x++) {
                if(y%2 == 0){
                    led l(x + 24*y,0,x + 24*y,0,0,clickedX + x * pitch,clickedY - y,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(x + 24*y,0,x + 24*y,0,0,(clickedX+23*pitch) + -(x * pitch) ,clickedY - y,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//20220730 add by ueda
void ofApp::create8x32LEDsSmallPanel(){
    float pitch = 1;
    if (condensedPitch) {
        pitch =1;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        //for (int i =0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 32; x++) {
                if(y%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 32*y,_devID,_linID,clickedX + x * pitch ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 32*y,_devID,_linID,(clickedX+31*pitch) + -(x * pitch) ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }else{
        cout << "led = 0 " << endl;
        //for (int i = 0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 32; x++) {
                if(y%2 == 0){
                    led l(x + 32*y,0,x + 32*y,0,0,clickedX + x * pitch,clickedY - y,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(x + 32*y,0,x + 32*y,0,0,(clickedX+31*pitch) + -(x * pitch) ,clickedY - y,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//_______________2019.02.21 add ONO________________________________________________________________________________________________________________________________________
void ofApp::createSmallPanel(){
    cout << " Passing createSmallPanel func " << endl;
    float pitch = 1;
    if (condensedPitch) {
        pitch =1;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        for (int y = 0; y < 16; y++) {
            for (int x = 0; x < 8; x++) {
                if(y%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 8*y,_devID,_linID,clickedX + x * pitch ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 8*y,_devID,_linID,(clickedX+7*pitch) + -(x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                }
            }
        }
    }else{
        for (int y = 0; y < 16; y++) {
            for (int x = 0; x < 8; x++) {
                if(y%2 == 0){
                    led l(x + 8*y,0,x + 8*y,0,0,clickedX + x * pitch,clickedY - y,0,1);
                    leds.push_back(l);
                }else{
                    led l(x + 8*y,0,x + 8*y,0,0,(clickedX+7*pitch) + -(x * pitch) ,clickedY - y,0,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//_______________2019.03.27 add ysik_________________________________________________________________
//kaminari panel
void ofApp::createKaminariPanel(){
    cout << " Passing createKaminariPanel func " << endl;
    float pitch = 1;
    int LED_Counter = 0;
    
    if (condensedPitch) {
        pitch =1;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID = maxDeviceID()+1;
        int _linID = maxLineID()+1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 17; x++) {
                if(y == 0 && x < 3){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,clickedX - x * pitch ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 1 && 0 <= x && x < 5){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-3*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 2 && 0 <= x && x < 6){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-9*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 3 && 0 <= x && x < 7){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-5*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(3 < y && y < 16){
                    if(y%2 == 0 && 0 <= x && x < 7){
                        led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-12*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                        leds.push_back(l);
                        LED_Counter++;
                    }else if (y%2 != 0 && 0 <= x && x < 7){
                        led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-6*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                        leds.push_back(l);
                        LED_Counter++;
                    }
                }else if(y == 16 && 0 <= x && x < 7){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-13*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 17 && 0 <= x && x < 6){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-9*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 18 && 0 <= x && x < 5){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-15*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 19 && 0 <= x && x < 3){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,LED_Counter,_devID,_linID,(clickedX-15*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }
            }
        }
    }else{
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 17; x++) {
                if(y == 0 && x < 3){
                    led l(LED_Counter,0,LED_Counter,0,0,clickedX - x * pitch ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 1 && 0 <= x && x < 5){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-3*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 2 && 0 <= x && x < 6){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-9*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 3 && 0 <= x && x < 7){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-5*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(3 < y && y < 16){
                    if(y%2 == 0 && 0 <= x && x < 7){
                        led l(LED_Counter,0,LED_Counter,0,0,(clickedX-12*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                        leds.push_back(l);
                        LED_Counter++;
                    }else if (y%2 != 0 && 0 <= x && x < 7){
                        led l(LED_Counter,0,LED_Counter,0,0,(clickedX-6*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                        leds.push_back(l);
                        LED_Counter++;
                    }
                }else if(y == 16 && 0 <= x && x < 7){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-13*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 17 && 0 <= x && x < 6){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-9*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 18 && 0 <= x && x < 5){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-15*pitch) + (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }else if(y == 19 && 0 <= x && x < 3){
                    led l(LED_Counter,0,LED_Counter,0,0,(clickedX-15*pitch) - (x * pitch) ,clickedY - y * pitch,0,1);
                    leds.push_back(l);
                    LED_Counter++;
                }
            }
        }
        
    }
}

//2018.07.31----------------------------------------------------
//--------------------------------------------------------------
void ofApp::createTriangle(){
    float pitch = 1;
    if (condensedPitch) {
        pitch =1.25;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID = maxDeviceID()+1;
        int _linID = maxLineID()+1;
        
        int tri_count = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8 - x; y++) {
                if(x%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,tri_count, _devID,_linID, clickedX + x * pitch, clickedY + y * pitch,0,1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID,tri_count, _devID,_linID, clickedX + x * pitch, clickedY + ((6-x)-y + 1) * pitch,0,1);
                    leds.push_back(l);
                }
                tri_count++;
            }
        }
    }else{
        int tri_count = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8 - x; y++) {
                if(x%2 == 0){
                    led l(tri_count, 0, tri_count, 0, 0, clickedX + x * pitch, clickedY + y * pitch,0,1);
                    leds.push_back(l);
                }else{
                    led l(tri_count, 0, tri_count, 0, 0, clickedX + x * pitch, clickedY + ((6-x)-y + 1) * pitch,0,1);
                    leds.push_back(l);
                }
                tri_count++;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::createPanel_v1(){
    float pitch = 1;
    if (condensedPitch) {
        pitch =1.25;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        //for (int i =0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 16; x++) {
                if(y%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 16*y,_devID,_linID,clickedX + x * pitch ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID,x + 16*y,_devID,_linID,(clickedX+15*pitch) + -(x * pitch) ,clickedY - y * pitch,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }else{
        cout << "led = 0 " << endl;
        //for (int i = 0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 16; x++) {
                if(y%2 == 0){
                    led l(x + 16*y,0,x + 16*y,0,0,clickedX + x * pitch,clickedY - y,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(x + 16*y,0,x + 16*y,0,0,(clickedX+15*pitch) + -(x * pitch) ,clickedY - y,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//2023.6.1 ysik add--------------------------------------------------------------
void ofApp::createPanel_v2(){
    float pitch = 1;
    if (condensedPitch) {
        pitch =1.25;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        //for (int i =0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 16; x++) {
                if(y%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID, x + 16*y, _devID, _linID, clickedX - x * pitch, clickedY + y * pitch, front_back, 1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID, x + 16*y, _devID,_linID, (clickedX-15*pitch) + (x * pitch), clickedY + y * pitch, front_back, 1);
                    leds.push_back(l);
                }
                
            }
        }
    }else{
        cout << "led = 0 " << endl;
        //for (int i = 0; i < 128 ; i++){
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 16; x++) {
                if(y%2 == 0){
                    led l(x + 16*y,0,x + 16*y,0,0,clickedX - x * pitch,clickedY + y,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(x + 16*y,0,x + 16*y,0,0,(clickedX-15*pitch) + (x * pitch) ,clickedY + y,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//2023.6.1 ysik add--------------------------------------------------------------
void ofApp::create15x15Panel(){
    float pitch = 3;
    if (condensedPitch) {
        pitch =1.25;
    }
    if ( leds.size() != 0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _linID = maxLineID()+1;
        //for (int i =0; i < 128 ; i++){
        for (int x = 0; x < 15; x++) {
            for (int y = 0; y < 15; y++) {
                if(x%2 == 0){
                    led l(maxLEDID() + 1,leds[tempID].dancerID, 15*x + y, _devID, _linID, clickedX + x * pitch, clickedY + y * pitch, front_back, 1);
                    leds.push_back(l);
                }else{
                    led l(maxLEDID() + 1,leds[tempID].dancerID, 15*x + y, _devID,_linID, clickedX + (x * pitch), (clickedY+14*pitch) - y * pitch, front_back, 1);
                    leds.push_back(l);
                }
                
            }
        }
    }else{
        cout << "led = 0 " << endl;
        //for (int i = 0; i < 128 ; i++){
        for (int x = 0; x < 15; x++) {
            for (int y = 0; y < 15; y++) {
                if(x%2 == 0){
                    led l(15*x + y,0,15*x + y,0,0,clickedX + x * pitch,clickedY + y * pitch,front_back,1);
                    leds.push_back(l);
                }else{
                    led l(15*x + y,0,15*x + y,0,0,clickedX + (x * pitch) ,(clickedY+14*pitch) - y * pitch,front_back,1);
                    leds.push_back(l);
                }
                
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::createCircle(){
    if ( leds.size() !=0){
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(clickedX - leds[i].x)*(clickedX - leds[i].x) + (clickedY - leds[i].y)*(clickedY - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        int _devID =maxDeviceID()+1;
        int _lineID = maxLineID()+1;
        double rad = (double)(2 * PI) / multiple ;
        
        for (int i =0; i < multiple ; i++){
            float _x = clickedX + (float)diameter * cos(rad * i ) - (float)diameter * sin(rad* i ) ;
            float _y = clickedY + (float)diameter  * sin(rad * i) + (float)diameter  * cos(rad* i ) ;
            led l(maxLEDID() + 1,leds[tempID].dancerID,i,_devID,_lineID,_x,_y,front_back,0);
            leds.push_back(l);
        }
    }else{
        double rad = (double)(2 * PI) / multiple ;
        for (int i =0; i < multiple ; i++){
            float _x = clickedX + (float)diameter * cos(rad * i ) - (float)diameter * sin(rad* i ) ;
            float _y = clickedY + (float)diameter  * sin(rad * i) + (float)diameter  * cos(rad* i ) ;
            led l(i,0,i,0,0,_x ,_y,front_back,0);
            leds.push_back(l);
        }
    }
}
//--------------------------------------------------------------
void ofApp::cpDevice(){
    if (useDevice && preLeds.size() != 0) {
        int _devID =maxDeviceID()+1;
        int _lineID = maxLineID()+1;
        int tempLineID=-1;
        for (int i = 0; i < preLeds.size(); i++){
            if(tempLineID != preLeds[i].lineID){
                _lineID = maxLineID()+1;
                tempLineID = preLeds[i].lineID;
            }
            led l(maxLEDID() + 1,preLeds[i].dancerID,preLeds[i].ledID,_devID,_lineID,preLeds[i].x + 10,preLeds[i].y,front_back,preLeds[i].light_down);
            leds.push_back(l);
        }
    }
}

//--------------------------------------------------------------
void ofApp::cpDancer(){
    int dnsr = -1;
    for (int j =0; j < dancers.size(); j++) {
        bool dnsrflag = false;
        for (int i=0; i < leds.size(); i++) {
            if (leds[i].dancerID == j) {
                dnsrflag = true;
            }
        }
        if (!dnsrflag) {
            dnsr = j;
            break;
        }
    }
    if(dnsr == -1){
        dnsr = dancers.size();
    }
    
    int _lineID = maxLineID()+1;
    for (int i = 0 ; i < leds.size() ; i++) {
        if (leds[i].dancerID == dancerID) {
            led l(maxLEDID() + 1,dnsr,leds[i].ledID,leds[i].deviceID, _lineID,leds[i].x + 270,leds[i].y,leds[i].front,0);
            leds.push_back(l);
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::reflectX(){
    if (useDevice && preLeds.size() != 0) {
        for (int i = 0 ; i < leds.size() ; i++) {
            if (leds[i].deviceID == deviceID) {
                int tempID  =0;
                for (int j = 0; j < preLeds.size(); j++){
                    if (preLeds[j].ledID == leds[i].ledID) {
                        tempID = j;
                    }
                }
                leds[i].x = preLeds[0].x - ( preLeds[tempID].x -preLeds[0].x);
                if (controlledID == i) {
                    ledx =leds[i].x;
                    ledy = leds[i].y;
                }
            }
        }
    }
    useDevice = false;
}
//--------------------------------------------------------------
void ofApp::reflectY(){
    if (useDevice && preLeds.size() != 0) {
        for (int i = 0 ; i < leds.size() ; i++) {
            if (leds[i].deviceID == deviceID) {
                int tempID  =0;
                for (int j = 0; j < preLeds.size(); j++){
                    if (preLeds[j].ledID == leds[i].ledID) {
                        tempID = j;
                    }
                }
                leds[i].y = preLeds[0].y - ( preLeds[tempID].y -preLeds[0].y);
                if (controlledID == i) {
                    ledx =leds[i].x;
                    ledy = leds[i].y;
                }
            }
        }
    }
    useDevice = false;
}
//--------------------------------------------------------------
void ofApp::createDancers(){
    dancers.clear();
    
    int xmin = ofGetWidth();
    int ymin = ofGetHeight();
    int xmax = 0;
    int ymax = 0;
    int dmax =0;
    for (int i = 0 ; i < leds.size() ; i++) {
        if (leds[i].dancerID > dmax) {
            dmax =leds[i].dancerID;
        }
    }
    for (int j =0; j <dmax +1 ; j++) {
        for (int i = 0 ; i < leds.size() ; i++) {
            if (leds[i].dancerID == j) {
                if (leds[i].x < xmin) {
                    xmin = leds[i].x;
                }
                if (leds[i].x > xmax) {
                    xmax = leds[i].x;
                }
                if (leds[i].y < ymin) {
                    ymin = leds[i].y;
                }
                if (leds[i].y > ymax) {
                    ymax = leds[i].y;
                }
            }
        }
        ofRectangle d(xmin,ymin,xmax -xmin,ymax-ymin);
        dancers.push_back(d);
        xmin = ofGetWidth();
        ymin = ofGetHeight();
        xmax = 0;
        ymax = 0;
    }
    
}

//clear LED
//--------------------------------------------------------------
void ofApp::rmLED(){
    vector<led>::iterator it = leds.begin();
    
    for (int i =0; i < controlledID; i++) {
        ++it;
    }
    it = leds.erase(it);
    
    if(leds.size() != 0){
        controlledID = 0;
        dancerID.set(leds[controlledID].dancerID);
        deviceID.set(leds[controlledID].deviceID);
        ledID.set(leds[controlledID].ledID);
        ledx.set(leds[controlledID].x);
        ledy.set(leds[controlledID].y);
        front.set(leds[controlledID].front);
    }
    vector<led>(leds).swap(leds);
    prevID = 0;
    
}

//--------------------------------------------------------------
void ofApp::rmLine(){
    
    vector<led>::iterator it = leds.begin();
    while (it != leds.end()) {
        if ((*it).lineID == lineID && (*it).dancerID == dancerID) {
            it = leds.erase(it);
        }else{
            ++it;
        }
    }
    
    if(leds.size() != 0){
        controlledID = 0;
        dancerID.set(leds[controlledID].dancerID);
        deviceID.set(leds[controlledID].deviceID);
        ledID.set(leds[controlledID].ledID);
        ledx.set(leds[controlledID].x);
        ledy.set(leds[controlledID].y);
        front.set(leds[controlledID].front);
    }
    vector<led>(leds).swap(leds);
    
    prevID = 0;
    
}
//--------------------------------------------------------------
void ofApp::rmDevice(){
    
    vector<led>::iterator it = leds.begin();
    while (it != leds.end()) {
        if ((*it).deviceID == deviceID && (*it).dancerID == dancerID) {
            it = leds.erase(it);
        }else{
            ++it;
        }
    }
    
    if(leds.size() != 0){
        controlledID = 0;
        dancerID.set(leds[controlledID].dancerID);
        deviceID.set(leds[controlledID].deviceID);
        ledID.set(leds[controlledID].ledID);
        ledx.set(leds[controlledID].x);
        ledy.set(leds[controlledID].y);
        front.set(leds[controlledID].front);
    }
    vector<led>(leds).swap(leds);
    
    prevID = 0;
    
}
//--------------------------------------------------------------
void ofApp::rmDancer(){
    vector<led>::iterator it = leds.begin();
    while (it != leds.end()) {
        if ((*it).dancerID == dancerID) {
            it = leds.erase(it);
        }else{
            ++it;
        }
    }
    
    if(leds.size() != 0){
        controlledID = 0;
        dancerID.set(leds[controlledID].dancerID);
        deviceID.set(leds[controlledID].deviceID);
        ledID.set(leds[controlledID].ledID);
        ledx.set(leds[controlledID].x);
        ledy.set(leds[controlledID].y);
        front.set(leds[controlledID].front);
    }
    vector<led>(leds).swap(leds);
    
    prevID = 0;
    
}

//--------------------------------------------------------------
void ofApp::saveImage(){
    mHide = false;
    saveImg = true;
}
//--------------------------------------------------------------
void ofApp::saveLayout(){
    string data = "";
    for (int i = 0; i < dancers.size(); i++) {
        int maxDeviceNum = 0;
        for (int j =0; j < leds.size(); j++) {
            if (leds[j].dancerID == i && leds[j].deviceID > maxDeviceNum) {
                maxDeviceNum = leds[j].deviceID;
            }
        }
        maxDeviceNum ++;
        for(int k =0 ; k < maxDeviceNum; k++){
            for (int j =0; j < leds.size(); j++) {
                if (leds[j].dancerID == i && leds[j].deviceID == k) {
                    data += ofToString(i) + "," + ofToString(leds[j].deviceID) + "," + ofToString(leds[j].ledID)+  "," + ofToString(leds[j].x) + "," + ofToString(leds[j].y) + "," + ofToString(leds[j].front) + "," + ofToString(leds[j].lineID)  + "," + ofToString(leds[j].light_down) + "\n" ;
                }
                
            }
        }
    }
    
    string filePath = "led/suit_led_s" + ofToString(scene) +".csv";
    
    ofFile file(filePath,ofFile::WriteOnly);
    file << data;
    file.close();
    mHide = false;
}


void ofApp::loadLEDLayout(){
    dancers.clear();
    leds.clear();
    
    int _dancerID = 0;
    int _deviceID = 0;
    unsigned int _ledID = 0;
    float _x = 0;
    float _y = 0;
    int _front = 0;
    int _lineID = 0;
    int _z = 0;
    
    string filePath = "led/suit_led_s" + scene.toString() + ".csv";
    //string filePath = "led/0/suit_led_s0.csv";
    //string filePath = "led/10/LEDMANTLE/suit_led_s0.csv";
    
    //Path to the comma delimited file
    //string filePath = "morse_.csv";
    ofFile file(filePath);
    
    if(!file.exists()){
        ofLogError("The file " + filePath + " is missing");
    }
    ofBuffer buffer(file);
    
    //Read file line by line
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        //cout << line << endl;
        //Split line into strings
        vector<string> words = ofSplitString(line, ",");
        
        //cout << words[0] << "," << words[1] << ","<< words[2] << ","<< words[3] << ","<< words[4] << "," << words[5] << "," << words[6] << endl;
        
        
        //Store strings into a custom container
        if (words.size()>=2) {
            
            _dancerID = atoi(words[0].c_str());
            _deviceID = atoi(words[1].c_str());
            _ledID = atoi(words[2].c_str());
            _x = atoi(words[3].c_str());
            _y = atoi(words[4].c_str());
            _front = atoi(words[5].c_str());
            _lineID = atoi(words[6].c_str());
            _z = 0;
            
        }
        //cout << dancer_counter << " // " << _dancerID << endl;
        dancer_counter++;
        led l(leds.size(),_dancerID,_ledID,_deviceID,_lineID,_x,_y,_front, _z);
        leds.push_back(l);
    }
    
    file.close();
    mHide = false;
    isLoadLayout = true;
}

//--------------------------------------------------------------
//ここ何してるか分からないので一回panelから消します　by ysik
void ofApp::invertLEDLine(){
    if (useLine && preLeds.size() != 0) {
        vector<int> temp;
        for (int i = 0; i < preLeds.size(); i++){
            int t = preLeds[i].ledID;
            temp.push_back(t);
        }
        for (int i = 0; i < preLeds.size(); i++){
            preLeds[i].ledID = temp[preLeds.size() - 1 -i];
        }
        
        for (int i = 0 ; i < leds.size() ; i++) {
            for (int j = 0; j < preLeds.size(); j++){
                if (preLeds[j].ID == leds[i].ID) {
                    leds[i].ledID = preLeds[j].ledID;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if( gHide){
        //cout << " gHide" << endl;
        if (!useDevice && leds.size() != 0) {
            leds[controlledID].x = ledx;
            leds[controlledID].y = ledy;
        }
        
        if (useDevice && preLeds.size() != 0) {
            if (controlledDancer == dancerID && controlledDevice == deviceID) {
                
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].deviceID == controlledDevice && leds[i].dancerID == controlledDancer) {
                        int tempID  =0;
                        for (int j = 0; j < preLeds.size(); j++){
                            if (preLeds[j].ID == leds[i].ID) {
                                tempID = j;
                            }
                        }
                        double rad =((double)multiRotate)* PI / 180.0;
                        double rotatedx =  (preLeds[tempID].x - preLeds[0].x) * cos(rad) - (preLeds[tempID].y - preLeds[0].y) * sin(rad) ;
                        double rotatedy =  (preLeds[tempID].x - preLeds[0].x) * sin(rad) + (preLeds[tempID].y - preLeds[0].y) * cos(rad) ;
                        
                        leds[i].x =preLeds[0].x + rotatedx + multix;
                        leds[i].y =preLeds[0].y + rotatedy + multiy;
                        
                        if (controlledID == i) {
                            ledx = leds[i].x;
                            ledy = leds[i].y;
                        }
                    }
                }
            }
        }
        
        if (useLine && preLeds.size() != 0) {
            if (controlledDancer == dancerID && controlledLine == lineID) {
                
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].lineID == controlledLine && leds[i].dancerID == controlledDancer) {
                        int tempID  =0;
                        for (int j = 0; j < preLeds.size(); j++){
                            if (preLeds[j].ID == leds[i].ID) {
                                tempID = j;
                            }
                        }
                        double rad =((double)multiRotate)* PI / 180.0;
                        double rotatedx =  (preLeds[tempID].x - preLeds[0].x) * cos(rad) - (preLeds[tempID].y - preLeds[0].y) * sin(rad) ;
                        double rotatedy =  (preLeds[tempID].x - preLeds[0].x) * sin(rad) + (preLeds[tempID].y - preLeds[0].y) * cos(rad) ;
                        
                        leds[i].x =preLeds[0].x + rotatedx + multix;
                        leds[i].y =preLeds[0].y + rotatedy + multiy;
                        
                        if (controlledID == i) {
                            ledx = leds[i].x;
                            ledy = leds[i].y;
                        }
                    }
                }
            }
        }
        
        if(useDancer && preLeds.size() != 0) {
            cout << "dancer select"<< endl;
            if (controlledDancer == dancerID) {
                //cout << "dancer move"<< endl;
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].dancerID == controlledDancer) {
                        int tempID  =0;
                        for (int j = 0; j < preLeds.size(); j++){
                            if (preLeds[j].ID == leds[i].ID) {
                                tempID = j;
                            }
                        }
                        double rad =((double)multiRotate)* PI / 180.0;
                        double rotatedx =  (preLeds[tempID].x - preLeds[0].x) * cos(rad) - (preLeds[tempID].y - preLeds[0].y) * sin(rad) ;
                        double rotatedy =  (preLeds[tempID].x - preLeds[0].x) * sin(rad) + (preLeds[tempID].y - preLeds[0].y) * cos(rad) ;
                        
                        //leds[i].x = preLeds[0].x + rotatedx + mouseX;
                        //leds[i].y = preLeds[0].y + rotatedy + mouseY;
                        leds[i].x = rotatedx + mouseX;
                        leds[i].y = rotatedy + mouseY;
                        cout << mouseX << " // " << mouseY << endl;
                        
                        if (controlledID == i) {
                            ledx = leds[i].x;
                            ledy = leds[i].y;
                        }
                    }
                }
            }
        }
        
        if(useDancer){
            useLine = false;
            useDevice = false;
            if(!setDeviceHover){
                
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].dancerID == dancerID) {
                        leds[i].hover = true;
                        led l(leds[i].ID,leds[i].dancerID,leds[i].ledID,leds[i].deviceID,leds[i].lineID,leds[i].x,leds[i].y,leds[i].front,leds[i].light_down);
                        preLeds.push_back(l);
                    }
                }
                controlledDancer = dancerID;
                setDeviceHover = true;
            }
            
            
        }else if(useDevice){
            useLine = false;
            useDancer = false;
            if(!setDeviceHover){
                
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].deviceID == deviceID && leds[i].dancerID == dancerID) {
                        leds[i].hover = true;
                        led l(leds[i].ID,leds[i].dancerID,leds[i].ledID,leds[i].deviceID,leds[i].lineID,leds[i].x,leds[i].y,leds[i].front,leds[i].light_down);
                        preLeds.push_back(l);
                    }
                }
                controlledDevice = deviceID;
                controlledDancer = dancerID;
                setDeviceHover = true;
            }
            
        }else if(useLine){
            useDancer = false;
            useDevice = false;
            if(!setDeviceHover){
                
                for (int i = 0 ; i < leds.size() ; i++) {
                    if (leds[i].lineID == lineID && leds[i].dancerID == dancerID) {
                        leds[i].hover = true;
                        led l(leds[i].ID,leds[i].dancerID,leds[i].ledID,leds[i].deviceID,leds[i].lineID,leds[i].x,leds[i].y,leds[i].front,leds[i].light_down);
                        preLeds.push_back(l);
                        
                    }
                }
                controlledLine = lineID;
                controlledDancer = dancerID;
                setDeviceHover = true;
            }
        }else{
            if(setDeviceHover){
                for (int i = 0 ; i < leds.size() ; i++) {
                    leds[i].hover = false;
                }
                setDeviceHover = false;
                multix = 0;
                multiy = 0;
                multiRotate =0;
                preLeds.clear();
                
            }
        }
    }
    
    if(push_command){
        if(push_s){
            saveLayout();
            isSave =true;
            textSaveCount=255;
        }
    }
    //for auto save
    int nowMinute = ofGetMinutes();
    if(editMode == true) {
        if(nowMinute == 0 ||nowMinute == 15 ||nowMinute == 30 ||nowMinute == 45 ) {
            if(isAutoSave == false) {
                //autoSave
                saveLayout();
                isAutoSave = true;
                isSave = true;
            }
        }
        if(nowMinute == 5 ||nowMinute == 20 ||nowMinute == 35 ||nowMinute == 50 ) {
            isAutoSave = false;
        }
    }
    
}
//--------------------------------------------------------------
void ofApp::oneLine(){
    for (int d = 0 ; d < dancers.size() ; d++) {
        int count =0;
        for (int i = 0 ; i < leds.size() ; i++) {
            if(leds[i].dancerID == d){
                leds[i].x = count*2 + 30;
                leds[i].y = d*60 +150;
                count++;
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    if (editMode) {
        ofBackground(255,255,255);
        if(refImgOn){
            ofSetColor(255, 255, 255,20);
            ofRectangle(0, 0, refImg.getWidth(), refImg.getHeight());
            ofSetColor(255, 255, 255,100);
            refImg.draw(0, 0, refImg.getWidth(), refImg.getHeight());
        }
        
        ofSetColor(245, 245, 245);
        for (int i =0;i < ofGetWidth();i +=20 ){
            //ofDrawLine(i, 0, i, ofGetHeight());
        }
        for (int i =0;i < ofGetHeight();i +=20 ){
            //ofDrawLine(0, i, ofGetWidth(), i);
        }
        ofSetColor(255, 255, 255);
        editImage.draw(4,4, 80, 20);
        
        if(bdraw_all == true || front_back == 0 || front_back == 1){
            for (int i = 0 ; i < leds.size() ; i++) {
                //font_frontback.drawString("front & back",100,30);
                //allImg.draw(100,4, 200/2, 50/2);
                leds[i].draw2();
            }
        }
        /*else{
            for (int i = 0 ; i < leds.size() ; i++) {
                if(front_back == 0){
                    //font_frontback.drawString("front",100,30);
                    frontImg.draw(100,4, 200/2, 50/2);
                    if(leds[i].front == 0){
                        leds[i].draw2();
                        //cout << "front" << endl;
                    }
                }else if(front_back == 1){
                    //font_frontback.drawString("back",100,30);
                    backImg.draw(100,4, 200/2, 50/2);
                    if(leds[i].front == 1){
                        leds[i].draw2();
                        //cout << "back" << endl;
                    }
                }
            }
        }*/
        
        for (int i = 0 ; i < dancers.size() ; i++) {
            if(dancers[i].width >=0){
                //ofSetColor(250, 50 + i * 5, 50 + i* 5);
                ofSetColor(250, 50, 50);
                myfont.drawString(ofToString(i),dancers[i].x - 5 , dancers[i].y - 8);
                ofDrawLine(dancers[i].x -3, dancers[i].y -3,dancers[i].x + dancers[i].width + 3,  dancers[i].y - 3);
                ofDrawLine(dancers[i].x + dancers[i].width + 3, dancers[i].y -3, dancers[i].x + dancers[i].width + 3, dancers[i].y + dancers[i].height +3);
                ofDrawLine(dancers[i].x + dancers[i].width + 3, dancers[i].y + dancers[i].height +3, dancers[i].x - 5, dancers[i].y + dancers[i].height +5);
                ofDrawLine(dancers[i].x - 3, dancers[i].y -3, dancers[i].x - 3, dancers[i].y + dancers[i].height +3);
            }
            
        }
        
    }else{
        ofBackground(0,0,0);
        ofSetColor(255,255,255);
        sceneImage.draw(4,4, 80, 20);
        myfont.drawString(scene.toString(), 100, 20);
        int boxWidth = 20;
        int boxHeight = 10;
        
        for (int i=0; i <maxScene; i++) {
            if(i == scene)
                {
                square.draw(130 + i*boxWidth*1.25 ,4, boxWidth, boxWidth);
                }else
                    {
                    squareEmpty.draw(130 + i*boxWidth*1.25 ,4, boxWidth, boxWidth);
                    }
        }
        
        for (int i = 0 ; i < dancers.size() ; i++) {
            if(dancers[i].width >=0){
                ofSetColor(150,150,150);
                int maxheight=0;
                for (int j = 0 ; j < dancers.size() ; j++) {
                    if(maxheight < dancers[j].height){
                        maxheight = dancers[j].height;
                    }
                }
                
                int dnsrWidth= dancers[0].width;
                int dnsrHeight=maxheight;
                int margin = 3;
                string label = ofToString(i) ;
                myfont.drawString(label,dancers[i].x -margin , dancers[i].y -margin*2);
                ofDrawLine(dancers[i].x - margin, dancers[i].y -margin, dancers[i].x + dnsrWidth + margin, dancers[i].y - margin);
                ofDrawLine(dancers[i].x + dnsrWidth + margin, dancers[i].y -margin, dancers[i].x + dnsrWidth + margin, dancers[i].y + dnsrHeight +margin);
                ofDrawLine(dancers[i].x + dnsrWidth + margin, dancers[i].y + dnsrHeight +margin, dancers[i].x - margin, dancers[i].y + dnsrHeight +margin);
                ofDrawLine(dancers[i].x - margin, dancers[i].y -margin, dancers[i].x - margin, dancers[i].y + dnsrHeight +margin);
            }
            
        }
        
        for (int i = 0 ; i < leds.size() ; i++) {
            leds[i].draw();
        }
    }
    
    //save img data
    if(saveImg){
        img.grabScreen(0,0,1920,1080);
        string fileName = "scene/scene" + ofToString(scene)+".png";
        img.save(fileName);
        saveImg = false;
    }
    ofSetColor(255, 255, 255);
    if( gHide ){
        gui.draw();
        //useDancer = false;
    }
    if( eHide ){
        edit.draw();
    }
    if ( mHide) {
        menu.draw();
    }
    
    if(isSave) {
        textSaveCount = textSaveCount -10;
        string saveText = "SAVE" ;
        ofSetColor(0,0,250,textSaveCount);
        saveFont.drawString(saveText,1750 , 1000);
        ofSetColor(255,255,255);
        if(textSaveCount == 0) {
            isSave = false;
            textSaveCount = 255;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == OF_KEY_UP ){
        incrementYM();
    }else if( key == OF_KEY_DOWN ){
        incrementYP();
    }else if ( key == OF_KEY_RIGHT ){
        incrementXP();
    }else if( key == OF_KEY_LEFT ){
        incrementXM();
    }else if(key == '@'){
        gHide = false;
        mHide = false;
        eHide = false;
        cout << "all false" << endl;
        setup();
    }else if (key == 'A'){
        for (int i = 0 ; i < leds.size() ; i++) {
            if (leds[i].front == 1) {
                cout << "pass ? shifrt A = " << i <<  endl;
                //led l(leds[i].ID,leds[i].dancerID,leds[i].ledID,leds[i].deviceID,leds[i].lineID,leds[i].x,leds[i].y-130,leds[i].front,leds[i].light_down);
                //preLeds.push_back(l);
                leds[i].y = leds[i].y - 130;
            }
        }
    }else if (key == 'P'){
        cout << "press P"<<  endl;
        for (int i = 0 ; i < leds.size() ; i++) {
            cout << "press P - i = " << i <<  endl;
            cout << "leds[i].front = " << leds[i].front << endl;
            if (leds[i].front == 1) {
                cout << "press P == 1 = " << i <<  endl;
                cout  << "back led = " << leds[i].front << endl;
            }
        }
    }else if(key == OF_KEY_COMMAND){
        push_command = true;
    }else if(key == 's'){
        push_s = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_COMMAND){
        push_command = false;
    }else if(key == 's'){
        push_s = false;
    }
    
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    ofShowCursor();
    if (editMode) {
        float minDistance = MAXFLOAT;
        int tempID =0;
        for (int i = 0 ; i < leds.size(); i++) {
            float tempDistance =(x - leds[i].x)*(x - leds[i].x) + (y - leds[i].y)*(y - leds[i].y);
            if ( tempDistance < minDistance) {
                minDistance = tempDistance;
                tempID =i;
            }
        }
        if (minDistance < 50) {
            leds[tempID].hover =true;
            if (tempID != prevID) {
                leds[prevID].hover =false;
                prevID = tempID;
            }
            gui.setPosition(x + 5,y );
            controlledID = prevID;
            dancerID.set(leds[controlledID].dancerID);
            deviceID.set(leds[controlledID].deviceID);
            lineID.set(leds[controlledID].lineID);
            ledID.set(leds[controlledID].ledID);
            ledx.set(leds[controlledID].x);
            ledy.set(leds[controlledID].y);
            front.set(leds[controlledID].front);
            useDevice.set(false);
            useLine.set(false);
            gHide = true;
            mHide = false;
            eHide = false;
        }else {
            //leds[prevID].hover =false;
            for (int i = 0 ; i < leds.size(); i++) {
                leds[i].hover = false;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(useDancer){
        useDancer = false;
    }
    
    if(button == 2 && leds.size() != 0  &&leds[prevID].hover == true )
        {
        
        gui.setPosition(x + 10,y );
        controlledID = prevID;
        dancerID.set(leds[controlledID].dancerID);
        deviceID.set(leds[controlledID].deviceID);
        ledID.set(leds[controlledID].ledID);
        ledx.set(leds[controlledID].x);
        ledy.set(leds[controlledID].y);
        front.set(leds[controlledID].front);
        useDevice.set(false);
        gHide = true;
        mHide = false;
        eHide = false;
        
        return;
        }else if(button == 2 && !editMode){
            clickedX = x;
            clickedY =y;
            menu.setPosition(x + 10,y );
            mHide = true;
            gHide = false;
            eHide = false;
            return;
            
        }else if(button == 2 && editMode){
            clickedX = x;
            clickedY = y;
            edit.setPosition(x + 10,y );
            eHide = true;
            mHide = false;
            gHide = false;
            return;
            
        }
    
    if(!gui.getShape().inside(x, y))
        {
        gHide = false;
        }
    if(!menu.getShape().inside(x, y))
        {
        mHide = false;
        }
    if(!edit.getShape().inside(x, y))
        {
        eHide = false;
        }
    
    createDancers();
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



