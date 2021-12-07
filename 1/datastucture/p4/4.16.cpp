#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

void StrCompareD(String &S,String &T){
    int i=StrCompare(S,T);
    if(i>0){
        cout<<"大于"<<endl;
    }
    else if(i<0){
        cout<<"小于"<<endl;
    }
    else{
        cout<<"等于"<<endl;
    }
}

int main(){
    String A("a");
    String B("ab");
    StrCompareD(A,B);
    A.show();
}