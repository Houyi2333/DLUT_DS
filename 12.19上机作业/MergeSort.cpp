#include <iostream>
using namespace std;
template <class T>
void Merge(T Data[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int i, j, k;
    T* left = new T[len1];
    T* right = new T[len2];
    // ���������ʱ����
    for (i = 0; i < len1; i++)
        left[i] = Data[i + start];
    for (i = 0; i < len2; i++)
        right[i] = Data[i + mid + 1];
    i = 0;
    j = 0;
    for (k = start; k < end; k++) {
        if (i == len1 || j == len2)
            break;
        if (left[i] <= right[j])
            Data[k] = left[i++];
        else
            Data[k] = right[j++];
    }
    // ��Data[start, mid]�������ݣ���ŵ�Data����
    while (i < len1)
        Data[k++] = left[i++];
    // ��Data[mid + 1, end]�������ݣ���ŵ�Data����
    while (j < len2)
        Data[k++] = right[j++];
    // �ͷ��ڴ�
    delete[] left;
    delete[] right;
}
template <class T>
// ��Data[start]-Data[end]֮������н��й鲢����
void MergeSort(T Data[], int start, int end) {
    if (end <= start)
        return;
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(Data, start, mid);
        MergeSort(Data, mid + 1, end);
        Merge(Data, start, mid, end);
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
    MergeSort<int>(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}