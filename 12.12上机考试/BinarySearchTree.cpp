
/* 班级：    姓名：    学号：         */

/*二叉搜索树类定义*/
#include <iostream>
#include <queue>
using namespace std;
#include "Queue.h"
#include "Stack.h"

class BinarySearchTreeNode  // 二叉搜索树的节点
{
   private:
    int element;

   public:
    BinarySearchTreeNode* LeftChild;
    BinarySearchTreeNode* RightChild;
    BinarySearchTreeNode(int ele = 0)  // 默认构造函数
    {
        element = ele;
        LeftChild = RightChild = NULL;
    }

    int getValue() const  // 返回数据值
    {
        return element;
    }
    void setValue(const int& val)  // 设置数据值
    {
        element = val;
    }
    bool isLeaf() const  // 判断是否为叶子结点
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
    BinarySearchTree()  // 默认构造函数
    {
        root = NULL;
    }
    ~BinarySearchTree()  // 析构函数
    {
        deletetree(root);
    }
    void deletetree(BinarySearchTreeNode* rt);  // 该函数已经定义好，不要改动

    // funAll:下面的函数大家都要写
    void insertNode(
        int* a,
        int n);  // 向二叉搜索树中依次插入数组a中的n个不重复的非负数据

    // fun0:学号个位数为0，3，6，9
    // 如果x存在，则按照从大到小顺序输出以x为根的左子树的所有数值,函数返回true
    // 否则，不输出任何信息，函数返回false
    // 用非递归算法实现
    bool printBefore(int x);

    // fun1:学号个位数为1，4，7
    // 如果x存在，则按照从大到小顺序输出以x为根的右子树的所有数值,函数返回true
    // 否则，不输出任何信息，函数返回false
    // 用非递归算法实现
    bool printAfter(int x);

    // fun2：学号个位数为2，5，8
    // 如果x存在，则返回以x为根的子树的高度，只有一个根结点的子树高度为1
    // 否则，不输出任何信息，函数返回false
    // 用非递归算法实现
    int subtreeHeight(int x);
};

void BinarySearchTree::deletetree(BinarySearchTreeNode* recent) {
    if (recent != NULL) {
        deletetree(recent->LeftChild);
        deletetree(recent->RightChild);
        delete recent;
    }
}
// funAll:下面的函数大家都要写
void BinarySearchTree::insertNode(int* a, int n) {}
// fun0:学号个位数为0，3，6，9
// 如果x存在，则按照从大到小顺序输出以x为根的左子树的所有数值,函数返回true
// 否则，不输出任何信息，函数返回false
// 用非递归算法实现
bool BinarySearchTree::printBefore(int x) {
    return true;
}
// fun1:学号个位数为1，4，7
// 如果x存在，则按照从大到小顺序输出以x为根的右子树的所有数值,函数返回true
// 否则，不输出任何信息，函数返回false
// 用非递归算法实现
bool BinarySearchTree::printAfter(int x) {
    return true;
}

// fun2：学号个位数为2，5，8
// 如果x存在，则返回以x为根的子树的高度，只有一个根结点的子树高度为1
// 否则，不输出任何信息，函数返回false
// 用非递归算法实现
int BinarySearchTree::subtreeHeight(int x) {
    return 0;
}

int main() {
    int i;
    BinarySearchTree test;

    int a[10] = {50, 72, 43, 85, 75, 20, 35, 45, 65, 30};

    test.insertNode(a, 10);

    /*
        //下面是用于fun0函数的测试
        int val;
        cout<<"\n请输入一个要找的数据"<<endl;
        cin >>val;
            cout<<"\n以"<<val<<"为根的左子树的数据有："<<endl;
            test.printBefore(val);
    */
    /*
         //下面是用于fun1函数的测试
        int val;
        cout<<"\n请输入一个要找的数据"<<endl;
        cin >>val;
            cout<<"\n以"<<val<<"为根的右子树数据有："<<endl;
            test.printAfter(val);
    */

    /*
         //下面是用于fun2函数的测试

        int val;
        cout<<"\n请输入一个要找的数据"<<endl;
        cin >>val;
            cout<<"\n以"<<val<<"为根的子树高度为："<<endl;

            cout<<test.subtreeHeight(val)<<endl;
    */
    return 0;
}
/*测试用例

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
