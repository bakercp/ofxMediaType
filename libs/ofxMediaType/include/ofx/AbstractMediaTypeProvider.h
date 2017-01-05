//
// Copyright (c) 2009 Christopher Baker <http://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "Poco/File.h"
#include "Poco/Net/MediaType.h"
#include "ofTypes.h"


namespace ofx {


/// \brief A base class for providing Media Type info.
class AbstractMediaTypeProvider
{
public:
    /// \brief A shared pointer to the AbstractMediaTypeProvider.
    typedef std::shared_ptr<AbstractMediaTypeProvider> SharedPtr;

    /// \brief Create an AbstractMediaTypeProvider.
    AbstractMediaTypeProvider()
    {
    }

    /// \brief Destroy the AbstractMediaTypeProvider.
    virtual ~AbstractMediaTypeProvider()
    {
    }

    /// \brief Attempt to get the MediaType for the given path.
    /// \param path The path of the file to test.
    /// \returns The MediaType for the given path on success, and the
    ///        default media type on failure.
    virtual Poco::Net::MediaType getMediaTypeForPath(const Poco::Path& path) const = 0;

    /// Returns a std::string description for a given Poco::Path.
    /// Archived and compressed files are searched if examineCompressed
    /// is set to true.
    virtual std::string getMediaDescription(const Poco::Path& path,
                                            bool examineCompressed) const = 0;

};


} // namespace ofx
