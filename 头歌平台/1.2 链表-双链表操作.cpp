/*1.2-g 双链表

        void Insert(const T& num)
   //在表尾插入结点 void createList()
   //构建双链表 DLLNode<T>* findValue(const T& value)
   //查找值为value的结点，返回第一个value值的结点，若不存在返回NULL void
   deleteValue(const T& value)			//删除所有值为value的结点

*/
#include <iostream>
using namespace std;

template <class T>
class DLLNode {
   public:
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;

    DLLNode(const T info,
            DLLNode<T>* prevVal = NULL,
            DLLNode<T>* nextVal = NULL) {
        data = info;
        prev = prevVal;
        next = nextVal;
    }
};

template <class T>
class DLLinkList {
   public:
    DLLNode<T>*head, *tail;
    DLLinkList() { head = tail = NULL; }

    /*
        TODO:
       在双链表的表尾插入值为num的DLLNode结点，注意考虑空链表场景的插入操作
         */
    void Insert(const T& num) {
        DLLNode<T>* newNode = new DLLNode<T>(num);
        if (head == NULL) {  // 空链表
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 构建双链表
    void createList() {
        cout << "输入链表，以0为结尾：";
        T i;
        cin >> i;
        while (i != 0 && i != '0') {
            Insert(i);
            cin >> i;
        }
    }

    /*
        TODO:查找值为value的结点，返回第一个value值的结点，若不存在则返回NULL
        */
    DLLNode<T>* findValue(const T& value) {
        DLLNode<T>* p = head;
        while (p != NULL && p->data != value) {
            p = p->next;
        }
        return p;  // 返回找到的节点指针或NULL
    }

    /*
        TODO：删除所有值为value的结点,如果未找到，则打印cout <<
       "不存在值为value的结点" << endl;并返回。
         */
    void deleteValue(const T& value) {
        DLLNode<T>* p = head;
        bool flag = false;  // 标记是否找到了节点
        while (p != NULL) {
            if (p->data == value) {
                if (p->prev != NULL)
                    p->prev->next = p->next;  // 非头节点
                else {
                    head = p->next;  // 头节点
                    head->prev = NULL;
                }

                if (p->next != NULL)
                    p->next->prev = p->prev;  // 非尾节点
                else {
                    tail = p->prev;  // 尾节点
                    tail->next = NULL;
                }
                DLLNode<T>* temp = p;  // 释放该节点的空间
                p = p->next;
                delete temp;
                flag = true;
            } else
                p = p->next;
        }
        if (!flag)
            cout << "不存在值为value的结点" << endl;
    }
    // 打印整个链表
    void printList() {
        DLLNode<T>* p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    int value1, value2;
    DLLinkList<int> DLL;
    DLL.createList();
    DLL.printList();
    cin >> value1 >> value2;
    DLL.Insert(value1);  // 插入value1
    DLL.printList();
    DLL.deleteValue(value2);  // 删除value2
    DLL.printList();
    return 0;
}