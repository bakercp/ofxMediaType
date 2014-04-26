// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
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


#pragma once


#include <sstream>
#include <string>
#include <map>
#include "Poco/File.h"
#include "Poco/Mutex.h"
#include "Poco/Path.h"
#include "Poco/StringTokenizer.h"
#include "Poco/Net/MediaType.h"
#include "ofLog.h"
#include "ofx/Media/AbstractMediaTypeProvider.h"


namespace ofx {
namespace Media {


/// \brief MediaTypeMap returns a file's MIME type based on its file suffix.
/// \details MediaTypeMap is a class that attempts to return MIME Type
///          information for a given file using the file's suffix.  The
///          default functionality loads an Apache mime.types file to
///          create the database.  Database entries can also be added and
///          removed manually.
class MediaTypeMap: public AbstractMediaTypeProvider
{
public:
    /// \brief A shared pointer typedef.
    typedef std::shared_ptr<MediaTypeMap> SharedPtr;

    /// \brief A map of file suffix keys and their MIME type values.
    typedef std::map<std::string, Poco::Net::MediaType> FileSuffixToMediaTypeMap;

    /// \brief A const iterator for the FileSuffixToMediaTypeMap type.
    typedef FileSuffixToMediaTypeMap::const_iterator ConstIterator;

    /// \brief Create a default MediaType map.
    MediaTypeMap();

    /// \brief Create a default MediaType map.
    /// \param mimeTypesFile The location of the Apache mime.types file.
    MediaTypeMap(const std::string& mimeTypesFile);

    /// \brief Create a default MediaType map
    /// \param mimeTypesFile The location of the Apache mime.types file.
    /// \param defaultMediaType The default media type used for
    ///        unrecognized files.
    MediaTypeMap(const std::string& mimeTypesFile,
                 const std::string& defaultMediaType);

    /// \brief Destroy the MediaTypeMap.
    virtual ~MediaTypeMap();

    /// \brief Attempt to get the MediaType for the given path.
    /// \param path The path of the file to test.
    /// \returns The MediaType for the given path on success, and the
    ///        default media type on failure.
    Poco::Net::MediaType getMediaTypeForPath(const Poco::Path& path) const;

    /// \brief Get the description of the media item at the given path.
    /// \param path The path of the file to test.
    /// \param examineCompressed look inside of compressed files.
    /// \returns the media description for the given path.
    std::string getMediaDescription(const Poco::Path& path,
                                    bool examineCompressed) const;

    /// \brief Add an entry to the media type database.
    /// \param suffix is the key.
    /// \param mediaType is the associated MediaType.
    void add(const std::string& suffix, const Poco::Net::MediaType& mediaType);

    /// \brief Load an Apache mime.types file from the given input stream.
    /// \param inputStream An input stream to the mime.types file.
    void load(std::istream& inputStream);

    /// \brief Remove all entries from the loaded mime types map database.
    void clear();

    /// \returns the default media type.  Usually `application/octet-stream`
    Poco::Net::MediaType getDefaultMediaType() const;

    /// \brief Sets the default media type used for unmatched file suffixes.
    /// \param defaultMediaType The default media type.
    void setDefaultMediaType(const Poco::Net::MediaType& defaultMediaType);

    /// \brief Get a the default instance of the MediaTypeMap.
    /// \returns the default shared instance.
    static SharedPtr getDefault();

    static FileSuffixToMediaTypeMap parse(std::istream& inputStream);
        ///< Parse Apache mime.types files and return the corresponding
        ///< FileSuffixToMediaTypeMap.

    static const std::string DEFAULT_MEDIA_TYPE;
        ///< The default MIME type used for unmatched files.

    static const std::string DEFAULT_APACHE_MIME_TYPES_PATH;
        ///< The default path location for the Apache mime types file.

private:
    FileSuffixToMediaTypeMap _map;
    Poco::Net::MediaType _defaultMediaType;

};


} } // namespace ofx::Media
