#include <iostream>
using namespace std;

void swap(int *p1, int *p2)
{
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}
void fb(int arr[], int len)
{
    int begin = 0;
    int end = len - 1;
    int cur = 0;
    while (cur <= end)
    {
        if (arr[cur] == 0)
        {
            swap(&arr[cur], &arr[begin]);
            begin++;
            cur++;
        }
        else if (arr[cur] == 1)
        {
            cur++;
        }
        else
        {
            swap(&arr[cur], &arr[end]);
            end--;
        }
    }
}
int main()
{
    int len;
    int i;
    int arr[] = {0, 2, 1, 2, 1, 0, 2, 1, 0, 0, 2, 1};
    len = sizeof(arr) / sizeof(int);
    fb(arr, len);
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}