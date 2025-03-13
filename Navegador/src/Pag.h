#ifndef PAG_H
#define PAG_H
#include <iostream>
#include <ostream>
using namespace std;

class Pag
{
private:
   string URL_;
   string date_;
   string time_;
   string cate_;
    
public:
    Pag();
    Pag(string URL,string date,string time,string cate);
    ~Pag();
    void setPag(string URL,string date,string time,string cate);
    string getURL();
    string getdate();
    string gettime();
    string getcate();
    void baraddress();
    friend ostream&operator<<(ostream& os,Pag & p);

};

















#endif