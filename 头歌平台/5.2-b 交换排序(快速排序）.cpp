/*5.2   交换排序

                b.	快速排序
                        void QuickSort(T Data[], int left, int right)
                        int Partition1(T Data[], int left, int right)
*/
#include <iostream>
using namespace std;

/*
TODO:实现对data[left]到data[right]的分割操作，并返回划分后轴元素对应的位置,返回轴元素的新位置，实现分治
*/
template <class T>
int Partition1(T Data[], int left, int right) {
    T pivot = Data[left];
    while (left < right) {
        while (left < right && Data[right] > pivot)
            right--;
        Data[left] = Data[right];
        while (left < right && Data[left] < pivot)
            left++;
        Data[right] = Data[left];
    }
    Data[left] = pivot;
    return left;
}

/*
TODO:用分治法实现快速排序算法,排序后Data中元素按升序排列
 */
template <class T>
void QuickSort(T Data[], int left, int right) {
    if (left >= right)
        return;
    if (left < right) {
        int p = Partition1(Data, left, right);
        QuickSort(Data, left, p - 1);
        QuickSort(Data, p + 1, right);
    }
}

int main() {
    int n, num;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    // a为待排序的数组，0为数组的第一个位置，n-1为数组的最后一个位置
    QuickSort<int>(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}