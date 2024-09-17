#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int medianOfThree(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);

    return mid;
}
int partition(std::vector<int>& arr, int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivotValue) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
void quicksort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
}
void testSortTime(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = rand();
    }
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(arr, 0, N - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "N: " << N << " 估计用时: " << N * N * 0.5
              << " 实际用时: " << duration.count() << " ms\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int initialN = 1000;
    int maxN = 32000;
    while (initialN <= maxN) {
        testSortTime(initialN);
        initialN *= 2;
    }
    return 0;
}