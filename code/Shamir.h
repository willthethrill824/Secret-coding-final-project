#ifndef SHAMIR_H
#define SHAMIR_H

#include <vector>
#include "Polynomial.h"
#include "Share.h"

// Generate a random polynomial of degree k-1 with secret as f(0)
Polynomial generateRandomPolynomial(int degree, const ModInt& secret);

// Generate n shares from the polynomial
std::vector<Share> generateShares(const Polynomial& poly, int n);

// Reconstruct secret from k shares using Lagrange interpolation
ModInt reconstructSecret(const std::vector<Share>& shares);

#endif
