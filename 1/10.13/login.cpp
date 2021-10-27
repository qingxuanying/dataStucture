#include <string.h>
#include <math.h>
#include<fstream>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Users{
    int ifowner;//0普通用户 1管理员 2超级管理员
    char name[20];
    char password[20];
};
struct uNode{
    Users user;
    uNode *next=NULL;
};
uNode *ulist=(uNode *)malloc(sizeof(uNode));
void regest_user(){
    char name[20];
    char password[20];
    cout<<"请输入账号/用户名:";
    cin>>name;
    cout<<endl<<"请输入密码:";
    cin>>password;
    uNode *p,*pnew;
    pnew = (uNode*)malloc(sizeof(uNode));
    strcpy(pnew->user.password,password);
    strcpy(pnew->user.name,name);
    pnew->user.ifowner = 0;

    p = ulist->next;

    pnew->next=p;
    ulist->next=pnew;

}
int login(){
    char name[20];
    char password[20];
    cout<<"请输入账号/用户名:";
    cin>>name;
    cout<<"请输入密码:";
    cin>>password;
    uNode *p;
    int x;
    p=ulist->next;
    while(p != NULL){
        if(strcmp(p->user.name,name) == 0){
            if(strcmp(p->user.password,password) == 0){
                return p->user.ifowner;
            }
            else{
                cout<<"密码错误"<<endl;
                return -1;
            }
        }
    }
    cout<<"用户不存在"<<endl;
    return -1;
}
void initUser(){
    uNode *p;
    p=(uNode *)malloc(sizeof(uNode));
    p->next=NULL;
    p->user.ifowner=2;
    strcpy(p->user.name,"root");
    strcpy(p->user.password,"123456");
    ulist->next=p;
}
