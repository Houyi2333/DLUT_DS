#include <iostream>
using namespace std;
template <class T>
class ArrayQueue {
   private:
    int maxSize;  // 队列最大容量
    int front;
    int rear;
    T* queue;
    bool tag;

   public:
    ArrayQueue(int size) {
        maxSize = size;
        queue = new T[maxSize];
        front = rear = 0;
        tag = 0;
    }
    ~ArrayQueue() { delete[] queue; }
    void Clear() {
        front = rear;
        tag = 0;
    }
    // 入队函数
    bool EnQueue(const T item) {
        if (IsFull()) {
            cout << "The queue is full!" << endl;
            return false;
        }
        queue[rear] = item;
        rear = (rear + 1) % maxSize;
        if (rear == front)
            tag = 1;
        return true;
    }
    // 出队函数
    bool DeQueue(T& item) {
        if (IsEmpty()) {
            cout << "The queue is empty!" << endl;
            return false;
        }
        item = queue[front];
        front = (front + 1) % maxSize;
        if (rear == front)
            tag = 0;
        return true;
    }
    // 返回头元素函数
    bool GetFront(T& item) {
        if (IsEmpty()) {
            cout << "The queue is empty!" << endl;
            return false;
        }
        item = queue[front];
        return true;
    }
    // 判断是否为空
    bool IsEmpty() {
        if (front == rear && tag == 0) {
            return true;
        } else {
            return false;
        }
    }
    // 判断是否为满
    bool IsFull() {
        if (rear == front && tag == 1) {
            return true;
        } else {
            return false;
        }
    }
};
int main() {
    int maxsize = 0, n = 0, temp1 = 0, temp2 = 0;
    cout << "Enter the maximum queue length" << endl;
    cin >> maxsize;
    cout << "Enter " << maxsize << "numbers as queue elements" << endl;
    ArrayQueue<int> aq(maxsize);
    for (int i = 0; i < maxsize; i++) {
        cin >> n;
        aq.EnQueue(n);
    }
    aq.DeQueue(temp1);
    cout << "Queue out: " << temp1 << endl;
    aq.GetFront(temp2);
    cout << "Read queue rear elements: " << temp2 << endl;
    return 0;
}