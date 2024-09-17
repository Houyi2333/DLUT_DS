/*课后习题1.8-b
        b.	给定一个不带头结点的单链表，写出将链表倒置的算法
                Node* Reverse(Node* first)
*/
#include <iostream>
using namespace std;
class Node {
   public:
    Node(int x) {
        value = x;
        next = NULL;
    }
    int value;
    Node* next;
};

/*
TODO:链表倒置的算法
 */
Node* Reverse(Node* first) {
    int len = 0;
    Node* head = first;
    Node* a = NULL;
    Node* pTemp;
    while (NULL != first) {
        len++;
        first = first->next;
    }
    first = head;
    int* valueArr = new int[len];
    for (int i = len - 1; i >= 0; i--) {
        valueArr[i] = first->value;
        first = first->next;
    }
    first = head;
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            a = new Node(valueArr[i]);
            pTemp = a;
        } else {
            pTemp->next = new Node(valueArr[i]);
            pTemp = pTemp->next;
        }
    }
    return a;
}
void print(Node* node) {
    while (NULL != node) {
        cout << node->value << " ";
        node = node->next;
    }
}
int main() {
    int iNum;
    cin >> iNum;
    Node* a = NULL;
    Node* pTemp;

    for (int i = 0; i < iNum; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a = new Node(tmp);
            pTemp = a;
        } else {
            pTemp->next = new Node(tmp);
            pTemp = pTemp->next;
        }
    }

    cout << "倒置前为：";
    print(a);
    cout << endl;
    Node* r = Reverse(a);
    cout << "倒置后为：";
    print(r);
    cout << endl;
    return 0;
}
