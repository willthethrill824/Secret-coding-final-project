#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include "ModInt.h"

using namespace std;

class Polynomial {
private:
    vector<ModInt> coefficients;
    // vector<long long> coefficients;

public:
    Polynomial(const vector<ModInt>& coeffs);
    // Polynomial(const vector<long long>& coeffs);

    // Evaluate f(x)
    ModInt evaluate(const ModInt& x) const;

    // Degree of the polynomial
    int degree() const;

    // Display
    void print() const;
};

#endif