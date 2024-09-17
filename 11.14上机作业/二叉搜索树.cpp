#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;
template <class T>
class BinarySearchTreeNode {
    friend class BinarySearchTree<T>;

   private:
    T element;
    BinarySearchTreeNode<T>* leftChild;
    BinarySearchTreeNode<T>* rightChild;

   public:
    BinarySearchTreeNode();
    BinarySearchTreeNode(const T& ele) {
        element = ele;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinarySearchTreeNode(const T& ele,
                         BinarySearchTreeNode<T>* l,
                         BinarySearchTreeNode<T>* r) {
        element = ele;
        leftChild = l;
        rightChild = r;
    }
    BinarySearchTreeNode<T>* getLeftChild() const { return leftChild; }
    BinarySearchTreeNode<T>* getRightChild() const { return rightChild; }
    void setLeftChild(BinarySearchTreeNode<T>* l) { leftChild = l; }
    void setRightChild(BinarySearchTreeNode<T>* r) { rightChild = r; }
    T getValue() const { return element; }
    void setValue(const T& val) { element = val; }
    bool isLeaf() const {
        if (leftChild == NULL && rightChild == NULL)
            return true;
        return false;
    }
};
template <class T>
class BinarySearchTree {
   private:
    BinarySearchTreeNode<T>* root;

   public:
    BinarySearchTree() { root = NULL; }
    BinarySearchTree(BinarySearchTreeNode<T>*& r) { root = r; }
    void createSearchTree();
    void visit(BinarySearchTreeNode<T>* current);
    BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root, T x);
    void insertNode(const T& value);
    void deleteByCopying(BinarySearchTreeNode<T>*& node);
    void inOrder(BinarySearchTreeNode<T>* root);
    void setRoot(BinarySearchTreeNode<T>* r);
    BinarySearchTreeNode<T>* getRoot();
    BinarySearchTreeNode<T>* getParent(BinarySearchTreeNode<T>* root,
                                       BinarySearchTreeNode<T>* current) const;
};
template <class T>
void BinarySearchTree<T>::createSearchTree() {
    int a;
    cout << "输入int型，以0为结束" << endl;
    cin >> a;
    while (a != 0) {
        insertNode(a);
        cin >> a;
    }
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getRoot() {
    return root;
}

template <class T>
void BinarySearchTree<T>::setRoot(BinarySearchTreeNode<T>* r) {
    this->root = r;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getParent(
    BinarySearchTreeNode<T>* root,
    BinarySearchTreeNode<T>* current) const {
    if (root != NULL) {
        if (root == current) {
            cout << "该节点为根结点，无父结点" << endl;
            return NULL;
        } else if (root->leftChild == current || root->rightChild == current) {
            return root;
        } else {
            getParent(root->leftChild, current);
            getParent(root->rightChild, current);
        }
    }
}

template <class T>
void BinarySearchTree<T>::visit(BinarySearchTreeNode<T>* current) {
    cout << current->element << " ";
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::search(
    BinarySearchTreeNode<T>* root,
    T x) {
    BinarySearchTreeNode<T>* current = root;
    if (current->element == x) {
        return current;
    } else if (x < current->element) {
        if (current->leftChild == NULL) {
            return NULL;
        }
        return search(current->leftChild, x);
    } else {
        if (current->rightChild == NULL) {
            return NULL;
        }
        return search(current->rightChild, x);
    }
}

template <class T>
void BinarySearchTree<T>::insertNode(const T& value) {
    BinarySearchTreeNode<T>* p = root;
    BinarySearchTreeNode<T>* prev = NULL;
    while (p != 0) {
        prev = p;
        if (value <= p->getValue())
            p = p->leftChild;
        else if (value > p->getValue())
            p = p->rightChild;
    }
    if (root == NULL) {
        root = new BinarySearchTreeNode<T>(value);
    } else if (value <= prev->getValue()) {
        prev->leftChild = new BinarySearchTreeNode<T>(value);
    } else if (value > prev->getValue()) {
        prev->rightChild = new BinarySearchTreeNode<T>(value);
    }
}

template <class T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchTreeNode<T>*& node) {
    if (node->leftChild != NULL && node->rightChild != NULL) {
        BinarySearchTreeNode<T>* maxNode = node->leftChild;
        BinarySearchTreeNode<T>* pre = node;
        while (maxNode->rightChild != NULL) {
            pre = maxNode;
            maxNode = maxNode->rightChild;
        }
        node->element = maxNode->element;
        pre->leftChild = maxNode->leftChild;
        delete (maxNode);
    } else if (node->leftChild != NULL) {
        node->element = node->leftChild->element;
        node->leftChild = node->leftChild->leftChild;
        // delete (node->leftChild);
    } else if (node->rightChild != NULL) {
        node->element = node->rightChild->element;
        node->rightChild = node->rightChild->rightChild;
        // delete (node->rightChild);
    } else {
        BinarySearchTreeNode<T>* parent = getParent(root, node);
        parent->leftChild = NULL;
        parent->rightChild = NULL;
    }
}

template <class T>
void BinarySearchTree<T>::inOrder(BinarySearchTreeNode<T>* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        visit(root);
        inOrder(root->rightChild);
    }
}

int main() {
    BinarySearchTreeNode<int>*tmp1, *tmp2;
    BinarySearchTree<int> st;
    st.createSearchTree();
    tmp1 = st.getRoot();
    st.inOrder(tmp1);
    cout << endl;
    cout << "插入结点" << endl;
    int temp;
    cin >> temp;
    st.insertNode(temp);
    st.inOrder(tmp1);
    cout << endl;
    cout << "输入一个需要查找的值" << endl;
    cin >> temp;                   // 输入一个需要查找的值
    tmp2 = st.search(tmp1, temp);  // 找到值temp 返回结点，找不到返回NULL
    if (tmp2 != NULL) {
        cout << "查找的值为: " << tmp2->getValue() << endl;
        // st.deleteByCopying(tmp2);
        // st.inOrder(tmp1);
    } else
        cout << "不存在值" << temp << endl;
    cout << "输入一个需要删除的值" << endl;
    cin >> temp;
    tmp2 = st.search(tmp1, temp);
    if (tmp2 != NULL) {
        cout << "删除的值为: " << tmp2->getValue() << endl;
        st.deleteByCopying(tmp2);
        st.inOrder(tmp1);
    } else
        cout << "不存在值" << temp << endl;
    return 0;
}
