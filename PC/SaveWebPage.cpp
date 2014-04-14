#include "SaveWebPage.h"
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
using namespace std;
string SaveWebPage::HTTP_HEAD = "http://";
SaveWebPage::SaveWebPage(string path){
    this->path = path;
}
bool SaveWebPage::checkPathStatus() {
    struct stat status;
    int flag = stat(path.c_str(), &status);
    if (flag == -1)
    {
        cout << "stat check fail" << endl;
        return false;
    }
    if (S_ISDIR(status.st_mode) == -1)
    {
        cout << "it's not a directory , please create it" << endl;
        return false;
    }
    if (access(path.c_str(), R_OK) == -1)
    {
        cout << "path : " << path << "can not read" << endl;
        return false;
    }
    if (access(path.c_str(), W_OK) )
    {
        cout << "path : " << path << "can not write" << endl;
        return false;
    }
    return true;
    
}

vector<string> SaveWebPage::split(string &str, string &pattern) {
    string::size_type pos;
    vector<string> result;
    str += pattern;

    int size = str.size();
    for (int i = 0; i < size; ++i) {

        pos = str.find(pattern,i);
        if (pos < size) {
            std::string s = str.substr(i,pos-i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}
string SaveWebPage::getPath(string &url){
    int flagSize = SaveWebPage::HTTP_HEAD.size();
    string host = url.substr(7);
    string pattern = "/";
    vector<string> items = split(host, pattern);
    string filePath("");
    filePath.append("/");
    filePath.append(path);
    for(int i = 0; i<items.size(); i++) {
        filePath.append("/");
        filePath.append(items[i]);
    }
    return filePath;
}

bool SaveWebPage::fileIsExists(string &filepath) {
    if (access(filepath.c_str(), F_OK) == -1)
    {
        cout << "filepath : " << filepath << " is not exists" << endl;
        return false;
    }
    if (access(filepath.c_str(), R_OK) == -1)
    {
        cout << "filepath : " << filepath << " can not read" << endl;
        return false;
    }
    if (access(filepath.c_str(), W_OK) )
    {
        cout << "filepath : " << filepath << " can not write" << endl;
        return false;
    }
    return true;
}

bool SaveWebPage::saveToFile(string &url, string &content) {
    string filepath = getPath(url);
    
    out.open(filepath.c_str());
    if (out.fail())
    {
        cout << "open file fail" << endl;
        return false;
    }
    ostream o = (out << content);
    if (o.fail())
    {
        cout << "write content fail" << endl;
        return false;
    }
    out.flush();
    out.close();
    
    
}
    
bool SaveWebPage::saveWritedUrls() {

}







