
#include <iostream>
#include "Polynomial.h"
#include "ModInt.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<ModInt> coefficients;

Polynomial::Polynomial(const vector<ModInt>& coeffs){
   coefficients = coeffs;
}

ModInt Polynomial::evaluate(const ModInt& x) const {
    ModInt result = ModInt(0);
    for(int i = coefficients.size() - 1; i >= 0; --i){ //Horner's method to evaluate polynomial
        result = result * x + coefficients[i];
    }
    return result;
}



int Polynomial::degree() const {
    for(int i = static_cast<int>(coefficients.size()) -1; i >= 0; i--){
        if(coefficients[i].getValue() != 0){
            return i;
        }
    }
    return -1;
}

void Polynomial::print() const {
    if (coefficients.empty()) {
        cout << "0" << endl;
        return;
    }
    
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        long long val = coefficients[i].getValue();
        if (val == 0) continue;

        if (i != coefficients.size() - 1 && val > 0) cout << " + ";

        cout << val;
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;
    }
    cout << endl;
}