#include <string.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct WNode
{
    string str;
    WNode *lchild;
    WNode *rbrother;
};
struct SNode
{
    string str;
    SNode *next;
};
char *filename;
SNode *strs = new SNode;
WNode *root = new WNode;

//从文件中读取dns字符并存到链表strs
int init()
{
    int i = 0;
    FILE *fp;
    SNode *p;
    root->lchild = NULL;
    root->rbrother = NULL;
    strs->next = NULL;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("cannot open file\n");
        return 0;
    }
    while (1)
    {
        if (feof(fp))
        {
            break;
        }
        char *str = new char[15];
        fscanf(fp, "%s", str);
        i++;
        p = new SNode;
        p->str = str;
        p->next = strs->next;
        strs->next = p;
        //cout<<p->str<<endl;
    }
    return 1;
}
//传入字符串，然后将它拆分并将子串存到链表并返回
SNode *getsub_str(string s)
{
    SNode *sub_str = new SNode;
    SNode *pnew, *tail;
    tail = sub_str;
    int i = 0;
    int j, k;
    j = k = 0;
    while (s[i])
    {
        if (s[i] == '.')
        {
            j = k;
            k = i;
            string str;
            if(j==0){
                j--;
            }
            str = s.substr(j+1, k - j-1);
            pnew = new SNode;
            pnew->str = str;

            tail->next=pnew;
            tail=pnew;
            //cout << pnew->str << endl;
        }
        i++;
    }
    string str;
    str = s.substr(k+1);
    pnew = new SNode;
    pnew->str = str;
    //cout << pnew->str << endl;
    tail->next=pnew;
    tail=pnew;
    tail->next=NULL;
    return sub_str;
}


//将SNODE中的数据以树状结构存储到root
void creatRootTree()
{
    SNode *p, *sub_str;
    p = strs->next;
    while (p)
    {
        sub_str = getsub_str(p->str);
        p = p->next;
        SNode *s=sub_str->next;
        WNode *pret=root;
        WNode *t=root->lchild;
        WNode *wnew;
        int flag=0;
        while(s != NULL){
            //cout<<s->str<<endl;
            if(t == NULL){
                wnew = new WNode;
                wnew->str=s->str;
                wnew->lchild=NULL;
                wnew->rbrother=NULL;
                
                if(flag == 0){
                    pret->lchild=wnew;
                    //cout<<"新建左子树"<<endl;
                }
                else if(flag == 1){
                    pret->rbrother=wnew;
                    //cout<<"新建右子树"<<endl;
                    flag=0;
                }
                
                s=s->next;
                t=wnew;
                pret=t;
                //cout<<t->str<<endl;

                t=t->lchild;
                
            }
            
            if(t!=NULL &&t->str == s->str){
                s=s->next;
                pret=t;
                t=t->lchild;
                
            }
            
            if( t!=NULL  && t->str != s->str){
                pret=t;
                t=t->rbrother;
                flag=1;
                
            }
            
            
        }
        

    }
}

//在树中查询
void findDnsfromTree(SNode *substr,string dns){
    SNode *p=substr->next;
    WNode *t=root->lchild;
    int flag=1;
    //cout<<"begin"<<endl;
    while(p){
        if(p->str != t->str && t->rbrother !=NULL){
            t=t->rbrother;
            //cout<<"test"<<endl;
            continue;
        }
        if(p->str == t->str){
            //cout<<"123."<<endl;
            t=t->lchild;
            p=p->next;
            continue;
        }
        if(p->str !=t->str && t->rbrother == NULL){
            cout<<"树中没有该dns"<<endl;
            flag==0;
            exit(-1);
            break;
        }
    }
    if(flag == 1){
        struct hostent* host;
        char *hostname =new char[20];
        strcpy(hostname,dns.c_str());
        host = gethostbyname(hostname);
        const char *hostip = inet_ntoa(*((struct in_addr*)host->h_addr));
        cout<<hostip<<endl;
        cout<<"跳转中"<<endl;
        const char *wanzhi=dns.c_str();
        char commond[30];
        strcpy(commond,"/home/taichuguang/wincmd ");
        strcat(commond,wanzhi);
        system(commond);
    }
    //cout<<"end"<<endl;
}

int main()
{
    filename = new char[10];
    strcpy(filename, "dns.txt");
    init();
    creatRootTree();
    string dns;
    SNode *dns_sub;
    cout<<"输入一个域名:"<<endl;
    cin>>dns;
    dns_sub=getsub_str(dns);
    findDnsfromTree(dns_sub,dns);
}