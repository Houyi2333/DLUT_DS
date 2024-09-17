#include <iostream>
using namespace std;
int NaiveStrMatching(const string& T, const string& P) {
    if (P.length() > T.length())
        return -1;
    for (int i = 0; i <= T.length() - P.length(); i++) {
        // 如果找到与P首字母相同的字母，开始进行查找
        if (T[i] == P[0]) {
            int j = i, k = 0;
            while (T[j] == P[k] && k < P.length()) {
                j++;
                k++;
            }
            if (k == P.length())
                return i;
        }
    }
    return -1;
}
int main() {
    string T = "grjieroaeahjieroa", P = "jieroa";
    cout << NaiveStrMatching(T, P);
    return 0;
}