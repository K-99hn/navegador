#include <iostream>
#include "Pag.h"

Pag::Pag(){

   URL_ = "";
   date_ = "0000-00-00";
   time_= "00:00:00";
   cate_= "";

}
Pag::Pag(string URL,string date,string time,string cate)
{
    URL_ = URL;
    date_ = date;
    time_ = time;
    cate_ = cate;
}
Pag::~Pag(){
    
}
void Pag::setPag(string URL,string date,string time,string cate){
    URL_ = URL;
    date_ = date;
    time_ = time;
    cate_ = cate;

}
string Pag::getURL(){
 return URL_;
}
string Pag:: getdate(){
 return date_;

}
string Pag::gettime(){
 return time_;
}
string Pag:: getcate(){
 return cate_;
}
void Pag:: baraddress(){
  cout << URL_<<" ,"<< date_<<" ,"<<time_<<" ,"<<cate_<< endl;
}
ostream&  operator<<(ostream& os,Pag& p){
    os << p.URL_<<" ,"<< p.date_<<" ,"<<p.time_<<" ,"<<p.cate_<< endl;
    return os;
}