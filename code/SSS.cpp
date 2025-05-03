#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime> // Required for seeding

using namespace std;

#include "SSS.h"

bool isPrime(long long num){
    if(num <= 1) return false;
    if(num <= 3) return false;
    if(num % 2 == 0 or num % 3 == 0) return false;
    
    for(long long i = 5; i * i <= num; i += 6){
        if(num % i == 0 or num % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

long long getPrimeAbove(long long threshold){ // (int max size = 2,147,483,647) Could use larger sized datatypes to hold and generate larger primes
    long long min = 0;
    long long max = 10000;
    long long randomOffset = (rand() % (max - min + 1) + min);
    
    long long startValue = threshold + randomOffset;
    if(startValue % 2 == 0){ //Ensure startValue is odd
        startValue++;
    }
    long long currentValue = startValue;
    while(!isPrime(currentValue)){
        currentValue += 2;
    }
    return currentValue;
}