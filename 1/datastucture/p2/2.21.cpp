#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE{
    int data;
    NODE *next;
};
NODE *creatLinkList(){
    NODE *head,*tail,*pnew;
    int data;char ch;
    head=(NODE *)malloc (sizeof(NODE));
    if(head==NULL){
        printf("no enough memory!\n");
        return (NULL);
    }
    head->next=NULL;
    tail=head;
    printf("input the data of node:\n");
    while(1){
        ch=getchar();
        if(ch!=' '&&ch!='\n'&&ch!='\r'&&(ch<'0'||ch>'9')){
            printf("输入非法");
            exit(-1);
        }
        if(ch=='\n'){
            break;
        }
        scanf("%d",&data);
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL){
            printf("no enough memory!\n");
            return NULL;
        }
        pnew->data=data;
        pnew->next=NULL;

        tail->next=pnew;
        tail=pnew;
    }
    printf("创建完毕\n");fflush(stdin);
    return (head);
}
void showLinkList(NODE *head){
    NODE *p;
    
    for(p=head->next;p !=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}
void nizhi(NODE *head){
    NODE *tail,*p,*q;
    for(p=head->next;p->next!=NULL;p=p->next);
    tail=p;q=tail;
    while(1){
        for(p=head->next;p->next!=tail;p=p->next);
        tail->next=p;
        p->next=NULL;
        tail=p;
        if(tail=head->next){
            break;
        }
        p=head->next;
    }
    head->next=q;
}
int main(){
    NODE *la;
    la=creatLinkList();
    showLinkList(la);
    nizhi(la);
    showLinkList(la);
}