#include "UrlList.h"
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

UrlList::UrlList(){
}

void UrlList::pushUrls(const set<string> &urls) {
    this->urls.insert(urls.begin(), urls.end());
    
    cout << "urls size : " << this->urls.size() << endl;
}
string UrlList::getUrl() {
    if (urls.size() == 0)
        return "";
    set<string>::iterator iter = urls.begin();
    string url = *iter;
    this->urls.erase(iter);
    map<string,int>::iterator iter1 = flag.find(url);
    if (iter1 != flag.end())
        return "null";
    flag[url]=1;
    cout << "get url : " << url << endl;
    return url;
}

UrlList::~UrlList() {
     
}

/*int main(int argc, char *argv[])
{
    UrlList list;
    set<string> urls;
    urls.insert("www.baidu.com");
    urls.insert("www.hello.com");
    urls.insert("www.hel.com");
    urls.insert("www.he.com");
    urls.insert("www.hell.com");
    urls.insert("www.hllo.com");
    urls.insert("www.we.com");
    urls.insert("www.osd.com");
    urls.insert("www.cke.com");
    urls.insert("www.iokk.com");
    cout << "start push url" << endl;
    list.pushUrls(urls);
    string u;
    while ((u=list.getUrl()) != "")
        cout << "url : " << u << endl;
    return 0;
    }*/