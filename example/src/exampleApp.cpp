#include "exampleApp.h"


//--------------------------------------------------------------
void exampleApp::setup(){
    instructions = "Drag file onto window for more info.";
    mediaType = "";

    // simulate a drag for platforms that don't support drag events
    ofDragInfo simulatedDrag;
    simulatedDrag.files.push_back(ofToDataPath("automat.ttf"));
    ofNotifyDragEvent(simulatedDrag);
}

//--------------------------------------------------------------
void exampleApp::draw(){
    ofBackground(0);

    // draw instructions and info
    ofDrawBitmapString(instructions, 10, 15);
    ofDrawBitmapString(file.path(), 10, 45);
    ofDrawBitmapString(mediaType, 10, 75);
}

//--------------------------------------------------------------
void exampleApp::dragEvent(ofDragInfo dragInfo) {

    if(!dragInfo.files.empty()) {
        file = Poco::File(dragInfo.files[0]);
        mediaType = mediaMap.getMediaTypeForFile(file).toString();
    }
    
}
