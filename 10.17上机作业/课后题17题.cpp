#include <iostream>
using namespace std;
int strCmp(string pc1, string pc2) {
    int len1 = pc1.length();
    int len2 = pc2.length();
    int len = len1 < len2 ? len1 : len2;
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (pc1[i] != pc2[i]) {
            return pc1[i] > pc2[i] ? 1 : (pc1[i] < pc2[i] ? -1 : 0);
        }
    }
    return len > 0 ? 1 : (len < 0 ? -1 : 0);
}
int main() {
    cout << strCmp("holle", "hello") << endl;
    return 0;
}