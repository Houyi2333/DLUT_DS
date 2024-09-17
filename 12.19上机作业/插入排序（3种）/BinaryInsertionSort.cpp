#include <iostream>
using namespace std;
//�۰��������  ����������
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
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    BinaryInsertionSort<int>(a, n);  // aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}