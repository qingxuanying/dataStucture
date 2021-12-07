#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;

struct Node{
    char str;
    int num=0;
    Node *next;
};
Node *head = new Node;

void inserttonode(char s){
    Node *p;
    int falg=0;
    p=head->next;
    while(p){
        if(p->str == s){
            p->num ++;
            falg=1;
        }
        p=p->next;
    }
    if(falg != 1){
        Node *pnew=new Node;
        pnew->str=s;
        pnew->num=1;
        pnew->next=head->next;
        head->next=pnew;
    }

}

void wordSUM(String A){
    for(int i=0;i<A.lenth();i++){
        char s=A.str[i];
        inserttonode(s);
    }
}

void showNodeList(){
    Node *p;
    p=head->next;
    while(p){
        cout<<p->str<<":"<<p->num<<endl;
        p=p->next;
    }
}

int main(){
    String A("asfsaaw");
    wordSUM(A);
    A.show();
    showNodeList();
}