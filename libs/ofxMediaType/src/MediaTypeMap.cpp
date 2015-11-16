// =============================================================================
//
// Copyright (c) 2009 Christopher Baker <http://christopherbaker.net>
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


#include "ofx/MediaTypeMap.h"
#include "ofFileUtils.h"
#include "Poco/UTF8String.h"


namespace ofx {


const std::string MediaTypeMap::DEFAULT_MEDIA_TYPE = "application/octet-stream";
const std::string MediaTypeMap::DEFAULT_APACHE_MIME_TYPES_PATH = "media/mime.types";
const std::string MediaTypeMap::DEFAULT_FILE_EXTENSION = "bin";


MediaTypeMap::MediaTypeMap():
    _defaultMediaType(DEFAULT_MEDIA_TYPE),
    _defaultFileExtension(DEFAULT_FILE_EXTENSION)
{
    ofBuffer buffer = ofBufferFromFile(DEFAULT_APACHE_MIME_TYPES_PATH);

    if (0 == buffer.size())
    {
        ofLogError("MediaTypeMap::MediaTypeMap") << "Media Types Buffer is Empty.";
    }

    std::stringstream ss;
    ss << buffer;
    load(ss);
}


MediaTypeMap::MediaTypeMap(const std::string& mimeTypesFile):
    _defaultMediaType(DEFAULT_MEDIA_TYPE)
{
    ofBuffer buffer = ofBufferFromFile(mimeTypesFile);

    if (0 == buffer.size())
    {
        ofLogError("MediaTypeMap::MediaTypeMap") << "Media Types Buffer is Empty.";
    }

    std::stringstream ss;
    ss << buffer;
    load(ss);
}


MediaTypeMap::MediaTypeMap(const std::string& mimeTypesFile,
                           const std::string& defaultMediaType):
    _defaultMediaType(defaultMediaType)
{
    ofBuffer buffer = ofBufferFromFile(mimeTypesFile);

    if (0 == buffer.size())
    {
        ofLogError("MediaTypeMap::MediaTypeMap") << "Media Types Buffer is Empty.";
    }

    std::stringstream ss;
    ss << buffer;
    load(ss);
}


MediaTypeMap::~MediaTypeMap()
{
}


Poco::Net::MediaType MediaTypeMap::getMediaTypeForPath(const Poco::Path& path) const
{
    Poco::File file(path);

    if (file.exists() && file.isDirectory())
    {
        return Poco::Net::MediaType("inode/directory");
    }
    else
    {
        FileExtensionConstIterator iter = _fileExtensionToMediaTypeMap.find(Poco::UTF8::toLower(path.getExtension()));

        if (iter != _fileExtensionToMediaTypeMap.end())
        {
            return (*iter).second;
        }
        else
        {
            return _defaultMediaType;
        }
    }
}


std::string MediaTypeMap::getMediaDescription(const Poco::Path& path,
                                              bool) const
{
    return getMediaTypeForPath(path).toString();
}


std::vector<std::string> MediaTypeMap::getFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const
{
    std::vector<std::string> fileExtensions;

    MediaTypeConstIterator iter = _mediaTypeToFileExtensionMap.begin();

    while (iter != _mediaTypeToFileExtensionMap.end())
    {
        if (mediaType.matches(iter->first))
        {
            fileExtensions = iter->second;

            if (fileExtensions.empty())
            {
                fileExtensions.push_back(_defaultFileExtension);
                return fileExtensions;
            }
            else
            {
                return fileExtensions;
            }
        }

        ++iter;
    }

    fileExtensions.push_back(_defaultFileExtension);

    return fileExtensions;

}


std::string MediaTypeMap::getBestFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const
{
    std::vector<std::string> fileExtensions = getFileExtensionsForMediaType(mediaType);

    if (fileExtensions.empty())
    {
        return _defaultFileExtension;
    }
    else
    {
        return fileExtensions[0];
    }
}


void MediaTypeMap::add(const std::string& suffix,
                       const Poco::Net::MediaType& mediaType)
{
    _fileExtensionToMediaTypeMap.insert(std::make_pair(suffix, mediaType.toString()));

    std::vector<std::string> fileExtensions = getFileExtensionsForMediaType(mediaType);

    std::vector<std::string>::iterator iter = fileExtensions.begin();

    while (iter != fileExtensions.end())
    {
        if (*iter == suffix) return; // Already exists.
        ++iter;
    }

    fileExtensions.push_back(suffix);

    _mediaTypeToFileExtensionMap.insert(std::make_pair(mediaType.toString(), fileExtensions));

}


bool MediaTypeMap::load(std::istream& inputStream)
{
    return parse(inputStream,
                 _fileExtensionToMediaTypeMap,
                 _mediaTypeToFileExtensionMap);
}


void MediaTypeMap::clear()
{
    _mediaTypeToFileExtensionMap.clear();
    _fileExtensionToMediaTypeMap.clear();
}


Poco::Net::MediaType MediaTypeMap::getDefaultMediaType() const
{
    return _defaultMediaType;
}


void MediaTypeMap::setDefaultMediaType(const Poco::Net::MediaType& defaultMediaType)
{
    _defaultMediaType = defaultMediaType;
}


std::string MediaTypeMap::getDefaultFileExtension() const
{
    return _defaultFileExtension;
}


void MediaTypeMap::setDefaultFileExtension(const std::string& defaultFileExtension)
{
    _defaultFileExtension = defaultFileExtension;
}


std::shared_ptr<MediaTypeMap> MediaTypeMap::getDefault()
{
    static std::shared_ptr<MediaTypeMap> ptr = std::make_shared<MediaTypeMap>();
    return ptr;
}


bool MediaTypeMap::parse(std::istream& inputStream,
                         FileExtensionToMediaTypeMap& fileExtensionToMediaTypeMap,
                         MediaTypeToFileExtensionMap& mediaTypeToFileExtensionMap)
{
    fileExtensionToMediaTypeMap.clear();
    mediaTypeToFileExtensionMap.clear();

    std::string line;

    while (std::getline(inputStream, line))
    {
        Poco::trimInPlace(line);

        if (line.empty() || '#' == line[0]) continue;

        int tokenizerFlags = Poco::StringTokenizer::TOK_TRIM |
                             Poco::StringTokenizer::TOK_IGNORE_EMPTY;

        Poco::StringTokenizer tokens(line, "\t", tokenizerFlags);

        if (2 == tokens.count())
        {
            std::string mediaType = tokens[0];

            std::vector<std::string> fileExtensions;

            Poco::StringTokenizer suffixTokens(tokens[1], " ", tokenizerFlags);
            Poco::StringTokenizer::Iterator iter = suffixTokens.begin();

            while (iter != suffixTokens.end())
            {
                fileExtensions.push_back(*iter);
                fileExtensionToMediaTypeMap.insert(std::make_pair(*iter,
                                                                  mediaType));
                ++iter;
            }

            mediaTypeToFileExtensionMap.insert(std::make_pair(mediaType, fileExtensions));
        }
    }
    
    return true;
}


} // namespace ofx
