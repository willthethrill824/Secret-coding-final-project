#include <iostream>
#include "Shamir.h"
#include "Polynomial.h"
#include "Share.h"
#include <cstdlib>
#include <ctime> // Required for seeding
#include <vector>
#include <map>

using namespace std;

// Generate a random polynomial of degree k-1 with secret as f(0)
Polynomial generateRandomPolynomial(int degree, const ModInt& secret){
    vector<ModInt> coeffs;
    coeffs.push_back(secret);
    long long min = 1;
    long long max = secret.getMod() - 1;
    for(int i = 1; i != degree; i++){
        long long randomInt = (rand() % (max - min + 1) + min);
        // coeffs.insert(coeffs.begin(),(randomInt));
        coeffs.push_back(ModInt(randomInt));
    }
    return Polynomial(coeffs);
}


// Generate n shares from the polynomial
vector<Share> generateShares(const Polynomial& poly, int n){
    vector<Share> result;

    vector<long long> x_vals;
    map<long long, bool> used;
    while(x_vals.size()< n){
        long long val = (rand() % 500) + 1;
        if(!used[val]){
            used[val] = true;
            x_vals.push_back(val);
        }
    }
    for(long long i = 0; i <= n; i++){
        ModInt x(x_vals[i]);
        ModInt y = poly.evaluate(x);
        result.push_back(Share(x,y));
    }
    return result;
}

// Reconstruct secret from k shares using Lagrange interpolation
ModInt reconstructSecret(const std::vector<Share>& shares){
    ModInt secret(0);
    int k = shares.size(); //k is minimum number of shares required to reconstruct polynomial

    for(int i = 0; i < k; ++i){
        ModInt numerator(1);    // Declare numerator and denominator as class ModInt so we can perform
        ModInt denominator(1);  //     modular arithmetic
        cout << "\n--- Processing share " << i + 1 << " (x = " << shares[i].x.getValue()
             << ", y = " << shares[i].y.getValue() << ") ---" << endl;
        ModInt y_i = shares[i].y;
        for(int j = 0; j < k; ++j){
            if(j!=i){
                ModInt numerator = ModInt(0) - shares[j].x;
                ModInt denominator = shares[i].x - shares[j].x;
                y_i = y_i * (numerator / denominator);
            }
        }
        secret = secret + y_i;
        cout << "   Partial sum of secret: " << secret.getValue() << endl;                                                       
    }
    cout << "\nFinal Reconstructed Secret (number): " << secret.getValue() << endl;
    return secret;
}


