#include <iostream>
using namespace std;
//ð������  ����������
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
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    BubbleSort<int>(a, n);  // aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}