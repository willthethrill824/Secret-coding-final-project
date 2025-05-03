#include <iostream>
#include "Shamir.h"
#include "Polynomial.h"
#include "Share.h"
#include <cstdlib>
#include <ctime> // Required for seeding

using namespace std;

// Generate a random polynomial of degree k-1 with secret as f(0)
Polynomial generateRandomPolynomial(int degree, const ModInt& secret){
    vector<ModInt> coeffs;
    coeffs.append(secret);
    int randomInt;
    int min = 1;
    int max = secret.getMod() - 1;
    for(int i = 1; i != degree; i++){
        int randomInt = (rand() % (max - min + 1) + min);
        coeffs.append(ModInt(randomInt));
    }
}

// Generate n shares from the polynomial
vector<Share> generateShares(const Polynomial& poly, int n){
    vector<Share> result;
    for(int i = 0; i <= n; i++){
        ModInt x(i);
        ModInt y = poly.evaluate(x);
        result.push_back(share(x,y));
    }
    return result.
}

// Reconstruct secret from k shares using Lagrange interpolation
ModInt reconstructSecret(const std::vector<Share>& shares){
    
}


