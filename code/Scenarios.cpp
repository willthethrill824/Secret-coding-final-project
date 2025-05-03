#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "ModInt.h"
#include "Polynomial.h"
#include "Shamir.h"
#include "Share.h"
#include "SSS.h"
#include "Utils.h"

using namespace std;

void scenario1(){ 
    srand(time(0));
    vector<string> cities = {"NYC", "DEN", "MSP", "DAL", "LA", "ATL", "TOR", "CHI", "SEA", "PHX", "MIA"};
    map<string, string > city_map = {
        {"NYC", "New York"}, {"DEN","Denver"}, {"MSP", "Minneapolis-St.Paul"}, 
        {"DAL","Dallas"}, {"LA","Los Angeles"}, {"ATL", "Atlanta"}, {"TOR", "Toronto"},
        {"CHI", "Chicago"}, {"SEA", "Seattle"}, {"PHX", "Pheonix"}, {"MIA", "Miami"}}; 
    int rand_idx = rand() % cities.size();
    string city = cities[rand_idx];

    cout << "\n\n\n A secure city has been selected for the emergency meeting: *** " << endl;
    cout << "Encoding the chosen city using Shamir's Secret Sharing ... \n";
    cout << "\nConverting city name to integer number...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nGenerating prime number above this number ...\n";
    this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\nAssigning and setting parammeters...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));

    long long city_num_val = stringToSecret(city);
    long long prime = getPrimeAbove(city_num_val);
    ModInt::setMod(prime);
    ModInt secret_num = ModInt(city_num_val);

    cout << "City Encoded as number: " << city_num_val<< endl;
    cout << "Prime modulus selected: "<< prime << "\n" <<endl;

    int k = 3; //threshold
    int n = 8; //total shares
    Polynomial p = generateRandomPolynomial(k - 1, secret_num);
    vector<Share> shares = generateShares(p, n);
    cout << "Shares have been generated and distributed to board members. \n";
    Share user_share = shares[0];
    cout << "Your share is {x = " << user_share.x.getValue() << ", y = " << user_share.y.getValue() << "}\n";

    cout << "Now, enter " << k - 1 << " share indicies(Trusted board members) (1 to " << n -1 << ") to reconstruct the location\n";
    vector<Share> selectedShares;
    selectedShares.push_back(user_share);

    for(int i = 0; i < k -1; i++){
        int idx;
        cout << "Index " << i + 2 << ": ";
        cin >> idx;
        while(idx < 1 || idx > n-1){
            cout << "Invalid index. Please enter a value between 1 and " << n << ": ";
            cin >> idx;
        }
        selectedShares.push_back(shares[idx]);
    }

    ModInt reconstructed = reconstructSecret(selectedShares);
    string decoded_city = decodeToString(reconstructed);

    cout << "\nReconstructed numeric value: " << reconstructed.getValue() << endl;
    cout << "Decoded city name: " << decoded_city << endl;

    if(decoded_city == city){
        cout << "\nSUCCESS! Emergency meeting location successfully recovered!\n"<< endl;
        cout << "The meeting will be held in " << city_map[decoded_city] << ". \n\n";
    }
    char ret;
    cout << "\n\n\n\nEnter a key to return to menu: ";
    cin >> ret;
    return;
}


void scenario2(){
    cout << "\n\nScenario 2: Safe Access with PIN\n\n";

    //Generate PIN:
    long long pin = rand() % 90000000 + 10000000;
    cout << "Generating a secret PIN (8 digits): ********\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));

    int k = 3;
    int n = 8;
    long long prime = getPrimeAbove(pin);
    ModInt::setMod(prime);
    ModInt secret = ModInt(pin);
    cout << "The minimum required shares to 'unlock' the secret is : " <<k << endl;
    Polynomial p = generateRandomPolynomial(k -1, secret);
    vector<Share> shares = generateShares(p, n);
    this_thread::sleep_for(chrono::seconds(1));
    cout << "There are only "<< n << " shares that have been created. \n";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Distributing shares to security officers ... \n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " .\n";
    
    Share user_share = shares[0];
    cout<< "Your share is share 0: {x = "<< user_share.x.getValue() <<", y = "<< user_share.y.getValue()<<"}\n";

    vector<Share> chosenShares;
    set<int> selected;
    while(selected.size() < 3){
        int index = rand() % (n -1) +1;
        selected.insert(index);
    }


    cout << "You have identified 3 other 'security officers' (One of them is fraudulent)\n";
    chosenShares.push_back(shares[0]);
    for(int idx: selected){
        chosenShares.push_back(shares[idx]);
    }

    int fake_index = rand() %(chosenShares.size()-1) + 1;
    chosenShares[fake_index].y = ModInt((chosenShares[fake_index].y.getValue() + 12345) % prime);

    for(int j = 0; j < chosenShares.size(); j++){
        cout << "Share #" << j << ": {x = " << chosenShares[j].x.getValue()
            << ", y = " << chosenShares[j].y.getValue() << "}\n";
    }
    this_thread::sleep_for(chrono::seconds(1));

    while (true) {
        cout << "\nYou must identify the valid shares to recover the PIN.\n";
        cout << "Enter the two other indices (1-3) shares to use: ";
        
        vector<int> indices(k - 1);
        for (int i = 0; i < k - 1; i++) {
            cout << "\nShare " << i+1 << ": ";
            cin >> indices[i];
            // Input validation: must be 1, 2, or 3
            while (indices[i] < 1 || indices[i] > 3) {
                cout << "Invalid index. Please enter an index between 1 and 3: ";
                cin >> indices[i];
            }
        }

        // Form reconstruction vector
        vector<Share> attemptShares;
        attemptShares.push_back(chosenShares[0]); // User's own share at index 0
        for (int i : indices) {
            attemptShares.push_back(chosenShares[i]);
        }

        ModInt reconstructed = reconstructSecret(attemptShares);

        if (reconstructed.getValue() == pin) {
            cout << "\nCorrect! The PIN has been successfully reconstructed: " << pin << "\n";
            break;
        } else {
            cout << "\nIncorrect. The reconstructed value was: " << reconstructed.getValue() << ". Try again.\n";
        }
    }
    char ret;
    cout << "\n\n\n\nEnter a key to return to menu: ";
    cin >> ret;
    return;
}

void default_(){
    srand(time(0));
     
    string secret;
    cout << "\n\n\nEnter a string(length < 6): ";
    cin >> secret;    
    cout << "Original secret string: '" << secret << "'" << endl;
    
    long long secret_num_val = stringToSecret(secret);
    // long long secret_num_val = 12345678;
    long long thresh = secret_num_val;
    long long this_prime = getPrimeAbove(thresh);
    ModInt::setMod(this_prime);
    ModInt secret_num = ModInt(secret_num_val);

    cout << "Original secret num: " << secret_num.getValue() << endl;
    cout << "Decoded secret num : " << decodeToString(secret_num) << endl;
    
    // long long this_prime = 14775983;
    cout<< "This prime Modulus generation: "<< this_prime << endl;


    int threshold = 3;
    int totalShares = 10;
    cout << "Enter a threshold number of k(default = 3, please use less than 5): ";
    cin >> threshold;
    while(threshold < 1 || threshold > 5){
        cout << "Invalid index. Please enter a value between 1 and " << 5 << ": ";
        cin>>threshold;
    };
    cout << "Enter a total number of shares(Greater than threshold, default = 10, please use less than 100): ";
    cin >> totalShares;
    while(totalShares < threshold || totalShares > 100){
        cout << "Invalid index. Please enter a value between 1 and " << 100 << ": ";
        cin>>threshold;
    };
    
    Polynomial poly = generateRandomPolynomial(threshold-1, secret_num);
    cout << threshold << " - 1 Polynomial: " << endl;
    poly.print();
    vector<Share> shares = generateShares(poly, totalShares);

    cout << "\n Generated Shares:" << endl;

    for(int share = 0; share < shares.size()-1; share++){
        cout << "Share " << share + 1 << ": x = " << shares[share].x.getValue()
            << ", y = " << shares[share].y.getValue() << endl;
    }

    vector<Share> chosenShares;
    cout<< "\n\nPlease indicate " << threshold <<" indicies(within 0 to "<< totalShares -1 << ") to use to reconstruct the secret. \n";
    for(int i = 0; i < threshold; i++){
        int idx;
        cout << "Share " << i << ": ";
        cin >> idx;
        while(idx < 1 || idx > totalShares-1){
            cout << "Invalid index. Please enter a value between 1 and " << totalShares << ": ";
            cin >> idx;
        }
        chosenShares.push_back(shares[idx -1]);
    }
    // vector<Share> chosenShares = {shares[0], shares[2], shares[4], shares[6]};

    // STEP 6: Reconstruct the secret using Lagrange interpolation
    ModInt recovered = reconstructSecret(chosenShares);
    cout << "\nRecovered number: " << recovered.getValue() << endl;
    cout << "Original secret num: " << secret_num.getValue() << endl;

    string recoveredStr = decodeToString(recovered);
    cout << "Recovered secret string: '" << recoveredStr << "'" << endl;

    // STEP 7: Validate reconstruction
    if (recovered == secret_num) {
        cout << "\n✅ Secret reconstruction successful!" << endl;
    } else {
        cout << "\n❌ Secret reconstruction failed." << endl;
    }

    char ret;
    cout << "\n\n\n\nEnter a key to return to menu: ";
    cin >> ret;
    return;

}