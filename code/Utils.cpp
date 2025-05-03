#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Utils.h"
#include "ModInt.h"
#include "Scenarios.h"

using namespace std;

long long stringToSecret(const string& msg){
    //MAX: 5
    long long result = 0;
    for (char c : msg) {
        result = result * 95 + (c - 32); // Printable ASCII is 32 to 126
    }
    return result;

}

string decodeToString(ModInt value){
    string result;
    long long val = value.getValue();
    while (val > 0) {
        char c = (val % 95) + 32;
        result = c + result;
        val /= 95;
    }
    return result;
}

void demo(){

    bool running = true;
    int choice;
    
    cout << description << endl;

    while(running){
        cout << "\n --- Shamir's Secret Sharing Demo Menu --- \n";
        cout << "0. | Default Shamir's secret demo\n";
        cout << "1. | Scenario 1: Emergency Metting Location\n";
        cout << "2. | Scenario 2: Safe Access with PIN\n";
        cout << "3. | Legrange Interpolation Description\n";
        cout << "4. | Shamir's Secret Sharing Description\n";
        cout << "5. | Quit \n";
        cout << "Select an option (1-5): ";
        cin >> choice;
        char c;
        switch (choice) {
            case 0:
                cout << def << endl;
                cout << "Would you like to start this scenario?('y' to confirm): ";
                cin >> c;
                if(c == 'y' || c == 'Y') default_();
                break;
            case 1:
                cout << scenario1_desc << endl;
                cout << "would you like to start this scenario?('y' to confirm): ";
                cin >> c;
                if(c == 'y' || c == 'Y') scenario1();
                break;
            case 2:
                cout << scenario2_desc << endl;
                cout << "would you like to start this scenario?('y' to confirm): ";
                cin >> c;
                if(c == 'y' || c == 'Y') scenario2();
                break;
            case 3:
                cout << Lagrange << endl;
                cout << "Enter any key to continue... ";
                cin >> c;
                break;
            case 4:
                cout << SSS << endl;
                cout << "Enter any key to continue... ";
                cin >> c;
                break;
            case 5: 
                cout << "Exiting program. Thank you, Goodbye! \n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please select a valid option. \n";
                cout << "Enter any key to continue... ";
                cin >> c;
                break;
        }
    }
    return;

}
