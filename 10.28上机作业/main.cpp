#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree<char> test;
    BinaryTreeNode<char>*root = NULL, *root2 = NULL;
    string prestr = "ABCDEFG", instr = "CBEDAFG", poststr = "CEDBGFA";
    root = test.buildPreAndIn(prestr, instr);
    root2 = test.buildPostAndIn(poststr, instr);

    cout << "PreAndIn:" << endl;
    cout << "preOrder: ";
    test.preOrder(root);
    cout << endl;

    cout << "inOrder: ";
    test.inOrder(root);
    cout << endl;

    cout << "postOrder: ";
    test.postOrder(root);
    cout << endl;

    cout << "levelOrder: ";
    test.levelOrder(root);
    cout << endl;

    cout << "PostAndIn:" << endl;
    cout << "preOrder: ";
    test.preOrder(root2);
    cout << endl;

    cout << "inOrder: ";
    test.inOrder(root2);
    cout << endl;

    cout << "postOrder: ";
    test.postOrder(root2);
    cout << endl;

    cout << "levelOrder: ";
    test.levelOrder(root2);
    cout << endl;

    test.homeWorkFunction(root);
    return 0;
}
