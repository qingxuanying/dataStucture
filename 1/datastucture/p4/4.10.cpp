#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;
String verseString(String &s){
    char str[s.lenth()+1];
    for(int i=s.lenth()-1,j=0;i>=0;i--,j++){
        str[j]=s.str[i];
    }
    str[s.lenth()]='\0';
    String verString(str);
    return verString;
};

int main(){
    String sa("abcdefg");
    verseString(sa).show();

}
