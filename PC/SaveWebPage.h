#ifndef SAVE_WEB_PAGE_H
#define SAVE_WEB_PAGE_H
#include <string>
#include <fstream>
#include <set>
#include <vector>
class SaveWebPage {
private:
    
    std::string path;
    std::ofstream out;
    std::set<std::string> urlList;
public:
    static std::string HTTP_HEAD;
    SaveWebPage(std::string path);
    bool checkPathStatus();
    bool saveToFile(std::string &url, std::string &content);
    bool fileIsExists(std::string &filePath) ;
    std::string getPath(std::string &url);
    bool saveWritedUrls();
    std::vector<std::string> split(std::string &str, std::string &pattern);
};
#endif