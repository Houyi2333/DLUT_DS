/*5.1  插入排序

                b.	折半插入排序
                        void BinaryInsertionSort(T Data[], int n)

*/
#include <iostream>
using namespace std;

/*
TODO:折半插入排序,使得排序后Data中的数据按递增排序
 */
template <class T>
// 参数：待排序数据和待排序元素个数
void BinaryInsertionSort(T Data[], int n) {
    int left, mid, right, p;
    for (p = 1; p < n; p++) {
        T temp = Data[p];
        left = 0;
        right = p - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (Data[mid] > temp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int i = p - 1; i >= left; i--)
            Data[i + 1] = Data[i];
        Data[left] = temp;
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

    BinaryInsertionSort<int>(a, n);  // a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}