#include <iostream>
#include <vector>
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}
void mergeSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int currSize = 1; currSize <= n - 1; currSize *= 2) {
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = std::min(left + currSize - 1, n - 1);
            int right = std::min(left + 2 * currSize - 1, n - 1);

            merge(arr, left, mid, right);
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
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    std::cout << "初始序列: ";
    printArray(arr);
    mergeSort(arr);
    std::cout << "排序后序列: ";
    printArray(arr);
    std::cout << "时间复杂度为O(nlogn)";
    return 0;
}
