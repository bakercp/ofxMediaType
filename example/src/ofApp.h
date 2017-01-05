//
// Copyright (c) 2009 Christopher Baker <http://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofMain.h"
#include "ofxMediaType.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();

    void dragEvent(ofDragInfo dragInfo);

    std::string instructions;

    Poco::Path path;
    std::string mediaType;

    std::vector<std::string> fileExtensions;

    std::shared_ptr<ofx::MediaTypeMap> mediaTypeMap;
    
};
