#include "WebDownload.h"
#include "AnalysisPageAndParseUrl.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include "SaveWebPage.h"
#include <queue>
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
    set<string>::iterator i;
    queue<string> que;
    
    for ( i = urlList.begin(); i != urlList.end() ; i++)
    {
        cout << *i << endl;
        que.push(*i);
        //content = du.download(*i);
        //swp.saveToFile(*i, content);
    }
    while (que.size() != 0) {
        url = que.pop();
        content = du.download(url);
        swp.saveToFile(url, content);
        
    }
    
    return 0;
}