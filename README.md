# **Secret-coding-final-project**

William Hansen

May 2025

## **Overview**

A C++ implementation of [Shamir's Secret Sharing](https://en.wikipedia.org/wiki/Shamir%27s_secret_sharing), a cryptographic algorithm that allows a secret to be split into multiple parts (shares) and reconstructed only when a minimum number of shares (threshold) are combined. This project was developed as part of a final assignment for a Data Structures course at CSU.

## **Project Overview**

The program showcases how a secret (such as a PIN or location) can be:
- Split into 'shares' using modular arithmetic and polynomial interpolation
- 'Distributed' shares to multiple recipients.
- Reconstructed only when a sufficient number of valid shares are combined

## **Data structures implemented:**
This project combines the use of multiple overlaying custon data structures to perform the different processes. Here are the different structures and their member function purposes:

### **1. ModInt:**
 * The ModInt structure is where the numbers and arithmetic operations are stored. It is a datastructure that holds the values and methods to perform the modular arithmetic needed.
 
   **private:**

    | member      | Description |
    | ----------- | ----------- |
    | static long long mod;    | Holds prime number used in modular arithmetic, set as static so it is the same for all ModInt variable types.       |
    | modReduce(long long a);   | Reduces the input argument a by the mod variable.        |
    | extendedGCD(m, n, x, y)    | Performes Euclidean algorithm to find greatest common divisor of m and n which is needed to find the modular inverse of a value.   |
    | modInverse(a);   | Returns the modular inverse for a % m using the extendedgcd function and coefficient x for (a * x) % m == 1.        |

   **Public:**
    | Member             | Description | Type |
    | -----------        | ----------- | -----|
    |  value             | Holds variable       | long long |
    |  setMod(m)         | Sets mod to m for class | void |
    |  getValue()        | Returns value           | long long |
    |  getMod()          | Returns Mod             | long long |
    |  operator+(other)  | custom operator overload allows for ModInt c = b + a | - |
    |  operator-(other)  | custom operator overload allows for ModInt c = b - a | - |
    |  operator*(other)  | custom operator overload allows for ModInt c = b * a | - |
    |  operator/(other)  | custom operator overload allows for ModInt c = b / a => c = a * modInverse(b) | - |
    |  operator=(other)  | custom operator overload assignment operator allows for c = a | - |
    |  operator==(other) | custom operator overload equal to operator allows for a.value == b.value | bool |
    |  operator!=(other) | custom operator overload not equal to operator allows for a.value != b.value | bool |
    |  printModInt       | Prints current value | - |

### **2. Polynomial:**
 * The Polynomial structure holds the information like coefficients, and ability to evaluate the polynomial k function.

   **Private:**
    | Member             | Description | 
    | -----------        | ----------- | 
    |  vector<modInt> coefficients  | Holds polynomial coefficients       |
 
   **Public:**
    | Member             | Description | 
    | -----------        | ----------- | 
    |  evaluate(modInt x)  | Evaluates the polynomial with the value in x using Horner's method (https://www.geeksforgeeks.org/horners-method-polynomial-evaluation/)       |
    | degree()             | Returns degree of polynomial (k - 1) | 
    | print()  | Prints function with corresponding coefficients(e.g. ax^2 + bx + c)       |

### **3. Share:**
 * Simple structure to hold the x and y value of a share.

    | Member             | Description | 
    | -----------        | ----------- | 
    |  x  | Holds x value      |
    |  y  | Holds y value       |
 

### **4. Shamir:**
 * The Shamir structure handles the polynomial generation, creating a vector of shares, and reconstructing the secret using shares.

    | Member             | Description | 
    | -----------        | ----------- | 
    |  generateRandomPolynomial(degree, secret)  | Generates polynomial object of the given degree setting the secret as the intercept in the polynomial.       |
    |  generateShares(poly, n) | Returns a vector of shares with randomly generated x values evaluated with the given polynomial.      |
    |  reconstructSecret(vector<<.Share>>shares) | Uses Lagrange Interpolation (https://www.geeksforgeeks.org/lagranges-interpolation/) to reconstruct/find the original secret from the points passed in through the vector. Requires at least k number of shares to successfully reconstruct. |

### **5. Other**
 * SSS.cpp
    * Holds two functions to generate and confirm a prime number.
        | Function             | Description | 
        | -----------        | ----------- |
        | bool isPrime(num) | Returns true if function is prime number, tests using square root method (https://www.geeksforgeeks.org/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-that-number-is-prime/) to efficiently confirm if a number is prime. | 
        | getPrimeAbove(threshold) | Generates a prime number a random amount between 1 and 10,000 above the given threshold. |
 * Utils.cpp
    * Holds two functions to encode and decode strings to numbers and vice versa.
        | Function             | Description | 
        | -----------        | ----------- |
        | stringToSecret(msg) | Returns a string encoded using each character's ASCII code and base-95 encoding method by treating each character as a digit in base-95. | 
        | decodeToString | Performs reverse operations of stringToSecret by first taking the value modulus 95 then adding 32 and concatenating the result character by character |
 * Scenarios.cpp 
   * Holds scenario functions for UI implementation

## Building and Running
```
### Build Instructions 

#Clone the repo to desired repository
git clone https://github.com/willthethrill824/Secret-coding-final-project.git

#Open build folder
cd build

#Execute cmake
cmake ..

#Execute make
make

#Executable
./run_app

```

## Goals
The goals of this project were to implement the techniques described to generate a random polynomial following the given secret. Then distribute any amount of shares that are the (x,y) coordinates following this polynomial. The secret can then be reconstructed using Lagrange interpolation of a minimum threshold of shares. 


## Resources:

- [Shamir's secret Sharing](https://en.wikipedia.org/wiki/Shamir%27s_secret_sharing)
- [Euclidean Algorithm](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)
- [Horner's Method](https://en.wikipedia.org/wiki/Horner%27s_method)
- [Horner's ALgorithm](https://www.geeksforgeeks.org/horners-method-polynomial-evaluation/)
- [Lagrange's Interpolation Method](https://www.geeksforgeeks.org/lagranges-interpolation/)
- [Lagrange Interpolation](https://en.wikipedia.org/wiki/Lagrange_polynomial)
