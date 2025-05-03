#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include "ModInt.h"

using namespace std;

class Polynomial {
private:
    std::vector<ModInt> coeffs;

public:
    Polynomial(const vector<ModInt>& coeffs);

    // Evaluate f(x)
    ModInt evaluate(const ModInt& x) const;

    // Degree of the polynomial
    int degree() const;

    // Display
    void print() const;
};

#endif