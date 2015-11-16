ofxMediaType
============

Compatible with openFrameworks 0.9.0+

For previous version of openFrameworks (e.g. 0.8.4), see https://github.com/bakercp/ofxMediaType/releases

Generate all project files using the openFrameworks Project Generator.

This is an addon that makes it easy to discover MIME types.  The basic implementation (contained in this addon) uses the Apache Mime Types definitions found here:

http://svn.apache.org/viewvc/httpd/httpd/trunk/docs/conf/mime.types?view=co

Other MIME-type discovery implementations (e.g. via libMagic, libAV) etc can easily be created by implementing `BaseMediaTypeProvider`).  See https://github.com/bakercp/ofxLibmagic for an example.
