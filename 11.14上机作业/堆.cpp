#include <iostream>
#include <vector>

class MaxHeap {
   private:
    std::vector<int> heap;

    // ά���ѵ�����
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

   public:
    // ���캯��
    MaxHeap() {}

    // ��ʼ����
    MaxHeap(const std::vector<int>& array) : heap(array) {
        // �����һ����Ҷ�ӽڵ㿪ʼ���жѻ�
        for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // ����Ԫ��
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // ɾ���Ѷ�Ԫ��
    void removeMax() {
        if (heap.empty()) {
            std::cout << "Heap is empty. Cannot remove." << std::endl;
            return;
        }

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    // ��ȡ�Ѷ�Ԫ��
    int getMax() const {
        if (!heap.empty()) {
            return heap[0];
        } else {
            std::cout << "Heap is empty." << std::endl;
            return -1;  // �����׳��쳣
        }
    }

    // ��ӡ���е�Ԫ��
    void printHeap() const {
        for (int value : heap)
            std::cout << value << " ";
        std::cout << std::endl;
    }
};

int main() {
    // ʹ��ʾ��
    MaxHeap maxHeap;
    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(5);
    maxHeap.insert(1);
    std::cout << "����: ";
    maxHeap.printHeap();
    std::cout << "���Ԫ��: " << maxHeap.getMax() << std::endl;
    maxHeap.removeMax();
    std::cout << "ɾ�����Ԫ��: ";
    maxHeap.printHeap();
    return 0;
}
