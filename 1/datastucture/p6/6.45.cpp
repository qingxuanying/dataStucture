#include<iostream>
#include<string.h>
#include "tree.cpp"
using namespace std;

NODE *tmp;
NODE* searchByVaule(int k,NODE *p){
    if(p->lchild != NULL){
        if(p->lchild->data == k){
            tmp = p->lchild;
            p->lchild = NULL;
        }
        else{
            searchByVaule(k,p->lchild);
        }
    }
    if(p->rchild != NULL){
        if(p->rchild->data == k){
            tmp = p->rchild;
            p->rchild == NULL;
        }
        else{
            searchByVaule(k,p->rchild);
        }
    }
    return tmp;
}

void deletebys(int s,Bitree &bt){
    NODE *p;
    p=searchByVaule(s,bt.tree);
    if(p != NULL){
        cout<<p->data<<endl;
        bt.deleteBynode(p);
    }
}


int main(){
    Bitree bt;
    int k=3;
    int x=4;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    //bt.firstVisit(bt.tree);
    deletebys(x,bt);
    cout<<endl;
    bt.firstVisit(bt.tree);
}