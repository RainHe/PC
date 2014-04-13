#include "WebDownload.h"
#include "AnalysisPageAndParseUrl.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
using namespace std;
using namespace hh_pc;

int main(int argc, char *argv[])
{
    string url("www.hao123.com");
    DownloadUrl du;
    string content = du.download(url);
    //cout << "content size : "<< data;
    
    UrlParse parse(content);
    set<string> urlList = parse.getUrlList();
    set<string>::iterator i;
    for ( i = urlList.begin(); i != urlList.end() ; i++)
    {
        cout << *i << endl;
    }
    //cout << "----------------------------------------------------------------" << endl;
    //cout << content << endl;
    return 0;
}