#include "UrlList.h"
#include <iostream>
#include <string>
#include <set>
#include <list>
using namespace std;

UrlList::UrlList(){
}
void UrlList::pushUrls(set<string> &urls) {
    
}
string UrlList::getUrl() {
    return urls.pop_front();
}


