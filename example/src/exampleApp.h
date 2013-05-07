#pragma once

#include "ofMain.h"

#include "Poco/File.h"
#include "Poco/Net/MediaType.h"
#include "MediaTypeMap.h"

class exampleApp : public ofBaseApp {
public:
    void setup();
    void draw();

    void dragEvent(ofDragInfo dragInfo);

    ofx::Media::MediaTypeMap mediaMap;

    string instructions;

    Poco::File file;
    string mediaType;
    
};
