#include "point.cpp"

class Node{   
    public:
        Point *p;
        Node *up;
        Node *bottom;
        Node *right;
        Node *left;
        Node();
        Node(Point *p);
        Node(Point *p,Node *up,Node *bottom , Node *right, Node *left);
        Node* getUp();
        Node* getBottom();
        Node* getRight();
        Node* getLeft();
        Point* getPoint();
        void setUp(Node *up){
            this->up = up;
        };
        void setBottom(Node *bottom){
            this->bottom = bottom;
        };
        void setRight(Node *right){
            this->right = right;
        };
        void setLeft(Node *left){
            this->left = left;
        };
        void setPoint(Point *p){
            this->p = p;
        };
};

Node::Node(){
    this->p = NULL;
    this->right = NULL;
    this->bottom = NULL;
}

Node::Node(Point *p){
    this->p = p;
    this->bottom = NULL;
    this->right = NULL;
}

Node::Node(Point *p,Node *up,Node *bottom , Node *right, Node *left){
    this->p = p;
    this->up = up;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
}

Node* Node::getUp(){
    return this->up;
}

Node* Node::getLeft(){
    return this->left;
}
Node* Node::getRight(){
    return this->right;
}
Node* Node::getBottom(){
    return this->bottom;
}
Point* Node::getPoint(){
    return this->p;
}
