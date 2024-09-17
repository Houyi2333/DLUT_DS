/*1.4-a-c 链式栈

        bool Push(const T item)		//1.4-a.	入栈操作
        bool Pop(T& item)			//1.4-b.
   出栈操作，并判断栈是否为空，返回栈顶元素 bool Top(T& item)
   //1.4-c.	读取栈顶元素，但不删除，判断栈是否为空

*/
#include <iostream>
using namespace std;

template <class T>
class LinkNode {
   public:
    T data;             // 数据域
    LinkNode<T>* link;  // 指向后继指针的结点
    LinkNode(const T& el, LinkNode<T>* ptr = 0) {
        data = el;
        link = ptr;
    }
};
template <class T>
class LinkStack {
   public:
    LinkStack() {
        top = NULL;
        size = 0;
    }
    ~LinkStack() { Clear(); }
    void Clear() {
        while (top != NULL) {
            LinkNode<T>* tmp = top;
            top = top->link;
            delete tmp;
        }
        size = 0;
    }

    /*
        TODO:1.4-a.	入栈操作,将item入栈，并返回true
         */
    bool Push(const T item) {
        LinkNode<T>* newNode = new LinkNode<T>(item);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->link = top;
            top = newNode;
        }
        size++;
        return true;
    }
    /*
        TODO:1.4-b.	出栈操作，并判断栈是否为空，将栈顶元素赋值给item
        返回值说明：出栈成功，返回true，否则返回false
        注意：如果栈为空，则打印cout << "栈为空，不能执行出栈操作" <<
       endl;并返回false
         */
    bool Pop(T& item) {
        if (top == NULL) {
            cout << "栈为空，不能执行出栈操作" << endl;
            return false;
        }
        item = top->data;
        LinkNode<T>* tmp = top;
        top = top->link;
        delete tmp;
        size--;
        return true;
    }
    /*
        TODO：1.4-c.	读取栈顶元素，但不删除，判断栈是否为空。
        如果栈为空，则输出打印cout << "栈为空，不能读取栈顶元素" <<
       endl;并返回false， 否则，将栈顶元素获取并赋值给item, 返回true。
         */
    bool Top(T& item) {
        if (top == NULL) {
            cout << "栈为空，不能读取栈顶元素" << endl;
            return false;
        }
        item = top->data;
        return true;
    }

   private:
    LinkNode<T>* top;  // 指向链式栈栈顶的指针
    int size;          // 栈中元素个数
};

int main() {
    LinkStack<int> ls;
    int iNum, temp, temp1 = -1, temp2 = -1;
    cin >> iNum;
    for (int i = 0; i < iNum; i++) {
        ls.Push(i * 10);
    }
    cout << "输入一个入栈数：";
    cin >> temp;
    if (temp != 99999) {
        ls.Push(temp);
    }
    ls.Pop(temp1);
    cout << "出栈：" << temp1 << endl;
    ls.Top(temp2);
    cout << "读取栈顶元素：" << temp2 << endl;
    return 0;
}
