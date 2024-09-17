#include <iostream>
using namespace std;
//希尔排序  不减序排序
template <class T>
void ShellSort(T Data[], int n) {
    int d = n / 2;
    while (d >= 1) {
        for (int k = 0; k < d; k++) {
            for (int i = k + d; i < n; i += d) {
                T temp = Data[i];
                int j = i - d;
                while (j >= k && Data[j] > temp) {
                    Data[j + d] = Data[j];
                    j -= d;
                }
                Data[j + d] = temp;
            }
        }
        d = d / 2;
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
    ShellSort<int>(a, n);  // a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}