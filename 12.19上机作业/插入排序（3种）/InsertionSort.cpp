#include <iostream>
using namespace std;
//直接插入排序  不减序排序
template <class T>
void InsertionSort(T Data[], int n) {
    int p, i;
    for (p = 1; p < n; p++) {
        T temp = Data[p];
        i = p - 1;
        while (i >= 0 && Data[i] > temp) {
            Data[i + 1] = Data[i];
            i--;
        }
        Data[i + 1] = temp;
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
    InsertionSort<int>(a, n);  // a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}