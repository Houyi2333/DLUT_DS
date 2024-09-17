#include <iostream>
using namespace std;
template <class T>
int Partition(T Data[], int left, int right) {
    T pivot = Data[left];
    while (left < right) {
        while (left < right && Data[right] > pivot)
            right--;
        Data[left] = Data[right];
        while (left < right && Data[left] < pivot)
            left++;
        Data[right] = Data[left];
    }
    Data[left] = pivot;
    return left;
}
template <class T>
void QuickSort(T Data[], int left, int right) {
    if (left >= right)
        return;
    if (left < right) {
        int p = Partition(Data, left, right);
        QuickSort(Data, left, p - 1);
        QuickSort(Data, p + 1, right);
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
    QuickSort<int>(a, 0, n - 1);  // aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}