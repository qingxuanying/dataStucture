#include <iostream>
#include <stdlib.h>
using namespace std;
double Sqrt(double A, double p, double e);
int main()
{
    double A, p, e;
    cout << "请输入 A p e:";
    cin >> A >> p >> e;
    cout << Sqrt(A, p, e) << endl;
    return 0;
}
double Sqrt(double A, double p, double e)
{
    if ((p * p - A) > -e && (p * p - A) < e)
        return p;
    else
        return Sqrt(A, (p + A / p) / 2, e);
}