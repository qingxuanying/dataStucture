#include<iostream>
#include<string.h>
using namespace std;
#include"queue.cpp"
struct NODE{
    int data;
    NODE *lchild;
    NODE *rchild;
};
class Bitree{
    public:
        NODE *tree;
        NODE *tmp;
        int size;
        Bitree(){
            tree=new NODE;
            tree->data=0;
            tree->lchild=NULL;
            tree->rchild=NULL;
            size = 1;
        }
        int insertTree(int a){
            NODE *pnew,*p;
            pnew=new NODE;
            pnew->data=a;
            pnew->lchild=NULL;
            pnew->rchild=NULL;
            p=tree;
            while(p != NULL){
                if(p->data == a){
                    return 1;
                }
                if(p->data > a){
                    if(p->lchild == NULL){
                        p->lchild=pnew;
                        size++;
                        return 1;
                    }
                    p=p->lchild;
                }
                else{
                    if(p->rchild == NULL){
                        p->rchild=pnew;
                        size++;
                        return 1;
                    }
                    p=p->rchild;
                }
            }
            
            return 1;
        }

        void InitFULLTree(int a[],int n){
            for(int i=0;i<n;i++){
                insertTree(a[i]);
            }
        }

        void firstVisit(NODE *p){
            cout<<p->data<<" ";
            if(p->lchild != NULL){
                firstVisit(p->lchild);
            }
            if(p->rchild != NULL){
                firstVisit(p->rchild);
            }
        }
        int leafNum(int n,NODE *p){
            if(p->lchild == NULL && p->rchild == NULL){
                n++;
            }
            else{
                if(p->lchild != NULL){
                    n=leafNum(n,p->lchild);
                }
                if(p->rchild != NULL){
                    n=leafNum(n,p->rchild);
                }
            }
            return n;
        }
        void deleteBynode(NODE *p){
            if(p->lchild != NULL){
                deleteBynode(p->lchild);
                p->lchild=NULL;
            }
            if(p->rchild != NULL){
                deleteBynode(p->rchild);
                p->rchild==NULL;
            }
            p->lchild=NULL;
            p->rchild=NULL;
            free(p);
        }
        NODE* searchByVaule(int k,NODE *p){
            if(p->lchild != NULL){
                if(p->lchild->data == k){
                    tmp = p->lchild;
                }
                else{
                    searchByVaule(k,p->lchild);
                }
            }
            if(p->rchild != NULL){
                if(p->rchild->data == k){
                    tmp = p->rchild;
                }
                else{
                    searchByVaule(k,p->rchild);
                }
            }
            return tmp;
        }
        int treeDepth(NODE *p){
            if(p != NULL){
                return  max(treeDepth(p->lchild),treeDepth(p->rchild))+1;
            }
            else{
                return 0;
            }
        }
        void treeVisitByFloor(){
            NODE *p=tree;
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
};
