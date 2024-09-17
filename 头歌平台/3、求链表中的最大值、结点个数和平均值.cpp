/*课后习题1.8-c

                c.
   已知head为单链表的表头指针，链表中存储的都是整形数据，实现下列运算的递归算法：
                        i.	求链表中的最大值
                                int GetMax(Node* a)

                        ii.	求链表中的结点个数
                                int GetNodeNum(Node* a)

                        iii.求所有整数的平均值
                                double GetAvg(Node* a, int n)

*/
#include <iostream>
using namespace std;
const int MinNumber = -1000000;
struct Node {
    Node(int x) {
        value = x;
        next = NULL;
    }
    int value;
    Node* next;
};
/*
TODO:求链表中的最大值,并返回。如果链表a为空，则直接返回MinNumber
*/
int GetMax(Node* a) {
    if (a == NULL) {
        return MinNumber;
    }
    int max = a->value;
    int restMax = GetMax(a->next);
    return (max > restMax) ? max : restMax;
}
/*
TODO:求链表中的结点个数，并返回个数。
 */
int GetNodeNum(Node* a) {
    if (a == NULL) {
        return 0;
    }
    return 1 + GetNodeNum(a->next);
}
/*
TODO: 求所有整数的平均值
*/
double GetAvg(Node* a, int n) {
    if (a == NULL) {
        return 0;
    }
    double sum = a->value + GetAvg(a->next, n - 1) * (n - 1);
    return sum / n;
}

int main() {
    int count;
    cin >> count;
    Node *a = NULL, *p;
    for (int i = 0; i < count; i++) {
        int iValue;
        cin >> iValue;
        if (a == NULL) {
            a = new Node(iValue);
            p = a;
        } else {
            p->next = new Node(iValue);
            p = p->next;
        }
    }
    int max = GetMax(a);
    int nodeNum = GetNodeNum(a);
    double avg = GetAvg(a, nodeNum);
    cout << "最大值：" << max << endl;
    cout << "结点个数：" << nodeNum << endl;
    cout << "平均值：" << avg << endl;
}
