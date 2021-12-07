//1.	设计函数找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[20];

int indexof(int x, int l)
{
    int flag = 0;
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == x)
        {
            flag = 1;
        }
    }
    return flag;
}
int solvion1(int n, int k, int sum, int l)
{
    if (l == k)
    {
        if (sum == n)
        {
            for (int i = 0; i < k; i++)
            {
                printf("%2d ", arr[i]);
            }
            printf("\n");
        }
        return 0;
    }
    if (sum >= n)
    {
        return 0;
    }

    for (int i = 1; i < 10; i++)
    {
        if (indexof(i, l))
        {
            continue;
        }
        arr[l] = i;
        solvion1(n, k, sum + arr[l], l + 1);
    }
    return 1;
}

int main()
{
    int n = 8;
    int k = 3;
    solvion1(n, k, 0, 0);
    return 0;
}