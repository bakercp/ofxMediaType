//// =============================================================================
////
//// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
////
//// Permission is hereby granted, free of charge, to any person obtaining a copy
//// of this software and associated documentation files (the "Software"), to deal
//// in the Software without restriction, including without limitation the rights
//// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//// copies of the Software, and to permit persons to whom the Software is
//// furnished to do so, subject to the following conditions:
////
//// The above copyright notice and this permission notice shall be included in
//// all copies or substantial portions of the Software.
////
//// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//// THE SOFTWARE.
////
//// =============================================================================
//
//
//#include "MediaTypeMap.h"
//#include "ApacheMimeTypes.h"
//
//
//namespace ofx {
//namespace Media {
//
//
//const std::string MediaTypeMap::DEFAULT_MEDIA_TYPE = "application/octet-stream";
//
//
////------------------------------------------------------------------------------
//MediaTypeMap::MediaTypeMap():
//    _defaultMediaType(DEFAULT_MEDIA_TYPE)//,
////    _map(defaultMediaTypeMap)
//{
//}
//
////------------------------------------------------------------------------------
//MediaTypeMap::~MediaTypeMap()
//{
//}
//
////------------------------------------------------------------------------------
//Poco::Net::MediaType MediaTypeMap::getMediaTypeForFile(const Poco::File& file) const
//{
//    try
//    {
//        if(file.isDirectory())
//        {
//            Poco::Path path(file.path());
//            path = path.makeDirectory();
//            return getMediaTypeForPath(path);
//        }
//    }
//    catch (Poco::IOException e)
//    {
//    }
//
//    return getMediaTypeForPath(Poco::Path(file.path()));
//}
//
////------------------------------------------------------------------------------
//Poco::Net::MediaType MediaTypeMap::getMediaTypeForSuffix(const std::string& suffix) const
//{
//    ConstIterator iter = _map.find(suffix);
//
//    if(iter != _map.end())
//    {
//        return (*iter).second;
//    }
//    else
//    {
//        return _defaultMediaType;
//    }
//}
//
////------------------------------------------------------------------------------
//Poco::Net::MediaType MediaTypeMap::getMediaTypeForPath(const Poco::Path& path) const
//{
//    if(path.isDirectory())
//    {
//        return Poco::Net::MediaType("inode/directory");
//    }
//    else
//    {
//        return getMediaTypeForSuffix(path.getExtension());
//    }
//}
//
////------------------------------------------------------------------------------
//std::string MediaTypeMap::getMediaDescription(const Poco::File& file,
//                                              bool bExamineCompressed) const
//{
//    return getMediaTypeForFile(file).toString();
//}
//
////------------------------------------------------------------------------------
//void MediaTypeMap::add(const std::string& suffix,
//                       const Poco::Net::MediaType& mediaType)
//{
//    _map.insert(std::make_pair(suffix,mediaType));
//}
//
////------------------------------------------------------------------------------
//void MediaTypeMap::add(std::istream& inputStream)
//{
//    FileSuffixToMediaTypeMap _newMap = parse(inputStream);
//    _map.insert(_newMap.begin(),_newMap.end());
//}
//
////------------------------------------------------------------------------------
//void MediaTypeMap::load(std::istream& inputStream)
//{
//    clear();
//    add(inputStream);
//}
//
////------------------------------------------------------------------------------
//void MediaTypeMap::clear()
//{
//    return _map.clear();
//}
//
////------------------------------------------------------------------------------
//std::size_t MediaTypeMap::size() const
//{
//    return _map.size();
//}
//
////------------------------------------------------------------------------------
//MediaTypeMap::ConstIterator MediaTypeMap::begin() const
//{
//    return _map.begin();
//}
//
////------------------------------------------------------------------------------
//MediaTypeMap::ConstIterator MediaTypeMap::end() const
//{
//    return _map.end();
//}
//
////------------------------------------------------------------------------------
//MediaTypeMap::ConstIterator MediaTypeMap::find(const std::string& suffix) const
//{
//    return _map.find(suffix);
//}
//
////------------------------------------------------------------------------------
//Poco::Net::MediaType MediaTypeMap::getDefault() const
//{
//    return _defaultMediaType;
//}
//
////------------------------------------------------------------------------------
//void MediaTypeMap::setDefault(const Poco::Net::MediaType& defaultMediaType)
//{
//    _defaultMediaType = defaultMediaType;
//}
//
//
//////------------------------------------------------------------------------------
////MediaTypeMap::FileSuffixToMediaTypeMap MediaTypeMap::parse(std::istream& inputStream)
////{
////    FileSuffixToMediaTypeMap newMap;
////    std::string line;
////    while(std::getline(inputStream,line))
////    {
////        if(line.empty() || line[0] == '#') continue;
////
////        int tokenizerFlags = Poco::StringTokenizer::TOK_TRIM |
////                             Poco::StringTokenizer::TOK_IGNORE_EMPTY;
////
////        Poco::StringTokenizer tokens(line,"\t",tokenizerFlags);
////
////        if(tokens.count() == 2)
////        {
////            std::string mediaType = tokens[0];
////            Poco::StringTokenizer suffixTokens(tokens[1]," ",tokenizerFlags);
////            Poco::StringTokenizer::Iterator iter = suffixTokens.begin();
////            while(iter != suffixTokens.end())
////            {
////                newMap.insert(std::make_pair(*iter, Poco::Net::MediaType(mediaType)));
////                ++iter;
////            }
////        }
////    }
////    return newMap;
////}
//
//
//} } // namespace ofx::Media
