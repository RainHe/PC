#include "AnalysisPageAndParseUrl.h"
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

UrlParse::UrlParse(string pageCode) {
    this->pageCode = pageCode;
    
    replaceList.insert(pair<string,string>("&amp;","&"));
    this->regexStr = "http://((((((([a-z]|[A-Z])|[0-9])|(([a-z]|[A-Z])|[0-9])((([a-z]|[A-Z])|[0-9])|-)*(([a-z]|[A-Z])|[0-9]))\\.)*(([a-z]|[A-Z])|([a-z]|[A-Z])((([a-z]|[A-Z])|[0-9])|-)*(([a-z]|[A-Z])|[0-9])*)*)|([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+))(:([0-9]+)){0,1})(/((((([a-z]|[A-Z])|[0-9]|(\\$|-|_|\\.|\\+)|(!|\\*|\\(|\\)|,))|(%([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)))|;|:|@|&|=)*)(/((((([a-z]|[A-Z])|[0-9]|(\\$|-|_|\\.|\\+)|(!|\\*|\\(|\\)|,))|(%([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)))|;|:|@|&|=)*))*(\\?((((([a-z]|[A-Z])|[0-9]|(\\$|-|_|\\.|\\+)|(!|\\*|\\(|\\)|,))|(%([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)([0-9]|A|B|C|D|E|F|a|b|c|d|e|f)))|;|:|@|&|=|/)*)){0,1}){0,1}";
    
}
string &UrlParse::getRegexHttp() {
    return regexStr;
}
void UrlParse::getUrls() {
    boost::regex reg(regexStr.c_str());
    boost::sregex_iterator its(pageCode.begin(), pageCode.end(), reg);
    boost::sregex_iterator end;
    while(its != end) {
        //cout << *its << endl;
        string url = its->str();
        processUrl(url);
        if (!isFile(url))
            urlList.insert(url);
        its++;
    }
        //urlList.push_back(*its++);
    
}
set<string> &UrlParse::getUrlList() {
    this->getUrls();
    return urlList;
}
void UrlParse::processUrl(string &url) {
    map<string,string>::iterator it;
    for (it = replaceList.begin(); it != replaceList.end(); it++) {
        size_t pos = url.find(it->first);
        while (pos != string::npos) {
            
            url.replace(pos, it->first.size(), it->second);
            pos = url.find(it->first);
        }
    }
    size_t pos = url.find_last_of("/");
    if (pos == (url.size() -1))
        url = url.substr(0, url.size() -1);
}
bool UrlParse::isFile(const string &url) const {
    
    size_t pos_backslash_f = url.find_last_of("/");
    size_t pos_backslash_s = url.find_last_of("/", pos_backslash_f-1);
    //cout << "pos_back 1: " << pos_backslash_f << endl;
    //cout << "pos_back 2: " << pos_backslash_s << endl;
    if (pos_backslash_f == (pos_backslash_s + 1))
        return false;
    size_t pos_point = url.find_last_of(".");
    if (pos_point == string::npos || pos_point < pos_backslash_f)
        return false;
    string backend = url.substr(pos_point + 1, url.size() - (pos_point +1));
    //cout << backend << endl;
    if (backend == "html")
        return false;
    return true;
}
UrlParse::~UrlParse(){
    urlList.clear();
}

/*int main (){
    UrlParse parse("hello world");
    bool flag = parse.isFile("http://www.baidu.com/d/d/a.gif");
    if (flag)
    {
        cout << "true" << endl;
    } else{
        cout << "false" << endl;
    }
    string url = "http://www.baidu.com/s?word=+%E5%B0%8F%E5%81%B7%E5%85%A5%E9%99%8B%E5%AE%A4%E4%B8%8D%E5%BF%8D%E4%B8%8B%E6%89%8B+%E7%95%99200%E5%85%83%E7%BB%99%E6%88%B7%E4%B8%BB%E6%8D%A2%E9%94%81&amp;tn=sitehao123_7_pg&amp;ie=utf-8";
    parse.processUrl(url);
    cout << url << endl;
}*/