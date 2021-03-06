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
    this->urlfile = path + "/urls.list";
}
bool SaveWebPage::checkPathStatus() {
    struct stat status;
    int flag = stat(path.c_str(), &status);
    if (flag == -1)
    {
        cout << "stat check fail" << endl;
        string command = "mkdir -p " + path;
        if (system(command.c_str()) <= 0)
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

string SaveWebPage::getPath(const string &url){
    int flagSize = SaveWebPage::HTTP_HEAD.size();
    string host = url.substr(7);
    string pattern = "/";
    vector<string> items = split(host, pattern);
    string filePath("");
    filePath.append(path);
    filePath.append("/");
    filePath.append(items[0]);
    int i;
    if (items.size() <= 1)
        i = 0;
    else
        i = 1;
    for( ; i<items.size()-1; i++) {
        filePath.append("/");
        filePath.append(items[i]);
    }
    cout << "file path : " << filePath << endl;
    struct stat status;
    int flag = stat(filePath.c_str(), &status);
    if (flag == -1){
        cout << "file stat get fail filepath" << endl;
        string command = "mkdir -p " + filePath;
        if (system(command.c_str()) < 0)
            return "/tmp/web.html";
        cout << "create filepath is success" << endl;
    }
        
    if(S_ISDIR(status.st_mode) == -1)
    {
        cout << "file is not exists" << endl;
        string command = "mkdir -p " + filePath;
        if (system(command.c_str()) < 0)
            return "/tmp/web.html";
    }
    filePath.append("/");
    filePath.append(items[items.size()-1]);
    cout << "final file path : " << filePath << endl;
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

bool SaveWebPage::saveToFile(const string &url, const string &content) {
    string filepath = getPath(url);
    cout << "file path : " << filepath << endl;
    
    out.open(filepath.c_str());
    if (out.fail())
    {
        cout << "open file fail : " << filepath << endl;
        return false;
    }
    out << content;
    out.flush();
    out.close();
    urlList.insert(url);
    saveWritedUrls();
    return true;
}
    
void SaveWebPage::saveWritedUrls() {
    
    if (urlList.size() >= 50)
    {
        ofstream o(urlfile.c_str(), ios::out | ios::app);
        set<string>::iterator it = urlList.begin();
        while(it != urlList.end()) {
            o << *it << endl;
            it++;
        }
        o.flush();
        o.close();
        
    }
}


