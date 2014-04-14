#include "WebDownload.h"
#include "AnalysisPageAndParseUrl.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include "SaveWebPage.h"
using namespace std;
using namespace hh_pc;

int main(int argc, char *argv[])
{
    string url("www.hao123.com");
    DownloadUrl du;
    SaveWebPage swp("/home/hhq/workspace/personal/");
    string content = du.download(url);
    //cout << "content size : "<< data;
    
    UrlParse parse(content);
    set<string> urlList = parse.getUrlList();
    set<string>::iterator i;
    for ( i = urlList.begin(); i != urlList.end() ; i++)
    {
        cout << *i << endl;
    }
    
    return 0;
}