#include <iostream>
using namespace std;

const int MAX = 30;
// 交换两个数
void Swap(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}
// 双向冒泡排序
void twoBubbleSort(int arr[], int len)
{
    int left, right, shift, i; // shift为记录左右两端已排序的元素位置

    left = 0;
    right = len - 1;
    shift = 1;
    while (left < right)
    { // 往右排序
        for (i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            { // 第一个数比第二个数大，交换
                Swap(arr[i], arr[i + 1]);
                shift = i;
            }
        }
        right = shift;
        for (i = right - 1; i >= left; i--)
        { // 向左排序
            if (arr[i] > arr[i + 1])
            { // 第一个数比第二个数大，交换
                Swap(arr[i], arr[i + 1]);
                shift = i + 1;
            }
        }
        left = shift;
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    int arr[MAX], i;
    cout << "排序前:";
    //获取一个随机数组
    for (i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    // 调用双向冒泡排序函数
    twoBubbleSort(arr, MAX);

    cout << "\n排序后：";
    for (i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}