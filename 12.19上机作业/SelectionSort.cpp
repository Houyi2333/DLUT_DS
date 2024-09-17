#include <iostream>
using namespace std;
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
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    SelectionSort<int>(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}