#include <iostream>
#include <boost/regex.hpp>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    string regStr("\\b(([\\w-]+://?|www[.])[^\\s()<>]+(?:\\([\\w\\d]+\\)|([^[:punct:]\\s]|/)))");
    string str("http://www.cppprog.com/2009/0112/48.html>www.baidu.com");
    //string str("http://baidu.com");
    boost::regex reg(regStr.c_str());
    /*boost::cmatch mat;
    bool r = boost::regex_match(str.c_str(), mat, reg);
    cout << r << endl;
    if (r)
    {
        for (boost::cmatch::iterator itr = mat.begin(); itr != mat.end(); itr++)
        {
            cout << itr->first-str.c_str() << ' ' << itr->second-str.c_str() << ' ' << *itr << endl;
        }
        cout << "hello" << endl;
        }*/
    boost::sregex_iterator its(str.begin(), str.end(), reg);
    boost::sregex_iterator end;
    while (its != end)
        cout << *its++ << endl;
    return 0;
}
