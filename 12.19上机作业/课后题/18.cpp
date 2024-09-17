#include <algorithm>
#include <iostream>
#include <vector>
void threeWayMerge(std::vector<int>& arr,
                   int left,
                   int mid1,
                   int mid2,
                   int right) {
    int n1 = mid1 - left + 1;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;
    std::vector<int> leftArr(n1);
    std::vector<int> middleArr(n2);
    std::vector<int> rightArr(n3);
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        middleArr[j] = arr[mid1 + 1 + j];
    }
    for (int k = 0; k < n3; ++k) {
        rightArr[k] = arr[mid2 + 1 + k];
    }
    int i = 0, j = 0, k = 0, l = left;
    while (i < n1 && j < n2 && k < n3) {
        if (leftArr[i] <= middleArr[j] && leftArr[i] <= rightArr[k]) {
            arr[l++] = leftArr[i++];
        } else if (middleArr[j] <= leftArr[i] && middleArr[j] <= rightArr[k]) {
            arr[l++] = middleArr[j++];
        } else {
            arr[l++] = rightArr[k++];
        }
    }
    while (i < n1) {
        arr[l++] = leftArr[i++];
    }
    while (j < n2) {
        arr[l++] = middleArr[j++];
    }
    while (k < n3) {
        arr[l++] = rightArr[k++];
    }
}
void threeWayMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int n = right - left + 1;
        if (n > 1) {
            int mid1 = left + n / 3 - 1;
            int mid2 = left + 2 * n / 3 - 1;
            threeWayMergeSort(arr, left, mid1);
            threeWayMergeSort(arr, mid1 + 1, mid2);
            threeWayMergeSort(arr, mid2 + 1, right);
            threeWayMerge(arr, left, mid1, mid2, right);
        }
    }
}
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> arr = {11, 12, 13, 6, 7};
    int n = arr.size();
    std::cout << "初始序列: ";
    printArray(arr);
    threeWayMergeSort(arr, 0, n - 1);
    std::cout << "排序后序列: ";
    printArray(arr);
    std::cout << "时间复杂度为O(nlog3(n))";
    return 0;
}