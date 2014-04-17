#include <iostream>
#include "WebDownload.h"

using namespace std;
using namespace hh_pc;

DownloadUrl::DownloadUrl(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
        
}

size_t DownloadUrl::getUrlResponse(char *ptr, size_t size, size_t nmemb, string *stream) {
    unsigned long  content_len = size * nmemb;
    if (stream == NULL || ptr == NULL)
    {
        cout << "not data be receive" << endl;
        return 0;
    }
    stream->append(ptr, content_len);
    
    return content_len;
}

string DownloadUrl::download(const string &url){
    string str="";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &DownloadUrl::getUrlResponse);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL,1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT,5);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    }
    //char *da new char[10240];
    
    return str;
}
DownloadUrl::~DownloadUrl() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}
