#include<iostream>
#include<string.h>
#include "tree.cpp"
using namespace std;

int i=1;
int firstvisitbyid(int k,NODE *p){
            if(i==k){
                cout<<p->data<<endl;
                return 1;
            }
            else{
                i++;
            }
            if(p->lchild != NULL){
                firstvisitbyid(k,p->lchild);
            }
            if(p->rchild != NULL){
                firstvisitbyid(k,p->rchild);
            }
        }

int main(){
    Bitree bt;
    int k=3;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    bt.firstVisit(bt.tree);
    cout<<endl;
    firstvisitbyid(k,bt.tree);

}