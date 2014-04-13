#include <iostream>
#include <curl/curl.h>
using namespace std;
int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
                
        char data;
        res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, data);
        cout << data;
        curl_easy_cleanup(curl);
    }
    return 0;
}
