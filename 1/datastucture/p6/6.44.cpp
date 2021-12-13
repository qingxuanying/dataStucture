#include<iostream>
#include<string.h>
#include "tree.cpp"
using namespace std;

int getSubDepth(Bitree bt,int x){
    NODE *p;
    int anw=0;;
    p=bt.searchByVaule(x,bt.tree);
    anw=bt.treeDepth(p);
    return anw;
}

int main(){
    Bitree bt;
    int x=4;
    int k;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    k=getSubDepth(bt,x);
    cout<<"以"<<x<<"为值的结点的子树深度（包含4为根节点）:"<<k<<endl;
}