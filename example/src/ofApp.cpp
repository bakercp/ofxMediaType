//
// Copyright (c) 2009 Christopher Baker <http://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    mediaTypeMap = ofx::MediaTypeMap::getDefault();

    instructions = "Drag file onto the window for more info.";
    mediaType = "";

    // simulate a drag event for platforms that don't yet support drag events
    ofDragInfo simulatedDrag;
    simulatedDrag.files.push_back(ofToDataPath("automat.ttf"));
    dragEvent(simulatedDrag);
}


void ofApp::draw()
{
    ofBackground(0);

    // draw instructions and info
    ofDrawBitmapString(instructions, 10, 15);

    ofDrawBitmapString("Path:", 10, 45);
    ofDrawBitmapString("\t" + path.toString(), 10, 60);

    ofDrawBitmapString("Media Type:", 10, 90);
    ofDrawBitmapString("\t" + mediaType, 10, 105);

    ofDrawBitmapString("File extensions for media type:", 10, 135);

    for (std::size_t i = 0; i < fileExtensions.size(); ++i)
    {
        ofDrawBitmapString("\t*." + fileExtensions[i], 10, 150 + (i * 15));
    }
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
    if (!dragInfo.files.empty())
    {
        path = dragInfo.files[0];

        cout << path.getFileName() << endl;

        mediaType = mediaTypeMap->getMediaTypeForPath(path).toString();
        fileExtensions = mediaTypeMap->getFileExtensionsForMediaType(mediaType);
    }
}
