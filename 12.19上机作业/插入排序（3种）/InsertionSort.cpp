#include <iostream>
using namespace std;
//ֱ�Ӳ�������  ����������
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
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    InsertionSort<int>(a, n);  // aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}