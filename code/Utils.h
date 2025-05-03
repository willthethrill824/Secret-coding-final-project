#ifndef UTILS_H
#define UTILS_H

using namespace std;
#include <iostream>
#include <string>
#include <vector> 
#include "Share.h"
#include "ModInt.h"
#include "Scenarios.h"

long long stringToSecret(const string& msg);

string decodeToString(ModInt value);

inline const string description =  "\n\n\nHello and welcome to the demo of my Shamir's secret code project. This project utilizes " 
                        "the ideas surrounding Lagrange interpolation and Modular arithmetic to encode a secret.\nFor the "
                        "demonstration, of the functionality of the programs that I have developed, a default function along with "
                        "two real-world scenarios have been made from which you may choose from.\nPlease review the description for each scenario then "
                        "confirm if you would like to start the scenario or if you would like a deeper explaination "
                        "of the methods used behind the scenes\n\n\n";
inline const string Lagrange = "\n\n\n In this project, I have implemented Lagrange interpolation as a core component of Shamir's Secret Sharing.\n"
                        "Lagrange interpolation is a means of using known points (x,y) to construct a polynomial function\n"
                        "where the intercept (x = 0) is the 'secret' that has been encoded into the polynomial. My \n"
                        "implementation calculates the Lagrange basis polynomials in a modular arithmetic setting to ensure \n"
                        "all oerations remain the same within the finite field defined by a prime modulus. This method \n"
                        "enables accurate reconstruction of the secret when the required threshold number of shares is provided.\n\n\n";
inline const string SSS = "\n\n\nShamir's Secret Sharing is a cryptographic method for securely splitting a secret into multiple parts, called\n"
                        "shares, such that only a minimum threshold number k of those shares is needed to reconstruct the \n"
                        "original secret. Say a secret was split up into 10 shares and the threshold is 3. Any 3 shares together \n"
                        "can be used to reconstruct the secret. To do this the, the secret is embedded as the constant term\n"
                        "(intercept) in a randomly generated polynomial of degree k-1(any 2 points define a line, any 3 points \n"
                        "define a quadratic function, any 4 points define a cubic function , etc.). Any number of shares can \n"
                        "be created by evaluating this polynomial at different non-zero x-values, and any combination of k \n"
                        "valid shares can be used with the polynomial interpolation to recover the secret.\n\n";                        
inline const string def = "\n\n\nThis is the default implementation of the Shamir's secret functionality. Define a secret, threshold,\n"
                        "number of shares, and test process\n\n";
inline const string scenario1_desc = "\n\n\nThe complany is in crisis. After a series of failed product launches and internal audits, \n"
                        "the buisiness teeters on the brink of bankruptcy. In the face of mounting legal and financial \n"
                        "pressure, the CEO and a small group of trusted board members must hold a top-secret emergency \n"
                        "meeting to devise a recovery plan, but the location must remain hidden from outside threats.\n\n"
                        "To protect this sensitive information, the meeting location is encoded as a secret using \n"
                        "Shamir's Secret Sharing. Only a minimum number of trusted members can collaborate to reconstruct \n"
                        "the location. Each board member holds one share of the secret. This scenario simulates the \n"
                        "process of splitting and reconstructing the location using cryptographic sharing principles.\n\n";
inline const string scenario2_desc = "\n\n\nDeep in the secure vault of your organization's headquarters lies a safe containing a device that \n"
                        "holds vital encryption keys. This device can only be accessed with an 8-digit PIN - A critical \n"
                        "secret known only to a small group of senior security officers. However, an emergency arises, \n"
                        "and only some of the officers can be trusted. One of the individuals present may not be a legit\n"
                        "imate officer and is holding a fake/compromised share. If the wrong shares are used, reconstruction \n"
                        "will fail. \n\nYour task is to analyze the provided shares, determine which one is invalid, and use \n"
                        "only the correct ones to recover the original PIN. Precision and logic are key, the safety of your \n"
                        "operation depends on identifying the imposet and unlocking the safe.\n\n";                         


void demo();

#endif