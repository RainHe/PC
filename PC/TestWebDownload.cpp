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

    string url("http://www.baidu.com");
    DownloadUrl du;
    SaveWebPage swp("/home/hhq/workspace/");
    
    string content = du.download(url);

    swp.saveToFile(url, content);


    //cout << "content size : "<< data;

    UrlParse parse(content);
    set<string> urlList = parse.getUrlList();
    set<string>::iterator i;
    for ( i = urlList.begin(); i != urlList.end() ; i++)
    {
        cout << *i << endl;
        content = du.download(*i);
        swp.saveToFile(*i, content);
    }
    
    return 0;
}