#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
template <class T>
class BinaryTree;
template <class T>
class BinaryTreeNode {
   private:
    T element;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;

   public:
    friend class BinaryTree<T>;
    BinaryTreeNode() {
        element = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinaryTreeNode(const T& ele) {
        element = ele;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r) {
        element = ele;
        leftChild = l;
        rightChild = r;
    }
    BinaryTreeNode<T>* getLeftChild() const { return leftChild; }
    BinaryTreeNode<T>* getRightChild() const { return rightChild; }
    void setLeftChild(BinaryTreeNode<T>* l) { leftChild = l; }
    void setRightChild(BinaryTreeNode<T>* r) { rightChild = r; }
    T getValue(const T& val) {
        val = element;
        return val;
    }
    void setValue(const T& val) { element = val; }
    bool isLeaf() const {
        if (leftChild == NULL && rightChild == NULL)
            return true;
        else
            return false;
    }
    void showEle() { cout << element << ' '; }
};
template <class T>
class BinaryTree {
   public:
    BinaryTreeNode<T>* root;
    BinaryTree() { root = NULL; }
    ~BinaryTree() { deleteBinaryTree(root); }
    bool isEmpty() const {
        if (root == NULL)
            return true;
        else
            return false;
    }
    BinaryTreeNode<T>* Root() { return root; }

    BinaryTreeNode<T>* buildPreAndIn(string prestr, string instr);
    BinaryTreeNode<T>* buildPostAndIn(string poststr, string instr);
    void levelOrder(BinaryTreeNode<T>* root);
    void preOrder(BinaryTreeNode<T>* root);
    void inOrder(BinaryTreeNode<T>* root);
    void postOrder(BinaryTreeNode<T>* root);

    void deleteBinaryTree(BinaryTreeNode<T>* root);

    void visit(BinaryTreeNode<T>* p) { p->showEle(); }
    BinaryTreeNode<T>* setTree() {
        T ch;
        cin >> ch;
        BinaryTreeNode<T>* treeroot = NULL;
        if (ch == 0 || ch == '0')
            return NULL;
        else {
            treeroot = new BinaryTreeNode<T>;
            treeroot->element = ch;
            treeroot->getLeftChild() = setTree();
            treeroot->getRightChild() = setTree();
            return treeroot;
        }
    }
    void homeWorkFunction(BinaryTreeNode<T>* root);
    int treeHeight(BinaryTreeNode<T>* root);
    int treeMaxWidthNoMap(BinaryTreeNode<T>* root);
    T maxElement(BinaryTreeNode<T>* root);
    void exchangeChild(BinaryTreeNode<T>* root);
    void deleteLeafNode(BinaryTreeNode<T>* root);
    bool isCompleteBinaryTree(BinaryTreeNode<T>* root);
};

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::buildPreAndIn(string prestr, string instr) {
    BinaryTreeNode<char>* root = NULL;
    if (prestr.length() > 0) {
        root = new BinaryTreeNode<char>;
        root->element = prestr[0];
        int index = instr.find(prestr[0]);
        root->leftChild =
            buildPreAndIn(prestr.substr(1, index), instr.substr(0, index));
        root->rightChild =
            buildPreAndIn(prestr.substr(index + 1), instr.substr(index + 1));
    }
    return root;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::buildPostAndIn(string poststr, string instr) {
    BinaryTreeNode<char>* root = NULL;
    if (poststr.length() > 0) {
        root = new BinaryTreeNode<char>;
        root->element = poststr[poststr.length() - 1];
        int index = instr.find(poststr[poststr.length() - 1]);
        root->leftChild =
            buildPostAndIn(poststr.substr(0, index), instr.substr(0, index));
        root->rightChild = buildPostAndIn(
            poststr.substr(index, (poststr.length() - index - 1)),
            instr.substr(index + 1));
    }
    return root;
}

template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root) {
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        nodeQueue.push(pointer);
    while (!nodeQueue.empty()) {
        pointer = nodeQueue.front();
        visit(pointer);
        nodeQueue.pop();
        if (pointer->getLeftChild())
            nodeQueue.push(pointer->leftChild);
        if (pointer->getRightChild())
            nodeQueue.push(pointer->rightChild);
    }
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        visit(root);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        visit(root);
        inOrder(root->rightChild);
    }
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root) {
    if (root != NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        visit(root);
    }
}

template <class T>

void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T>* root) {
    if (root == NULL)
        return;
    BinaryTreeNode<T>* temp = NULL;
    queue<BinaryTreeNode<T>*> node_queue;
    if (root->getLeftChild())
        node_queue.push(root->leftChild);
    if (root->getRightChild())
        node_queue.push(root->rightChild);
    delete root;
    while (!node_queue.empty()) {
        temp = node_queue.front();
        node_queue.pop();
        if (temp->getLeftChild() != NULL)
            node_queue.push(temp->leftChild);
        if (temp->getRightChild() != NULL)
            node_queue.push(temp->rightChild);
        delete temp;
    }
    root = NULL;
}

template <class T>
void BinaryTree<T>::homeWorkFunction(BinaryTreeNode<T>* root) {
    // 统计二叉树中度为0 1 2的个数
    int num_0 = 0, num_1 = 0, num_2 = 0;
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        nodeQueue.push(pointer);
    while (!nodeQueue.empty()) {
        pointer = nodeQueue.front();
        if (pointer->isLeaf())
            num_0++;
        else if (pointer->getLeftChild() && pointer->getRightChild())
            num_2++;
        else
            num_1++;
        nodeQueue.pop();
        if (pointer->getLeftChild())
            nodeQueue.push(pointer->leftChild);
        if (pointer->getRightChild())
            nodeQueue.push(pointer->rightChild);
    }
    cout << "度为0的结点个数: " << num_0 << endl;
    cout << "度为1的结点个数: " << num_1 << endl;
    cout << "度为2的结点个数: " << num_2 << endl;
    // 统计二叉树的高度
    cout << "二叉树的高度为: ";
    cout << this->treeHeight(root) << endl;
    // 统计二叉树的宽度（不包含NULL结点）
    cout << "二叉树的宽度(不包含NULL结点)为: ";
    cout << this->treeMaxWidthNoMap(root) << endl;
    // 计算二叉树各结点最大元素的值
    cout << "二叉树各结点最大元素的值为: ";
    cout << this->maxElement(root) << endl;
    // 判断是否为完全二叉树
    cout << "是否为完全二叉树: ";
    cout << this->isCompleteBinaryTree(root) << endl;
}
template <class T>
int BinaryTree<T>::treeHeight(BinaryTreeNode<T>* root) {
    if (root == NULL) {
        return 0;
    } else
        return 1 + std::max(treeHeight(root->leftChild),
                            treeHeight(root->rightChild));
}
template <class T>
int BinaryTree<T>::treeMaxWidthNoMap(BinaryTreeNode<T>* root) {
    int maxWidth = 0;
    if (root == NULL) {
        return maxWidth;
    }

    // 用队列实现
    queue<BinaryTreeNode<T>*> q;
    q.push(root);
    BinaryTreeNode<T>* curEnd = root;   // 记录当前层的尾结点
    BinaryTreeNode<T>* nextEnd = NULL;  // 记录下一层的尾结点
    int curWidth = 0;

    while (!q.empty()) {
        BinaryTreeNode<T>* node = q.front();
        q.pop();

        // 更新下一层尾结点
        if (node->getLeftChild() != NULL) {
            q.push(node->leftChild);
            nextEnd = node->leftChild;
        }
        if (node->getRightChild() != NULL) {
            q.push(node->rightChild);
            nextEnd = node->rightChild;
        }
        curWidth++;
        // 如果当前结点是该层的尾结点
        if (node == curEnd) {
            maxWidth = max(maxWidth, curWidth);
            curWidth = 0;
            curEnd = nextEnd;
        }
    }
    return maxWidth;
}

template <class T>
T BinaryTree<T>::maxElement(BinaryTreeNode<T>* root) {
    T max = 0;
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        nodeQueue.push(pointer);
    while (!nodeQueue.empty()) {
        pointer = nodeQueue.front();
        if (pointer->element > max)
            max = pointer->element;
        nodeQueue.pop();
        if (pointer->getLeftChild())
            nodeQueue.push(pointer->leftChild);
        if (pointer->getRightChild())
            nodeQueue.push(pointer->rightChild);
    }
    return max;
}
template <class T>
void BinaryTree<T>::exchangeChild(BinaryTreeNode<T>* root) {
    BinaryTreeNode<T> temp;
    if (root == NULL)
        return;
    else {
        if (root->getLeftChild() && root->getRightChild()) {
            temp = root->rightChild;
            root->rightChild = root->leftChild;
            root->leftChild = temp;
        } else if (root->getLeftChild() == NULL && root->getRightChild()) {
            root->leftChild = root->rightChild;
            root->rightChild = NULL;
        } else if (root->getRightChild() == NULL && root->getLeftChild()) {
            root->rightChild = root->letfChild;
            root->letfChild = NULL;
        }
        exchange_child(root->letfChild);
        exchange_child(root->rightChild);
    }
}
template <class T>
void BinaryTree<T>::deleteLeafNode(BinaryTreeNode<T>* root) {
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        nodeQueue.push(pointer);
    while (!nodeQueue.empty()) {
        pointer = nodeQueue.front();
        if (pointer->getLeftChild()->isLeaf()) {
            delete pointer->leftChild;
            pointer->leftChild = NULL;
        }
        if (pointer->getRightChild()->isLeaf()) {
            delete pointer->rightChild;
            pointer->rightChild() = NULL;
        }
        nodeQueue.pop();
        if (pointer->getLeftChild())
            nodeQueue.push(pointer->leftChild);
        if (pointer->getRightChild())
            nodeQueue.push(pointer->rightChild);
    }
}
template <class T>
bool BinaryTree<T>::isCompleteBinaryTree(BinaryTreeNode<T>* root) {
    queue<BinaryTreeNode<T>*> queue;
    queue.push(root);
    BinaryTreeNode<T>* front = NULL;
    // 队列中第一个节点为空跳出
    while (front = queue.front()) {
        queue.push(front->leftChild);
        queue.push(front->rightChild);
        queue.pop();
    }
    while (!queue.empty()) {
        // 第一个空节点之后的节点不为空，则返回
        if (queue.front() != NULL)
            return false;
        queue.pop();
    }
    return true;
}
#endif