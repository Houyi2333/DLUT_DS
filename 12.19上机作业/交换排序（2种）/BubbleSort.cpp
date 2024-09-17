#include <iostream>
using namespace std;
//冒泡排序  不减序排序
template <class T>
void BubbleSort(T Data[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (Data[j] < Data[j - 1]) {
                T temp = Data[j];
                Data[j] = Data[j - 1];
                Data[j - 1] = temp;
            }
        }
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
    BubbleSort<int>(a, n);  // a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}