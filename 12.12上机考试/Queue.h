#include <iostream>
using namespace std;

template <class T>
class Queue {
   public:
    Queue(int MaxQueueSize = 10);
    ~Queue() { delete[] queue; }
    bool IsEmpty() { return front == rear; }
    bool IsFull() {
        if ((rear + 1) % MaxSize == front)
            return 1;
        else
            return 0;
    }
    T First();  // ���ض���Ԫ��
    void push(const T& x);
    void pop(T& x);

   private:
    int front;    // ���һ��Ԫ���ڷ�ʱ�뷽�������һ��λ��
    int rear;     // ָ�����һ��Ԫ��
    int MaxSize;  // ��������Ĵ�С
    T* queue;     // ����
};

template <class T>
Queue<T>::Queue(int MaxQueueSize) {
    MaxSize = MaxQueueSize;
    queue = new T[MaxSize];
    front = rear = 0;
}

template <class T>
T Queue<T>::First() {
    if (IsEmpty())
        return -1;
    else
        return queue[(front + 1) % MaxSize];
}

template <class T>
void Queue<T>::push(const T& x) {
    if (IsFull()) {
        cout << "no memeory";
        return;
    }
    rear = (rear + 1) % MaxSize;
    queue[rear] = x;
    return;
}

template <class T>
void Queue<T>::pop(T& x) {
    if (IsEmpty()) {
        cout << "no element";
        return;
    }
    front = (front + 1) % MaxSize;
    x = queue[front];
    return;
}
