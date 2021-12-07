#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

int deleteStringsub(String &S,String sub){
    int start=S.subStrIndex(sub);
    if(start==0){
        cout<<"字符中不存在对应字串"<<endl;
        return 0;
    }
    for(int i=0;i<sub.lenth();i++){
        S.deleteByid(start-1);
    }
    //S.show();
}
int main(){
    String A("xxxzkyxxx");
    String B("zky");
    deleteStringsub(A,B);
    A.show();
}