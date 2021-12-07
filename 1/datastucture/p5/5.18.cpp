#include<iostream>
#include<string.h>
using namespace std;

void rightMove(int a[],int n, int k){
    int tmp;
    int i;
    for(i=0;i<n/2;i++){
        tmp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=tmp; 
    }
    for(i=0;i<k/2;i++){
        tmp=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=tmp;
    }
    for(i=k;i<(n-k)/2+k;i++){
        tmp=a[i];
        a[i]=a[n-i-1+k];
        a[n-1-i+k]=tmp;
    }
}

void show(int a[]){
    int j=0;
    for(int i=0;i<100;i++,j++){
        if(j==10){
            j=0;
            cout<<endl;
        }
        cout<<" "<<a[i];
    }
}

int main(){
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i;
    }
    int k=32;
    rightMove(a,100,k);
    show(a);
}
