/*4.1  折半查找算法*/

#include <iostream>
using namespace std;

/*
TODO:折半查找算法,折半查找过程，Array[0,…,n-1]为待查找的有序数据记录，key为查找的记录
查找成功，返回该元素所在位置,查找不成功，返回-1

 */
template <class T>
//折半查找过程，Array[0,…,n-1]为待查找的有序数据记录，key为查找的记录
int BiSearch(T Array[], T key, int n) {
    int left, mid, right;
    left = 0;
    right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key < Array[mid])
            right = mid - 1;
        else if (key > Array[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    int n, num;
    cin >> n;
    int* A = new int[n];
    //输入应为有序的顺序表
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> num;
    int index = BiSearch<int>(A, num, n);
    if (index == -1) {
        cout << "查找不成功" << endl;
    } else {
        cout << num << " 的位置为： " << index;
    }
    return 0;
}