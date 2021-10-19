#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NodeType
{
    char data;
    NodeType *next;
} NodeType, *LinkType;
typedef struct
{
    LinkType top;
    int size;
} Stack;
void InitStack(Stack &s)
{
    s.top = NULL;
    s.size = 0;
}
void DestroyStack(Stack &s)
{
    LinkType p;
    while (s.top)
    {
        p = s.top;
        s.top = p->next;
        delete p;
        s.size--;
    }
}
void ClearStack(Stack &s)
{
    LinkType p;
    while (s.top)
    {
        p = s.top;
        s.top = p->next;
        delete p;
        s.size--;
    }
}
int StackLength(Stack s)
{
    return s.size;
}
int StackEmpty(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}
int GetTop(Stack s, char &e)
{
    if (!s.top)
        return -1;
    else
    {
        e = s.top->data;
        return 1;
    }
}
int Push(Stack &s, char e)
{
    LinkType p;
    p = new NodeType;
    if (!p)
        exit(-1);
    p->next = s.top;
    s.top = p;
    p->data = e;
    s.size++;
    return 1;
}
int Pop(Stack &s, char &e)
{
    LinkType p;
    if (s.top)
    {
        e = s.top->data;
        p = s.top;
        s.top = p->next;
        delete p;
        s.size--;
    }
    return 1;
}

int main()
{
    int i = 0;
    char a[100];
    cout<<"请输入序列"<<endl;
    cin>>a;
    cout<<a<<endl;
    Stack s;
    InitStack(s);
    char x;
    while (a[i] != '&' && a[i])
    {
        Push(s, a[i]);
        i++;
    }
    i++;
    while (a[i])
    {
        Pop(s, x);
        if (x != a[i])
        {
            DestroyStack(s);
            cout<<"不是"<<endl;
            exit(-1);
        }
        i++;
    }
    cout<<"是"<<endl;
    return 0;
}