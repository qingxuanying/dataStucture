#include<iostream>
#include<string.h>
#include "string.cpp"
using namespace std;
struct Node
{
    char val;
    Node *son;
    Node *bro;
};
class broTree
{
public:
    Node *root;
    broTree()
    {
        root = new Node;
        root->bro = NULL;
        root->son = NULL;
        // root->son=new Node;
        // root->son->val='a';
        // root->son->bro=NULL;
        // root->son->son=NULL;
    }

    void insert(String &str)
    {
        Node *p, *pnew, *pre;
        p = root->son;
        pre = root;
        int flag = 0;
        int i = 0;

        while (i < str.lenth())
        {
            if (p == NULL)
            {
                pnew = new Node;
                pnew->val = str.str[i];
                pnew->bro = NULL;
                pnew->son = NULL;
                // cout<<str.str[i];
                //新建左子树
                if (flag == 0)
                {
                    pre->son = pnew;
                }
                else if (flag == 1)
                {
                    pre->bro = pnew;
                    flag = 0;
                }
                i++;
                p=pnew;
                pre=p;
                p=p->son;
            }

            if ( p != NULL && p->val == str.str[i] )
            {
                pre = p;
                p = p->son;
                i++;
                
            }

            if ( p != NULL && p->val != str.str[i])
            {
                pre = p;
                p = p->bro;
                flag = 1;
                
            }
        }
    }
    int search(String s){
        Node *p,*pre;
        int i=0;
        p=root->son;
        if(p == NULL){
            cout<<"树为空"<<endl;
            return 0;
        }
        while(i<s.lenth()-1){
            if(p->val == s.str[i]){
                pre=p;
                p=p->son;
                i++;
            }
            if(p->val != s.str[i]){
                pre=p;
                p=p->bro;
                
            }
            if(p == NULL){
                cout << "词典中未查询到单词:" << s.str <<"，请确认拼写!"<<endl;
                return 0;
            }
        }
        cout <<"单词库中查询到该单词:" <<s.str<<endl;
        return 1;
    }
    
};

int main(){
    broTree bt;
    String a("head");
    String b("body");
    String a1("back");
    String ky("kashfaoi");
    String m("body");
    bt.insert(a);
    // cout<<endl;
    bt.insert(b);
    // cout<<endl;
    bt.insert(a1);
    // cout<<endl;
    bt.insert(ky);
    // cout<<endl;
    bt.search(m);
    bt.search(ky);
}