/*5.4  归并排序

                a.	归并排序
                        void MergeSort(T Data[], int start, int end)
                        void Merge(T Data[], int start, int mid, int end)
*/

#include <iostream>
using namespace std;

template <class T>
/*
TODO:函数Merge，参数Data是待归并数组，其中对Data[start,mid]和Data[mid+1, end]
  之间的数据进行归并
*/
void Merge(T Data[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int i, j, k;
    T* left = new T[len1];
    T* right = new T[len2];
    //左半数组临时储存
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
    //若Data[start, mid]还有数据，则放到Data后面
    while (i < len1)
        Data[k++] = left[i++];
    //若Data[mid + 1, end]还有数据，则放到Data后面
    while (j < len2)
        Data[k++] = right[j++];
    //释放内存
    delete[] left;
    delete[] right;
}

/*
TODO:对Data[start]-Data[end]之间的序列进行归并排序,排序后使得Data中元素升序排列
 */
template <class T>
//对Data[start]-Data[end]之间的序列进行归并排序
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
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    // a为待排序的数组，0为数组的第一个位置，n-1为数组的最后一个位置
    MergeSort<int>(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}