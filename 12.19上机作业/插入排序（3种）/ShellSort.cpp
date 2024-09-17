#include <iostream>
using namespace std;
//ϣ������  ����������
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
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    ShellSort<int>(a, n);  // aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}