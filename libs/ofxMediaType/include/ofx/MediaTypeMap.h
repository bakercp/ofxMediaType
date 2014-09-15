// =============================================================================
//
// Copyright (c) 2009-2014 Christopher Baker <http://christopherbaker.net>
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
#include "ofx/AbstractMediaTypeProvider.h"


namespace ofx {


struct MediaTypeComparator
{
    bool operator()(const Poco::Net::MediaType& a,
                    const Poco::Net::MediaType& b) const
    {
        return a.toString().compare(b.toString());
    }
};

/// \brief MediaTypeMap returns a file's MIME type based on its file suffix.
///
/// MediaTypeMap is a class that attempts to return MIME Type information for a
/// given file using the file's suffix.  The default functionality loads an
/// Apache mime.types file to create the database.  Database entries can also be
/// added and removed manually.
class MediaTypeMap: public AbstractMediaTypeProvider
{
public:
    /// \brief A shared pointer typedef.
    typedef std::shared_ptr<MediaTypeMap> SharedPtr;

    /// \brief A map of file extension keys and their MIME type values.
    typedef std::map<std::string, Poco::Net::MediaType> FileExtensionToMediaTypeMap;

    /// \brief A map of file extension keys and their MIME type values.
    typedef std::map<Poco::Net::MediaType, std::vector<std::string>, MediaTypeComparator> MediaTypeToFileExtensionMap;

    /// \brief A const iterator for the FileExtensionToMediaTypeMap type.
    typedef FileExtensionToMediaTypeMap::const_iterator FileExtensionConstIterator;

    /// \brief A const iterator for the FileExtensionToMediaTypeMap type.
    typedef MediaTypeToFileExtensionMap::const_iterator MediaTypeConstIterator;

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

    /// \brief Get the list of file extensions for a given media type.
    /// \param mediaType the type to search for.
    /// \returns A vector of possible file extensions.
    std::vector<std::string> getFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const;

    /// \brief Get the best file extension for a given media type.
    /// \param mediaType the type to search for.
    /// \returns A the best possible file extensions.
    std::string getBestFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const;

    /// \brief Add an entry to the media type database.
    /// \param suffix is the key.
    /// \param mediaType is the associated MediaType.
    void add(const std::string& suffix, const Poco::Net::MediaType& mediaType);

    /// \brief Load an Apache mime.types file from the given input stream.
    /// \param inputStream An input stream to the mime.types file.
    bool load(std::istream& inputStream);

    /// \brief Remove all entries from the loaded mime types map database.
    void clear();

    /// \brief Get the default media type. Usually `application/octet-stream`
    /// \returns the default media type.  Usually `application/octet-stream`
    Poco::Net::MediaType getDefaultMediaType() const;

    /// \brief Sets the default media type used for unmatched file suffixes.
    /// \param defaultMediaType The default media type.
    void setDefaultMediaType(const Poco::Net::MediaType& defaultMediaType);

    /// \brief Get the default file extension.
    /// \returns the default file extension.
    std::string getDefaultFileExtension() const;

    /// \brief Sets the default file extension used for unmatched Media Type.
    /// \param defaultFileExtension The default file extension.
    void setDefaultFileExtension(const std::string& defaultFileExtension);

    /// \brief Get a the default instance of the MediaTypeMap.
    /// \returns the default shared instance.
    static SharedPtr getDefault();

    /// \brief Parse Apache mime.types files.
    /// \param inputStream an input stream containing Apache mime.types.
    /// \param mediaTypeToFileExtensionMap The MediaTypeToFileExtensionMap to be filled.
    /// \param fileExtensionToMediaTypeMap The FileExtensionToMediaTypeMap to be filled.
    /// returns true iff successful.
    static bool parse(std::istream& inputStream,
                      FileExtensionToMediaTypeMap& fileExtensionToMediaTypeMap,
                      MediaTypeToFileExtensionMap& mediaTypeToFileExtensionMap);

    /// \brief The default MIME type used for unmatched files.
    static const std::string DEFAULT_MEDIA_TYPE;

    /// \brief The default MIME type used for unmatched media types.
    static const std::string DEFAULT_FILE_EXTENSION;

    /// \brief The default path location for the Apache mime types file.
    static const std::string DEFAULT_APACHE_MIME_TYPES_PATH;

private:
    /// \brief The mapping between file suffix and media type.
    FileExtensionToMediaTypeMap _fileExtensionToMediaTypeMap;

    /// \brief The mapping between media type and file suffix.
    MediaTypeToFileExtensionMap _mediaTypeToFileExtensionMap;

    /// \brief The default media type assigned when it is unknown.
    Poco::Net::MediaType _defaultMediaType;

    /// \brief The default file extension assigned when it is unknown.
    std::string _defaultFileExtension;

};


} // namespace ofx
