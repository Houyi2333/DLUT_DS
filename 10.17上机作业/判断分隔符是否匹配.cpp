#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
bool isParenthesesMatch(const string& str) {
    ArrayStack<char> sa(100);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            sa.Push(str[i]);
        } else if (str[i] == ')') {
            if (sa.IsEmpty()) {
                return false;
            } else {
                sa.Pop();
            }
        }
        if (str[i] == '[') {
            sa.Push(str[i]);
        } else if (str[i] == ']') {
            if (sa.IsEmpty()) {
                return false;
            } else {
                sa.Pop();
            }
        }
    }
    return sa.IsEmpty();
}
int main() {
    cout << isParenthesesMatch("([())]]") << endl;
    return 0;
}
