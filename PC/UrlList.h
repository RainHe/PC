#ifndef URL_LIST_H
#define URL_LIST_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
typedef std::list<std::string>::iterator UrlIter;
class UrlList {
private:
    std::list<std::string> urls;
    std::set<UrlIterator> urlIters;
public:
    UrlList();
    void pushUrls(std::set<std::string> &urls);
    std::string getUrl();
    
};
class UrlIterator {
    
private:
    UrlIter iter;
public:
    UrlIterator(UrlIter &iter);
    UrlIter getIterator();
    bool operator<(UrlIter &aIter);
};
#endif