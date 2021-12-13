#include<iostream>
#include<string.h>
#include "tree.cpp"
#include "queue.cpp"
using namespace std;

int ifFullTree(Bitree &bt){
    Queue<NODE*> q;
    NODE *tmp;
    q.offer(bt.tree);
    
    while(!q.isEmpty()){
        tmp=q.poll();
        if(tmp == NULL){
            while(q.peek()==NULL){
                q.poll();
            }
            if(q.isEmpty()){
                cout<<"是一个完全二叉树";
                return 1;
            }
            else{
                cout<<"不是一个完全二叉树";
                return 0;
            }
        }
        q.offer(tmp->lchild);
        q.offer(tmp->rchild);
    }
    cout<<"是一个完二叉树";
    return 1;
}

int main(){
    Bitree bt;
    int k=3;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    ifFullTree(bt);
}