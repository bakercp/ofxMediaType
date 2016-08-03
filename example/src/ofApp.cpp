// =============================================================================
//
// Copyright (c) 2009-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


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
