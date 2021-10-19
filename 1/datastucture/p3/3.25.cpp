#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i;
    int a[100];
    int n;
    cout << "请输入 n:";
    cin >> n;
    for (i = 0; i < n + 1; i++)
    {
        if (i < 1)
            a[i] = 1;
        else
            a[i] = i * a[i / 2];
    }
    cout << a[n] << endl;
    return 0;
}