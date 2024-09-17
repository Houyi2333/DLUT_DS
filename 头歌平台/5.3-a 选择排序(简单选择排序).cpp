/*5.3  选择排序

                a.	简单选择排序
                        void SelectionSort(T Data[], int n)

*/

#include <iostream>
using namespace std;

/*
TODO:简单选择排序,排序后Data中元素升序排列
 */
template <class T>
void SelectionSort(T Data[], int n) {
    for (int i = 1; i < n; i++) {
        int min = i - 1;
        for (int j = i; j < n; j++) {
            if (Data[j] < Data[min])
                min = j;
        }
        if (min != i - 1) {
            T temp = Data[min];
            Data[min] = Data[i - 1];
            Data[i - 1] = temp;
        }
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
    SelectionSort<int>(a, n);  // a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}