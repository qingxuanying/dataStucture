#include<iostream>
#include<string.h>
#include "tree.cpp"
#include "queue.cpp"
using namespace std;

void treeVisitByceng(Bitree bt){
    NODE *p=bt.tree;
    Queue<NODE*> q;
    q.offer(p);
    while(!q.isEmpty()){
        p=q.poll();
        if(p->lchild){
            q.offer(p->lchild);
        }
        if(p->rchild){
            q.offer(p->rchild);
        }
        cout<<p->data<<" ";
    }
    cout<<endl;
}

int main(){
    Bitree bt;
    int x;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    treeVisitByceng(bt);
}