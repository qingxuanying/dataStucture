#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

String inSnotInT(String s,String t){
    int l=t.lenth();
    for(int i=0;i<l;i++){
        s.deleteStr(t.str[i]);
    }
    return s;
}

int main(){
    String s("abcdefg");
    String t("acdg");
    cout<<"s:";
    s.show();
    cout<<"t:";
    t.show();
    inSnotInT(s,t).show();
}