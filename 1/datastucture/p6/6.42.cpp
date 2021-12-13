#include<iostream>
#include<string.h>
#include "tree.cpp"
using namespace std;


int main(){
    Bitree bt;
    int k=3;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    //bt.firstVisit(bt.tree);
    cout<<bt.leafNum(0,bt.tree)<<endl;
}