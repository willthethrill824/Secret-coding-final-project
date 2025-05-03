#include <iostream>
using namespace std;

#include <string>
#include "Utils.h"
#include "ModInt.h"

ModInt stringToSecret(const string& msg){
    long int value = 0;
    for(char c: msg){
        value = value * 256 + static_cast<unsigned char>(c);
    }
    return value;
}

string decodeToString(long int value){
    string result;
    while(value > 0){
        char c = static_cast<char>(value %256);
        result = c + result;
        value /= 256;
    }
    return result;
}
