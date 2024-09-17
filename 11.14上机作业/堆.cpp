#include <iostream>
#include <vector>

class MaxHeap {
   private:
    std::vector<int> heap;

    // 维护堆的性质
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
    // 构造函数
    MaxHeap() {}

    // 初始化堆
    MaxHeap(const std::vector<int>& array) : heap(array) {
        // 从最后一个非叶子节点开始进行堆化
        for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // 插入元素
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // 删除堆顶元素
    void removeMax() {
        if (heap.empty()) {
            std::cout << "Heap is empty. Cannot remove." << std::endl;
            return;
        }

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    // 获取堆顶元素
    int getMax() const {
        if (!heap.empty()) {
            return heap[0];
        } else {
            std::cout << "Heap is empty." << std::endl;
            return -1;  // 或者抛出异常
        }
    }

    // 打印堆中的元素
    void printHeap() const {
        for (int value : heap)
            std::cout << value << " ";
        std::cout << std::endl;
    }
};

int main() {
    // 使用示例
    MaxHeap maxHeap;
    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(5);
    maxHeap.insert(1);
    std::cout << "最大堆: ";
    maxHeap.printHeap();
    std::cout << "最大元素: " << maxHeap.getMax() << std::endl;
    maxHeap.removeMax();
    std::cout << "删除最大元素: ";
    maxHeap.printHeap();
    return 0;
}
