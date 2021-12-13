#include<iostream>
#include<string.h>
#include "tree.cpp"
#include "queue.cpp"
using namespace std;

int getfan(Bitree &bt){
    int depth=bt.treeDepth(bt.tree);
    int m=0;int falg=0;
    NODE *p=bt.tree;
    NODE *s,*t;
    Queue<NODE*> q1;
    Queue<NODE*> q2;
    q1.offer(p);
    while(!q1.isEmpty() || !q2.isEmpty()){
        while(falg == 0 && !q1.isEmpty()){
            m=max(m,q1.Size());
            p=q1.poll();
            if(p->lchild){
                q2.offer(p->lchild);
            }
            if(p->rchild){
                q2.offer(p->rchild);
            }
            cout<<p->data<<endl;
        }
        falg=1;
        while(falg == 1 && !q2.isEmpty()){
            m=max(m,q2.Size());
            p=q2.poll();
            if(p->lchild){
                q1.offer(p->lchild);
            }
            if(p->rchild){
                q1.offer(p->rchild);
            } 
        }
        falg=0;
    }
    cout<<"各层节点最大数:"<<m<<endl;
    cout<<"树高:"<<depth<<endl;
    return m*depth;
}

int main(){
    Bitree bt;
    int x;
    int a[10]={0,2,9,4,3,5,6,7,8,1};
    bt.InitFULLTree(a,10);
    x=getfan(bt);
    cout<<"繁密度:"<<x<<endl;
}