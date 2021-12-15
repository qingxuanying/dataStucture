#include<iostream>
#include "brotree.cpp"

int treedepth(Node *p){
    if(p != NULL){
        return max(treedepth(p->son),treedepth(p->bro)-1)+1;
    }
    else{
        return 0;
    }
}
int main(){
    broTree bt;
    String a("head");
    String b("body");
    String a1("back");
    String ky("kashfaoi");
    String m("body");
    bt.insert(a);
    bt.insert(b);
    cout<<"树深:"<<treedepth(bt.root)<<endl;
}