#include <iostream>
using namespace std;
//折半插入排序  不减序排序
template <class T>
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
    cout << "请输入待排序数组元素个数" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "请输入 " << n << " 个元素" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    BinaryInsertionSort<int>(a, n);  // a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}