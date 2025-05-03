#ifndef MODINT_H
#define MODINT_H

using namespace std;

class ModInt {
private:
    
    
    // Mod(prime) value equivalent for all ModInt instnces
    static long long mod;
    
    // Finds number such that (a * inverse) % m == 1
    //modReduce ensures that a value is reduced modulo mod
    static long long modReduce(long long a);
    // Extended Euclidean Algorithm
    static long long extendedGCD(long long m, long long n, long long& x, long long& y);

    // Compute modular inverse using EEA
    static long long modInverse(long long a, long long m);
public:
    long long value;
    
    ModInt(long long value = 0);
    
    // Set modulus globally
    static void setMod(long long m);
    
    //Return value
    long long getValue() const;
    
    //Return Modulus
    long long getMod() const;

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
    
    // void swap(ModInt& other); // assuming `value` is your internal integer

};


#endif