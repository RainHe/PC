#ifndef WEB_DOWNLOAD
#define WEB_DOWNLOAD
#include <string>
#include <curl/curl.h>
#include <map>
namespace hh_pc{
    
    class DownloadUrl{
    private:
        CURL *curl;
        CURLcode res;
        
        //string content;
    public:
        
        DownloadUrl();
        std::string download(const std::string &url);
        static size_t getUrlResponse(char *ptr, size_t size, size_t nmemb, std::string *stream);
        
        ~DownloadUrl();
        
    };
    
}
#endif