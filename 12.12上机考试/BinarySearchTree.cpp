
/* �༶��    ������    ѧ�ţ�         */

/*�����������ඨ��*/
#include <iostream>
#include <queue>
using namespace std;
#include "Queue.h"
#include "Stack.h"

class BinarySearchTreeNode  // �����������Ľڵ�
{
   private:
    int element;

   public:
    BinarySearchTreeNode* LeftChild;
    BinarySearchTreeNode* RightChild;
    BinarySearchTreeNode(int ele = 0)  // Ĭ�Ϲ��캯��
    {
        element = ele;
        LeftChild = RightChild = NULL;
    }

    int getValue() const  // ��������ֵ
    {
        return element;
    }
    void setValue(const int& val)  // ��������ֵ
    {
        element = val;
    }
    bool isLeaf() const  // �ж��Ƿ�ΪҶ�ӽ��
    {
        if (RightChild == NULL && LeftChild == NULL)
            return true;
        else
            return false;
    }
};

class BinarySearchTree {
   private:
    BinarySearchTreeNode* root;

   public:
    BinarySearchTree()  // Ĭ�Ϲ��캯��
    {
        root = NULL;
    }
    ~BinarySearchTree()  // ��������
    {
        deletetree(root);
    }
    void deletetree(BinarySearchTreeNode* rt);  // �ú����Ѿ�����ã���Ҫ�Ķ�

    // funAll:����ĺ�����Ҷ�Ҫд
    void insertNode(
        int* a,
        int n);  // ����������������β�������a�е�n�����ظ��ķǸ�����

    // fun0:ѧ�Ÿ�λ��Ϊ0��3��6��9
    // ���x���ڣ����մӴ�С˳�������xΪ������������������ֵ,��������true
    // ���򣬲�����κ���Ϣ����������false
    // �÷ǵݹ��㷨ʵ��
    bool printBefore(int x);

    // fun1:ѧ�Ÿ�λ��Ϊ1��4��7
    // ���x���ڣ����մӴ�С˳�������xΪ������������������ֵ,��������true
    // ���򣬲�����κ���Ϣ����������false
    // �÷ǵݹ��㷨ʵ��
    bool printAfter(int x);

    // fun2��ѧ�Ÿ�λ��Ϊ2��5��8
    // ���x���ڣ��򷵻���xΪ���������ĸ߶ȣ�ֻ��һ�������������߶�Ϊ1
    // ���򣬲�����κ���Ϣ����������false
    // �÷ǵݹ��㷨ʵ��
    int subtreeHeight(int x);
};

void BinarySearchTree::deletetree(BinarySearchTreeNode* recent) {
    if (recent != NULL) {
        deletetree(recent->LeftChild);
        deletetree(recent->RightChild);
        delete recent;
    }
}
// funAll:����ĺ�����Ҷ�Ҫд
void BinarySearchTree::insertNode(int* a, int n) {}
// fun0:ѧ�Ÿ�λ��Ϊ0��3��6��9
// ���x���ڣ����մӴ�С˳�������xΪ������������������ֵ,��������true
// ���򣬲�����κ���Ϣ����������false
// �÷ǵݹ��㷨ʵ��
bool BinarySearchTree::printBefore(int x) {
    return true;
}
// fun1:ѧ�Ÿ�λ��Ϊ1��4��7
// ���x���ڣ����մӴ�С˳�������xΪ������������������ֵ,��������true
// ���򣬲�����κ���Ϣ����������false
// �÷ǵݹ��㷨ʵ��
bool BinarySearchTree::printAfter(int x) {
    return true;
}

// fun2��ѧ�Ÿ�λ��Ϊ2��5��8
// ���x���ڣ��򷵻���xΪ���������ĸ߶ȣ�ֻ��һ�������������߶�Ϊ1
// ���򣬲�����κ���Ϣ����������false
// �÷ǵݹ��㷨ʵ��
int BinarySearchTree::subtreeHeight(int x) {
    return 0;
}

int main() {
    int i;
    BinarySearchTree test;

    int a[10] = {50, 72, 43, 85, 75, 20, 35, 45, 65, 30};

    test.insertNode(a, 10);

    /*
        //����������fun0�����Ĳ���
        int val;
        cout<<"\n������һ��Ҫ�ҵ�����"<<endl;
        cin >>val;
            cout<<"\n��"<<val<<"Ϊ�����������������У�"<<endl;
            test.printBefore(val);
    */
    /*
         //����������fun1�����Ĳ���
        int val;
        cout<<"\n������һ��Ҫ�ҵ�����"<<endl;
        cin >>val;
            cout<<"\n��"<<val<<"Ϊ���������������У�"<<endl;
            test.printAfter(val);
    */

    /*
         //����������fun2�����Ĳ���

        int val;
        cout<<"\n������һ��Ҫ�ҵ�����"<<endl;
        cin >>val;
            cout<<"\n��"<<val<<"Ϊ���������߶�Ϊ��"<<endl;

            cout<<test.subtreeHeight(val)<<endl;
    */
    return 0;
}
/*��������

        50
       /  \
     43    72
    /  \  /  \
   20  45 65 85
    \       /
    35     75
   /
  30

*/
