#ifndef UTILS_H
#define UTILS_H

using namespace std;
#include <iostream>
#include <string>
#include "ModInt.h"

ModInt stringToSecret(const string& msg);

string decodeToString(long int value);


#endif