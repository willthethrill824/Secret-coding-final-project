#ifndef MODINT_H
#define MODINT_H

using namespace std;

class ModInt {
private:
    long int value;
    
    // Mod(prime) value equivalent for all ModInt instnces
    static int mod;
    
    // Finds number such that (a * inverse) % m == 1
    //modReduce ensures that a value is reduced modulo mod
    static int modReduce(int a);
    // Extended Euclidean Algorithm
    static int extendedGCD(int a, int b, int& x, int& y);

    // Compute modular inverse using EEA
    static int modInverse(int a, int m);
public:
    ModInt(long int v = 0);
    
    // Set modulus globally
    static void setMod(int m);
    
    //Return value
    long int getValue() const;
    
    //Return Modulus
    long int getMod() const;

    // Arithmetic operators
    ModInt operator+(const ModInt& other) const; //Allows for ModInt c = b + a
    ModInt operator-(const ModInt& other) const; //Allows for ModInt c = b - a
    ModInt operator*(const ModInt& other) const; //Allows for ModInt c = b * a
    ModInt operator/(const ModInt& other) const; //Allows for ModInt c = b / a => c = a * modInverse(b)
    
    // Assignment
    ModInt& operator=(const ModInt& other);      //Assignment operator allows c = a
    
    //Comparison
    bool operator==(const ModInt& other) const;  //Returns true if a.value == b.value
    bool operator!=(const ModInt& other) const;  //Returns true if a.value != b.value

    // Output
    void printModInt(const ModInt& m);
};

#endif