#include <iostream>

using namespace std;

#include "ModInt.h"

int ModInt::mod = 1;
//Constructor:
ModInt::ModInt(long int v){
    this->value = v;
}

int ModInt::modReduce(int a){
    int result = a % mod;
    if(result < 0)
        result += mod;
    return result;
}
    
int ModInt::extendedGCD(int m, int n, int& x, int& y){
    //swap m, n to ensure m>n
    if(n > m){
        int temp = m;
        m = n;
        n = temp;
    }
    if(m >= 0 and n >=0){
        int s1 = 1, t1 = 0;                             //Initialize (s2, t2) to (0, 1)
        int s2 = 0, t2 =  1;     
        int k = 0, q = 0;
        int s1_h = 0, t1_h = 0;
        int s2_h = 0, t2_h = 0;
        
                               
        while (n > 0){                                  //Iterate Euclid algorithm while n > 0           
            k = m % n;                                  //Calculate current remainder
            q = m / n;                                  //Calculate current int division
            m = n;                                      //update new value of m
            n = k;                                      //update new value of n
            s1_h = s2;                                  //Updating s1,t1
            t1_h = t2;
            s2_h = s1 - q * s2;                         //calculating s2,t2 for next iteration
            t2_h = t1 - q * t2;    
            s1 = s1_h;                                  //Updating s1,t1 as previous s2,t2
            t1 = t1_h;                      
            s2 = s2_h;                                  //updating s2,t2 as calculation
            t2 = t2_h;
        }
        x = s1;
        y = t1;
        return m; // GCD
    }
    else{return 0;
        }
}
 

int ModInt::modInverse(int a, int m){
    //TODO
    int x,y;
    int gcd = extendedGCD(a,m,x,y);
    if(gcd != 1){
        return 0;
    }
    return modReduce(x);
}


void ModInt::setMod(int m){
    mod = m;
}


long int ModInt::getValue() const {
    return value;
}

long int ModInt::getMod() const {
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
    int inverse = modInverse(other.value, mod);
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