#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NodeType
{
    char  data;
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
    Stack s;
    char Buffer[80];
    int i = 0, j = 0;
    InitStack(s);
    cout << "请输入硬席(H)和软席车厢(S)序列：";
    cin >> Buffer;
    cout << Buffer << endl;
    while (Buffer[i])
    {
        if (Buffer[i] == 'S')
        {
            Buffer[j] = Buffer[i];
            j++;
        }
        else
            Push(s, Buffer[i]);
        i++;
    }
    while (Buffer[j])
    {
        Pop(s, Buffer[j]);
        j++;
    }
    cout << Buffer << endl;
    return 0;
}