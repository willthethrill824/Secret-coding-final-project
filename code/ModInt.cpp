#include <iostream>

using namespace std;

#include "ModInt.h"

long long ModInt::mod = 1;
//Constructor:
ModInt::ModInt(long long v){
    value = ((v % mod) + mod) % mod;
}

long long ModInt::modReduce(long long a){
    long long result = a % mod;
    if(result < 0)
        result += mod;
    return result;
}
    
long long ModInt::extendedGCD(long long m, long long n, long long& x, long long& y){
    long long s = 1, t = 0;                               // Initialize (s, t) to (1, 0)
    long long s1 = 0, t1 = 1;                             // Initialize (s1, t1) to (0, 1)
    long long orig_m = m, orig_n = n;                    // Store original values of m and n

    while (n != 0) {                                      // Iterate Euclid's algorithm while n > 0
        long long q = m / n;                              // Calculate current integer division
        long long temp = n;                               // Temporarily store n
        n = m % n;                                        // Update n as remainder
        m = temp;                                         // Update m to previous n

        temp = s1;                                        // Temporarily store s1
        s1 = s - q * s1;                                  // Update s1 using recurrence
        s = temp;                                         // Update s to previous s1

        temp = t1;                                        // Temporarily store t1
        t1 = t - q * t1;                                  // Update t1 using recurrence
        t = temp;                                         // Update t to previous t1
    }

    x = s;                                                // Set x to the coefficient for original m
    y = t;                                                // Set y to the coefficient for original n
    return m;                                             // Return the GCD of original m and n

}
 

long long ModInt::modInverse(long long a, long long m){
    //TODO
    long long x,y;
    long long gcd = extendedGCD(a,m,x,y);
    if(gcd != 1){
        return 0;
    }
    return modReduce(x);
}


void ModInt::setMod(long long m){
    mod = m;
}


long long ModInt::getValue() const {
    return value;
}

long long ModInt::getMod() const {
    return mod;
}

ModInt ModInt::operator+(const ModInt& other) const { //Allows for ModInt c = b + a
    return ModInt(modReduce(this->value + other.value));
} 

ModInt ModInt::operator-(const ModInt& other) const { //Allows for ModInt c = b - a
    return ModInt(modReduce(this->value - other.value));
} 


ModInt ModInt::operator*(const ModInt& other) const { //Allows for ModInt c = b * a
    return ModInt(modReduce(this->value * other.value));
} 

ModInt ModInt::operator/(const ModInt& other) const { //Allows for ModInt c = b / a => c = a * modInverse(b)
    long long inverse = modInverse(other.value, mod);
    return ModInt(modReduce(this->value * inverse));
      
} 

ModInt& ModInt::operator=(const ModInt& other){      //Assignment operator allows c = a
    this->value = other.value;
    return *this;
}
    
bool ModInt::operator==(const ModInt& other) const{  //Returns true if a.value == b.value
    if(this->value == other.value){return true;}
    else{return false;}
}

bool ModInt::operator!=(const ModInt& other) const{  //Returns true if a.value != b.value
    if(this->value != other.value){return true;}
    else{return false;}
} 

void printModInt(const ModInt& m){
    cout << m.getValue();
}

