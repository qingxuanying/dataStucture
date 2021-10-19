#include <iostream>
#include <stdlib.h>
using namespace std;

#define N 10
double polynomail(int a[],int i,double x,int n);
int main(){
double x;
int n,i;
int a[N];
cout<<"输入变量的值 x:";
cin>>x;
cout<<"输入多项式的阶次 n:";
cin>>n;
if(n>N-1) exit(0);
cout<<"输入多项式的系数 a[0]--a[n]:";
for(i=0;i<=n;i++) cin>>a[i];
cout<<"多项式的结果 "<<polynomail(a,n,x,n)<<endl;
return 0;
}
double polynomail(int a[],int i,double x,int n)
{
if(i>0) return a[n-i]+polynomail(a,i-1,x,n)*x;
else return a[n];
}
//o(n)