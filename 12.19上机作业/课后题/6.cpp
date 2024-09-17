#include <iostream>
using namespace std;
void rearrange(int arr[], int n) {
    // ��ָ�룬ָ��Ǹ���
    int left = 0;
    // ��ָ�룬ָ����
    int right = n - 1;
    while (left <= right) {
        if (arr[left] >= 0 && arr[right] < 0) {
            // ����ָ��ָ��Ǹ�������ָ��ָ����ʱ���������ǵ�λ��
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            // �ƶ�ָ�룬׼��������һ��Ԫ��
            left++;
            right--;
        } else if (arr[left] < 0) {
            // �����ָ��ָ�����������ƶ�
            left++;
        } else if (arr[right] >= 0) {
            // �����ָ��ָ��Ǹ����������ƶ�
            right--;
        }
    }
}

int main() {
    cout << "ʹ������ָ��ֱ��������������м��ƶ������������ͷǸ�����λ�ã���"
            "�ս������Ƶ��Ǹ���֮ǰ"
         << endl;
    int n, num;
    cout << "���������������Ԫ�ظ���" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "������ " << n << " ��Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    rearrange(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)" << endl;
    return 0;
}