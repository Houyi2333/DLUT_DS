/*1.7-a 朴素的模式匹配算法

        //1.7-a.
   朴素的模式匹配算法，返回子串第一次出现的位置，若不存在，返回-1 int
   NaiveStrMatch(const string& T, const string& P)

*/
#include <string.h>
#include <iostream>
using namespace std;

/*
TODO：1.7-a.朴素的模式匹配算法，返回子串第一次出现的位置，若不存在，返回-1
*/
int NaiveStrMatch(const string& T, const string& P) {
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
                return i + 1;
        }
    }
    return -1;
}
int main() {
    int result;
    string t = "I Lo Love Programing";
    string p = "Love";
    getline(cin, t);
    getline(cin, p);
    result = NaiveStrMatch(t, p);
    if (result != -1) {
        cout << "目标字符串中存在于第" << result << "位上" << endl;
    } else {
        cout << "没有找到" << endl;
    }
    return 0;
}