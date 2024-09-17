#include <iostream>
using namespace std;
//����ṹ�����������ֵ����Сֵ
struct MinMax {
    int minValue;
    int maxValue;
};
MinMax findMinAndMax(int arr[], int n) {
    MinMax result;
    if (n == 0) {
        result.minValue = result.maxValue = INT_MIN;
        return result;
    }
    result.minValue = result.maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < result.minValue) {
            result.minValue = arr[i];
        } else if (arr[i] > result.maxValue) {
            result.maxValue = arr[i];
        }
    }
    return result;
}
int main() {
    int n, num;
    cout << "����������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    MinMax result = findMinAndMax(a, n);
    cout << "Min is " << result.minValue << endl;
    cout << "Max is " << result.maxValue << endl;
    return 0;
}