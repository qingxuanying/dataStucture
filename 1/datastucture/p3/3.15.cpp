#include <iostream>
#include <stdlib.h>
using namespace std;

class DStack
{
    int *top[2];
    int *p;
    int stacksize;
    int di;

public:
    DStack(int m)
    {
        p = new int[m];
        if (!p)
            exit(-1);
        top[0] = p + m / 2;
        top[1] = top[0];
        stacksize = m;
    }
    ~DStack() { delete p; }
    void Push(int i, int x)
    {
        di = i;
        if (di == 0)
        {
            if (top[0] >= p)
                *top[0]-- = x;
            else
                cerr << "Stack overflow!";
        }
        else
        {
            if (top[1] < p + stacksize - 1)
                *++top[1] = x;
            else
                cerr << "Stack overflow!";
        }
    }
    int Pop(int i)
    {
        di = i;
        if (di == 0)
        {
            if (top[0] < top[1])
                return *++top[0];
            else
                cerr << "Stack empty!";
        }
        else
        {
            if (top[1] > top[0])
                return *top[1]--;
            else
                cerr << "Stack empty!";
        }
        return 1;
    }
};
// 链栈的数据结构及方法的定义
typedef struct NodeType
{
    int data;
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
int GetTop(Stack s, int &e)
{
    if (!s.top)
        return -1;
    else
    {
        e = s.top->data;
        return 1;
    }
}
int Push(Stack &s, int e)
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
int Pop(Stack &s, int &e)
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


int main(){
    Stack s;
    int i;
    InitStack(s);
    Push(s,1);
    Push(s,3);
    Push(s,9);
    Push(s,6);
    Pop(s,i);
    cout<<i<<endl;
    Pop(s,i);
    cout<<i<<endl;
    Pop(s,i);
    cout<<i<<endl;
}