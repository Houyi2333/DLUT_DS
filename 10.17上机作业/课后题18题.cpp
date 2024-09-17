#include <iostream>
using namespace std;
int reverseNaiveStrMatching(const string& T, const string& P) {
    if (P.length() > T.length())
        return -1;
    for (int i = T.length() - 1; i >= P.length() - 1; i--) {
        // 如果找到与P尾字母相同的字母，开始进行查找
        if (T[i] == P[P.length() - 1]) {
            int j = i, k = P.length() - 1;
            while (T[j] == P[k] && k >= 0) {
                j--;
                k--;
            }
            if (k == -1)
                return i - P.length() + 1;
        }
    }
    return -1;
}
int main() {
    string T = "hellohellohellohello", P = "hello";
    cout << reverseNaiveStrMatching(T, P);
    return 0;
}