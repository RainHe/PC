#ifndef ANALYSIS_PAGE_AND_PARSE_URL 
#define ANALYSIS_PAGE_AND_PARSE_URL
#include <iostream>
#include <string>
#include <set>
#include <map>
class UrlParse {
private:
    std::string regexStr;
    std::string pageCode;
    std::set<std::string> urlList;
    std::map<std::string, std::string> replaceList;
public:
    UrlParse();
    void getUrls();
    std::string &getRegexHttp();
    void processUrl(std::string &url);
    bool isFile(const std::string & url) const;
    std::set<std::string> &getUrlList(std::string pageCode) ;
    ~UrlParse();
};
#endif
 