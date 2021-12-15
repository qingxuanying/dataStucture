#include <iostream>
using namespace std;

class Point{
    private :
        int x;
        int y;
        int val;
    public :
        Point();
        Point(int x,int y,int val);
        int getX();
        int getY();
        int getValue();
        void setX(int x);
        void setY(int y);
        void setValue(int value);
        void show();
};

Point::Point(){
    this->x = 0;
    this->y = 0;
    this->val = 1;
}

Point::Point(int x,int y,int val){
    this->x = x;
    this->y = y;
    this->val = val;
}

int Point::getX(){
    return this->x;
}

int Point::getY(){
    return this->y;
}

int Point::getValue(){
    return this->val;
}

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

void Point::setValue(int value){
    this->val = value;
}

void Point::show(){
    cout<<"("<<this->x <<","<<this->y <<")"<< endl;
}