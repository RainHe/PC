#ifndef URL_LIST_H
#define URL_LIST_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>

class UrlList {
private:
    std::set<std::string> urls;

public:
    UrlList();
    void pushUrls(const std::set<std::string> &urls);
    void pushFun(const std::string &url);
     std::string getUrl();
    ~UrlList();
};

#endif