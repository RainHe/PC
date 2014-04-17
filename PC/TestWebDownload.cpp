#include "WebDownload.h"
#include "AnalysisPageAndParseUrl.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include "SaveWebPage.h"
#include <queue>
#include "UrlList.h"
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
    UrlParse parse;
    set<string> urlList = parse.getUrlList(content);
    UrlList all;
    all.pushUrls(urlList);
            
    while (true) {
        url=all.getUrl();
        if (url == "")
            break;
        if (url == "null")
            continue;
        
        content = du.download(url);
        swp.saveToFile(url, content);
        urlList = parse.getUrlList(content);
        cout << "urllist : " << urlList.size() << endl;
        all.pushUrls(urlList);
        cout << 1 << " is end new list size : " << urlList.size() << endl;
    }
    
    return 0;
}