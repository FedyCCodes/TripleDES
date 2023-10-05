//
//  test.cpp
//  Triple DES
//
//  Created by Fedy Cherif on 7/11/21.
//  Copyright © 2021 Fedy Cherif. All rights reserved.
//

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include "TripleDES.h"

int main(int argc, const char * argv[]) {
  // the main function
  
  TripleDES *des = new TripleDES();
  // creates the class
  
  // Below here, it tests the core methods of the class to see that it is working
  
  cout << "Testing TripleDES::hexToBinary (input: F98FA3210FBC228A)" << endl;
  cout << des->hexToBinary("F98FA3210FBC228A") << endl;
  
  cout << "Testing TripleDES::hexToBinary (input: 1111100110001111101000110010000100001111101111000010001010001010)" << endl;
  cout << des->binaryToHex("1111100110001111101000110010000100001111101111000010001010001010") << endl;
  
  cout << "Testing TripleDES::shiftKeyWith (input: 0100101)" << endl;
  cout << des->shiftKeyWith("0100101", 1) << endl;
  
  cout << "Testing TripleDES::permutate (inputs: 1111100110001111101000110010000100001111101111000010001010001010, TripleDES::initialPermutation)" << endl;
  cout << des->permutate("1111100110001111101000110010000100001111101111000010001010001010" , des->initialPermutation, 64) << endl;
  
  cout << "Testing TripleDES::xorStringAddition (inputs: 01001, 11101)" << endl;
  cout << (des->xorStringAddition("001001", "011101")) << endl;
  
  string text = "123456ABCD132536";
  // this is the the input data
  
  string key1 = "AABB09182736CCDD";
  string key2 = "B8091827AACCDD36";
  string key3 = "22B8091827CC89AA";
  // these are the keys
  
  string keys[3] = {key1, key2, key3};
  // this is an array for all the keys
  
  cout << "Encryption:" << endl;
  text = des->encrypt(text, keys);
  cout << "\nCipher Text: " + text << endl;
  cout << "Decryption" << endl;
  text = des->decrypt(text, keys);
  cout << "\nPlain Text: " + text << endl;
  
  
  
  return 0;
}
