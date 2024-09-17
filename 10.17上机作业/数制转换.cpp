#include <cmath>
#include <iostream>
using namespace std;
// 将二进制数转换为十进制数
int binaryToDecimal(long long bin) {
    int decimal = 0, i = 0, remainder;
    while (bin != 0) {
        remainder = bin % 10;
        bin /= 10;
        decimal += remainder * pow(2, i);
        i++;
    }
    return decimal;
}
// 将十进制数转换为二进制数
long long decimalToBinary(int dec) {
    long long binary = 0, i = 1;
    while (dec != 0) {
        binary += (dec % 2) * i;
        dec /= 2;
        i *= 10;
    }
    return binary;
}

int main() {
    cout << binaryToDecimal(10010) << endl;
    cout << decimalToBinary(18) << endl;
    return 0;
}
