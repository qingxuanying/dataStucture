#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

void StrArrignd(String &S,char *str){
    String tmp(str);
    StrAssign(S,tmp);
}

int main(){
    String A("xxxzkyxxx");
    char str[30];
    strcpy(str,"abcdefg");
    StrArrignd(A,str);
    A.show();
}