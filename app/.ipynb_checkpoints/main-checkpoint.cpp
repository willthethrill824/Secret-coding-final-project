#include <iostream>
#include "../code/ModInt.h"
#include "../code/Polynomial.h"
#include "../code/Shamir.h"
// #include "../code/Share.h"
// #include "../code/ShareStore.h"
#include "../code/SSS.h"
#include "../code/Utils.h"

using namespace std;

#include <string>


int main(){
    //g++ app/main.cpp code/SSS.cpp code/ModInt.cpp code/Polynomial.cpp code/Utils.cpp -o run_app
    //./run_app
    srand(time(0));
    
    int thresh = 5000;
    int this_prime = getPrimeAbove(thresh);
    cout<< "This prime generation: "<< this_prime << endl;
    
    ModInt A = ModInt(10);
    A.setMod(this_prime);
    
    cout << "This secret: " << A.getValue() << endl;
    
    int min = 1;
    int max = A.getMod() -1;
    int randomInt = (rand() % (max - min + 1) + min);
    
    cout << "Random Int less than " << this_prime << " is : " << randomInt << endl;
   
    string secret = "tacobell";
    cout << "Our secret: '" << secret << "'" <<endl;
    
    ModInt secret_num = stringToSecret(secret);
    cout << "Secret message number: " << secret_num.getValue() << endl;
    
    cout << "Decoded message : " << decodeToString(secret_num.getValue()) << endl;
    
   

    return 0;
}