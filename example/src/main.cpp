//
// Copyright (c) 2009 Christopher Baker <http://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


int main()
{
	ofSetupOpenGL(1024, 480, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
