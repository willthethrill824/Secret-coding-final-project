#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime> // Required for seeding

using namespace std;

#include "SSS.h"

bool isPrime(int num){
    if(num <= 1) return false;
    if(num <= 3) return false;
    if(num % 2 == 0 or num % 3 == 0) return false;
    
    for(int i = 5; i * i <= num; i += 6){
        if(num % i == 0 or num % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

int getPrimeAbove(int threshold){ // (int max size = 2,147,483,647) Could use larger sized datatypes to hold and generate larger primes
    int min = 0;
    int max = 10000;
    int randomOffset = (rand() % (max - min + 1) + min);
    
    int startValue = threshold + randomOffset;
    if(startValue % 2 == 0){ //Ensure startValue is odd
        startValue++;
    }
    int currentValue = startValue;
    while(!isPrime(currentValue)){
        currentValue += 2;
    }
    return currentValue;
}