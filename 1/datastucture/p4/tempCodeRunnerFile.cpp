#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

int Replace(String &S,String T,String V){
    int start=S.subStrIndex(T);
    if(start==0){
        cout<<"字符中不存在对应字串"<<endl;
        return 0;
    }
    for(int i=0;i<T.lenth();i++){
        S.deleteByid(start-1);
    }
    //S.show();
    S.insert(V,start-1);
    //S.show();
};

int main(){
    String A("xxxzkyxxx");
    String B("zky");
    String C("qyh");
    Replace(A,B,C);
    A.show();
}