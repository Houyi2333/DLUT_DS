#include <iostream>
using namespace std;
void rearrange(int arr[], int n) {
    // 左指针，指向非负数
    int left = 0;
    // 右指针，指向负数
    int right = n - 1;
    while (left <= right) {
        if (arr[left] >= 0 && arr[right] < 0) {
            // 当左指针指向非负数，右指针指向负数时，交换它们的位置
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            // 移动指针，准备处理下一对元素
            left++;
            right--;
        } else if (arr[left] < 0) {
            // 如果左指针指向负数，向右移动
            left++;
        } else if (arr[right] >= 0) {
            // 如果右指针指向非负数，向左移动
            right--;
        }
    }
}

int main() {
    cout << "使用两个指针分别从数组的两端向中间移动，交换负数和非负数的位置，最"
            "终将负数移到非负数之前"
         << endl;
    int n, num;
    cout << "请输入待重排数组元素个数" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "请输入 " << n << " 个元素" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    rearrange(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "时间复杂度为O(n)，空间复杂度为O(1)" << endl;
    return 0;
}