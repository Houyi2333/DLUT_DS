#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    cout << isPalindrome("abccbb") << endl;
    return 0;
}
