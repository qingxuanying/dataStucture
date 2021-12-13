#include <iostream>
using namespace std;

template <class T>
class ListNode{
    public:
        //ListNode *pre;
        ListNode<T> *next;
        T data;
};

template <class T>
class Queue{
    private:
        ListNode<T> *head;
        ListNode<T> *rear;
        int size;
    public:
        Queue();
        bool isEmpty();
        void offer(T t);
        T poll();
        T peek();
        int Size();
};

template <class T>
Queue<T>::Queue(){
    ListNode<T> *p = new ListNode<T>;
//    p->pre = NULL;
    p->next = NULL;
    head = p;
    rear = head;
    size = 0;
}

template <class T>
void Queue<T>::offer(T t){
    ListNode<T> *p = new ListNode<T>;
    p->data = t;
    p->next = NULL;
    rear->next = p;
    rear = rear->next;
    size++;
}

template <class T>
T Queue<T>::poll(){
    if(head == rear){
        throw "都空了还想抛出？！";
    }
    ListNode<T> *p = head;
    head = head->next;
    T ans = head->data;
    delete p;
    size--;
    return ans;
}

template<class T>
T Queue<T>::peek(){
    return this->head->next->data;
} 

template <class T>
bool Queue<T>::isEmpty(){
    return head == rear;
}

template <class T>
int Queue<T>::Size(){
    return size;
}

