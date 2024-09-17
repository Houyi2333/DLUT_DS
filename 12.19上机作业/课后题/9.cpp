#include <iostream>
#include <map>
typedef std::map<int, int> Polynomial;
Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    for (auto& term : p2) {
        result[term.first] += term.second;
    }
    return result;
}
void printPolynomial(const Polynomial& p) {
    for (auto i = p.rbegin(); i != p.rend(); i++) {
        std::cout << i->second << "x^" << i->first;
        if (std::next(i) != p.rend()) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}
int main() {
    Polynomial p1 = {{3, 4}, {2, 4}, {1, 2}};
    Polynomial p2 = {{2, 3}, {0, 4}};
    Polynomial p3 = addPolynomials(p1, p2);
    printPolynomial(p1);
    std::cout << "+";
    printPolynomial(p2);
    std::cout << "=";
    printPolynomial(p3);
    return 0;
}
