#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "../code/ModInt.h"
#include "../code/Polynomial.h"
#include "../code/Shamir.h"
#include "../code/Share.h"
#include "../code/SSS.h"
#include "../code/Utils.h"
#include "../code/Scenarios.h"

using namespace std;



int main(){
    //g++ app/main.cpp code/ModInt.cpp code/Polynomial.cpp code/Shamir.cpp code/Share.cpp code/SSS.cpp code/Utils.cpp -o run_app
    //./run_app
      
    demo();
   
    return 0;
}