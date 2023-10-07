//
//  TripleDES.cpp
//  Triple DES
//
//  Created by Fedy C. on 7/11/21.
//  Copyright © 2021 Fedy C. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "TripleDES.h"

/**
 * @method binaryToHex - converts binary text to hexadecimal text
 * @param {std::string} binaryString - the binary input
 * @returns {std::string} hexadecimalString - the hexadecimal output
 */
std::string TripleDES::binaryToHex(std::string binaryString) {
  
  // the return data
  std::string hexadecimalString = "";
  
  // a for loop for each of the characters
  for (int i = 0; i < binaryString.size() / 4; i++) {
    
    // individual hex value in binary
    std::string hexadecimalValue = binaryString.substr((i * 4), 4);
    
    // checks if the binary value is 0
    if (hexadecimalValue == "0000") 
    {
      
      
      hexadecimalString += "0";
      // adds 0 in hex form to the string
    }
    // checks if the binary value is 1
    else if (hexadecimalValue == "0001") 
    {
      
      
      hexadecimalString += "1";
      // adds 1 in hex form to the string
    }
    // checks if the binary value is 10
    else if (hexadecimalValue == "0010") 
    {
      
      
      hexadecimalString += "2";
      // adds 10 in hex form to the string
    }
    // checks if the binary value is 11
    else if (hexadecimalValue == "0011") 
    {
      
      
      hexadecimalString += "3";
      // adds 11 in hex form to the string
    }
    // checks if the binary value is 100
    else if (hexadecimalValue == "0100") 
    {
      
      
      hexadecimalString += "4";
      // adds 100 in hex form to the string
    }
    // checks if the binary value is 101
    else if (hexadecimalValue == "0101") 
    {
      
      
      hexadecimalString += "5";
      // adds 101 in hex form to the string
    }
    // checks if the binary value is 110
    else if (hexadecimalValue == "0110") 
    {
      
      
      hexadecimalString += "6";
      // adds 110 in hex form to the string
    }
    // checks if the binary value is 111
    else if (hexadecimalValue == "0111") 
    {
      
      
      hexadecimalString += "7";
      // adds 111 in hex form to the string
    }
    // checks if the binary value is 1000
    else if (hexadecimalValue == "1000") 
    {
      
      
      hexadecimalString += "8";
      // adds 1000 in hex form to the string
    }
    // checks if the binary value is 1001
    else if (hexadecimalValue == "1001") 
    {
      
      
      hexadecimalString += "9";
      // adds 1001 in hex form to the string
    }
    // checks if the binary value is 1010
    else if (hexadecimalValue == "1010") 
    {
      
      
      hexadecimalString += "A";
      // adds 1010 in hex form to the string
    }
    // checks if the binary value is 1011
    else if (hexadecimalValue == "1011") 
    {
      
      
      hexadecimalString += "B";
      // adds 1011 in hex form to the string
    }
    // checks if the binary value is 1100
    else if (hexadecimalValue == "1100") 
    {
      
      
      hexadecimalString += "C";
      // adds 1100 in hex form to the string
    }
    // checks if the binary value is 1101
    else if (hexadecimalValue == "1101") 
    {
      
      
      hexadecimalString += "D";
      // adds 1101 in hex form to the string
    }
    // checks if the binary value is 1110
    else if (hexadecimalValue == "1110") 
    {
      
      
      hexadecimalString += "E";
      // adds 1110 in hex form to the string
    }
    // checks if the binary value is 1111
    else if (hexadecimalValue == "1111") 
    {
      
      
      hexadecimalString += "F";
      // adds 1111 in hex form to the string
    }
    
  }
  
  // returns the data
  return hexadecimalString;
  
}

/**
 * @method hexToBinary - converts hexadecimal text to binary text
 * @param {std::string} hexadecimalString - the hexadecimal input
 * @returns {std::string} binaryString - the binary output
 */
std::string TripleDES::hexToBinary(std::string hexadecimalString) {
  
  // the return data
  std::string binaryString = "";
  
  // a for loop for each of the characters
  for (int i = 0; i < hexadecimalString.size(); i++) {
    
    // checks if the character 0
    if (hexadecimalString[i] == '0') 
    {
      
      
      binaryString += "0000";
      // adds to the binary string 0 in binary form
    }
    // checks if the character 1
    else if (hexadecimalString[i] == '1') 
    {
      
      
      binaryString += "0001";
      // adds to the binary string 1 in binary form
    }
    // checks if the character 2
    else if (hexadecimalString[i] == '2') 
    {
      
      
      binaryString += "0010";
      // adds to the binary string 2 in binary form
    }
    // checks if the character 3
    else if (hexadecimalString[i] == '3') 
    {
      
      
      binaryString += "0011";
      // adds to the binary string 3 in binary form
    }
    // checks if the character 4
    else if (hexadecimalString[i] == '4') 
    {
      
      
      binaryString += "0100";
      // adds to the binary string 4 in binary form
    }
    // checks if the character 5
    else if (hexadecimalString[i] == '5') 
    {
      
      
      binaryString += "0101";
      // adds to the binary string 5 in binary form
    }
    // checks if the character 6
    else if (hexadecimalString[i] == '6') 
    {
      
      
      binaryString += "0110";
      // adds to the binary string 6 in binary form
    }
    // checks if the character 7
    else if (hexadecimalString[i] == '7') 
    {
      
      // adds to the binary string 7 in binary form
      binaryString += "0111";
      
    }
    // checks if the character 8
    else if (hexadecimalString[i] == '8') 
    {
      
      
      binaryString += "1000";
      // adds to the binary string 8 in binary form
    }
    // checks if the character 9
    else if (hexadecimalString[i] == '9') 
    {
      
      
      binaryString += "1001";
      // adds to the binary string 9 in binary form
    }
    // checks if the character A
    else if (hexadecimalString[i] == 'A') 
    {
      
      
      binaryString += "1010";
      // adds to the binary string A in binary form
    }
    // checks if the character B
    else if (hexadecimalString[i] == 'B') 
    {
      
      
      binaryString += "1011";
      // adds to the binary string B in binary form
    }
    // checks if the character C
    else if (hexadecimalString[i] == 'C') 
    {
      
      
      binaryString += "1100";
      // adds to the binary string C in binary form
    }
    // checks if the character D
    else if (hexadecimalString[i] == 'D') 
    {
      
      
      binaryString += "1101";
      // adds to the binary string D in binary form
    }
    // checks if the character E
    else if (hexadecimalString[i] == 'E') 
    {
      
      
      binaryString += "1110";
      // adds to the binary string E in binary form
    }
    // checks if the character F
    else if (hexadecimalString[i] == 'F') 
    {
      
      
      binaryString += "1111";
      // adds to the binary string F in binary form
    }
    
  }
  
  // returns the data
  return binaryString;
  
}

/**
 * @method applyRound - since there are many rounds to DES this does an individual round
 * @param {std::string} inputedBinaryData - the inputed data in binary form
 * @param {std::string} key - the key for the code
 * @param {int} currentRound - the current round
 * @returns {std::string} encryptedData - the encrypted data
 */
std::string TripleDES::applyRound(std::string inputedBinaryData, std::string key, int currentRound) {
  
  // the result after the data was mangled
  std::string encryptedData = "";
  
  // the left side of the data
  std::string leftSide = inputedBinaryData.substr(32, 32);
  
  // the right side of the data
  std::string rightSide = inputedBinaryData.substr(0, 32);
  
  // std::cout << "Pre-R " + std::to_string(currentRound + 1) + " " + binaryToHex(rightSide) + " " + binaryToHex(leftSide) + " " + binaryToHex(key) + "\n";
  
  // the another copy of the right side of the data
  std::string copyRightSide = leftSide;
  
  // std::cout << "crghtSide " + copyRightSide + "\n";
  // std::cout << "rightSide " + rightSide + "\n";
  // std::cout << "leftSide  " + leftSide + "\n";
  //std::cout << "copyRightSide Pre Expanded: " + copyRightSide + "\n";
  // increases the copy of the right side from 32 bits to 48 bits
  copyRightSide = permutate(copyRightSide, expandingDataFrom32to48, 48);
  
  //std::cout << "copyRightSide Post Expanded:" + copyRightSide + "\n";
  //std::cout << "copyRightSide Xor Pre Add:  " + copyRightSide + "\n";
  // merges the data with the key
  copyRightSide = xorStringAddition(copyRightSide, key);
  
  //std::cout << "copyRightSide Xor Post Add: " + copyRightSide + "\n";
  //std::cout << "copyRightSide Pre S-Box Mangle: " + copyRightSide + "\n";
  // mutates the data
  copyRightSide = applySubstitutionBox(copyRightSide);
  
  //std::cout << "copyRightSide Post S-Box Mangle:" + copyRightSide + "\n";
  //std::cout << "S-Box Mangling: " + copyRightSide + "\n";
  // shrinks the data
  copyRightSide = permutate(copyRightSide, shrinkingDataFrom48to32, 32);
  
  // std::cout << "crghtSide " + copyRightSide + "\n";
  // std::cout << "rightSide " + rightSide + "\n";
  // std::cout << "leftSide  " + leftSide + "\n";
  
  // mangles the left side of the data
  copyRightSide = xorStringAddition(rightSide, copyRightSide);
  
  // combines the two sides
  encryptedData = leftSide + copyRightSide;
  
  // std::cout << "crghtSide " + copyRightSide + "\n";
  // std::cout << "rightSide " + rightSide + "\n";
  // std::cout << "leftSide  " + leftSide + "\n";
  
  std::cout << "Round " + std::to_string(currentRound + 1) + " " + binaryToHex(leftSide) + " " + binaryToHex(copyRightSide) + " " + binaryToHex(key) + "\n";
  
  // returns the result
  return encryptedData;
}

/**
 * @method applySubstitutionBox - converts the inputed data based on the substituionBox array
 * @param {std::string} binaryInput - this is the 48 bit data input to get the coresponding correct value
 * @returns {std::string} binaryOutput - this is the 48 bit data that has been mangled
 */
std::string TripleDES::applySubstitutionBox(std::string binaryInput) {
  
  // the variable for the output
  std::string binaryOutput = "";
  
  // a for loop for all the bits (by a factor of 6)
  for (int i = 0; i < 48; i += 6) 
  {
    
    // gets the string of the current 6 bits that are being analyzed
    std::string currentValue = binaryInput.substr(i, 6);
    
    //std::cout << "S-BOX editing val: " + currentValue + "\n";
    
    // the current number
    int num = i / 6;
    
    // the row into the hex
    std::string rowBin = "00" + std::string(1,currentValue[0]) + std::string(1,currentValue[5]);
    
    //std::cout << "S-BOX editing rowB:" + rowBin + "\n";
    
    // the row of the number by converting the binary into hex then into int
    int row = std::stoul("0x" + binaryToHex(rowBin), nullptr, 16);
    
    //std::cout << "S-BOX editing row: " + std::to_string(row) + "\n";
    
    // the row into the hex
    std::string colBin = currentValue.substr(1, 4);
    
    //std::cout << "S-BOX editing colB:" + colBin + "\n";
    
    // the col of the number
    int col = std::stoul("0x" + binaryToHex(colBin), nullptr, 16);
    
    //std::cout << "S-BOX editing col: " + std::to_string(col) + "\n";
    
    // adds the value found into the binary output and converts it from a number to a string
    binaryOutput += std::bitset< 4 >(substituionBox[num][row][col]).to_string();
  }
  
  // returns the output
  return binaryOutput;
}

/**
 * @method shiftKeyWith - changes the key based on the spacing needed
 * @param {std::string} key - the key
 * @param {int} spacing - the amount that needs to move
 * @returns {std::string} returnKey - the fixed key with the correct placement
 */
std::string TripleDES::shiftKeyWith(std::string key, int spacing) {
  
  // the return string of the fixed key
  std::string returnKey = "";
  
  // changes the value of the return key by creating a substring based on the original key
  returnKey = key.substr(spacing, key.size() - spacing);
  
  // adds the front part of the string
  returnKey = returnKey + key.substr(0, spacing);
  
  // returns the key
  return returnKey;
}

/**
 * @method generateModifiedKeys - creates a huge list of all the modified keys in the rounds
 * @param {std::string} key - the first key that needs to be added in hexadecimal
 * @returns {Array<std::string>} keys - the second key that needs to be added as binary
 */
std::string* TripleDES::generateModifiedKeys(std::string key) {
  
  // the variable for the return value 
  std::string* keys = new std::string[16];
  
  // converts the key into binary
  key = hexToBinary(key);
  
  // removes every 8th bit
  key = permutate(key, keyRemove8thBits, 56);
  
  // loops to create all the keys
  for (int i = 0; i < 16; i++) 
  {
    
    // the left side of the key (splitted to improve security)
    std::string leftSideOfKey = key.substr(0, 28);
    
    // the right side of the key
    std::string rightSideOfKey = key.substr(28, 28);
    
    // shifts the left key based on the data
    leftSideOfKey = shiftKeyWith(leftSideOfKey, shiftKeyTable[i]);
    
    // shifts the right key based on the data
    rightSideOfKey = shiftKeyWith(rightSideOfKey, shiftKeyTable[i]);
    
    // combines the two sides
    key = leftSideOfKey + rightSideOfKey;
    
    // std::cout << "key: " + key + "\n";
    
    // stores the key to the array and compresses it to a 48 bit based key
    keys[i] = permutate(key, keyCompressionArray, 48);
    
    // std::cout << "com: " + keys[i] + "\n";
    
  }
  
  // returns the keys
  return keys;
}

/**
 * @method xorStringAddition - combines two binary strings together in the xor format (1 + 1 == 0, 0 + 0 == 0, 1 + 0 = 1)
 * @param {std::string} a - the first hexadecimal value
 * @param {std::string} b - the second hexadecimal value to be added
 * @returns {std::string} result - the end result
 */
std::string TripleDES::xorStringAddition(std::string a, std::string b) {
  
  // the result variable of the two strings
  std::string result = "";
  
  // converts the first input into binary (to compare it more easily)
  std::string binaryA = a;
  
  // converts the second input into binary
  std::string binaryB = b;
  
  // loops through the whole binary
  for (int i = 0; i < binaryA.size(); i++) 
  {
    
    // checks if both values of A and B on the current one or zero are the same
    if (binaryA[i] == binaryB[i]) 
    {
      
      // adds a 0
      result += "0";
    }
    // checks if the 2 values are not the same
    else 
    {
      
      // adds a 1
      result += "1";
    }
    
  }
  
  // returns the result
  return result;
}

/**
 * @method permutate - this is the function used to rearange data
 * @param {std::string} binInput - the binary byte form of the inputed data
 * @param {int[]} rules - the table used for the function to know how to rearange the data
 * @param {int} length - the size of the return data
 * @returns {std::string} binOutput - the binary byte form of the outputed data
 */
std::string TripleDES::permutate(std::string binInput, int rules[], int length) {
  
  // this is the string hex output
  std::string binOutput = "";
  
  // this is a for loop that goes all the way until the length
  for (int index = 0; index < length; index++) 
  {
    
    // this adds the rearanged character to the hexadecimal output
    binOutput += binInput[rules[index] - 1];
  }
  
  // returns the data
  return binOutput;
}

/**
 * @method reverse - this reverses an array
 * @param {std::string} inputedArray - the inputed data
 * @param {int} start - this is the starting point
 * @param {int} end - this is the ending point
 */
std::string* TripleDES::reverse(std::string* inputedArray, int start, int end) {
  
  // this loops until the whole array is looked
  while (start <= end) 
  {
    
    // this is a temporary
    std::string temp = inputedArray[end];
    
    // this puts in the bottom item to the top
    inputedArray[end] = inputedArray[start];
    
    // this puts in the top item to the bottom
    inputedArray[start] = temp;
    
    // adds one start
    start++;
    
    // removes one from the end
    end--;
    
  }
}

/**
 * @method encrypt - this encrypts the data using 3 keys
 * @param {std::string} inputedText - the inputed data from the user
 * @param {Array<std::string>} keys - the 3 symmetric keys that is used to encrypt/decrypt
 * @returns {std::string} outputedText - the outputed data (hexadecimal)
 */
std::string TripleDES::encrypt(std::string inputedText, std::string* keys) {
  
  // the outputed data (hexadecimal)
  std::string outputedText = "";
  
  // the amount of different chunks of data
  int amountOfChunks = inputedText.size() / 16;
  
  // this is a for loop for all the outputed text
  for (int i = 0; i < amountOfChunks; i++) {
    
    // the encrypted part of the text 
    std::string encryptedText = inputedText.substr(i * 16, 16);
    
    std::cout << "ENCRYPTED DATA:" + encryptedText + "\n";
    
    // this encrypts the text
    encryptedText = singleEncrypt(encryptedText, keys[0]);
    
    std::cout << "ENCRYPTED DATA:" + encryptedText + "\n";
    
    // this encrypts the text using decryption with the second key
    encryptedText = singleDecrypt(encryptedText, keys[1]);
    
    std::cout << "ENCRYPTED DATA:" + encryptedText + "\n";
    
    // this adds one more layer of encryption the text
    encryptedText = singleEncrypt(encryptedText, keys[2]);
    
    std::cout << "ENCRYPTED DATA:" + encryptedText + "\n";
    
    // this adds to the result
    outputedText += encryptedText;
    
  }
  
  // returns the outputed text
  return outputedText;
  
}

/**
 * @method decrypt - this decrypts the data using 3 keys
 * @param {std::string} inputedText - the inputed data from the user
 * @param {Array<std::string>} keys - the 3 symmetric keys that is used to encrypt/decrypt
 * @returns {std::string} outputedText - the outputed data (hexadecimal)
 */
std::string TripleDES::decrypt(std::string inputedText, std::string* keys) {
  
  // the outputed data (hexadecimal)
  std::string outputedText = "";
  
  // the amount of different chunks of data
  int amountOfChunks = inputedText.size() / 16;
  
  // this is a for loop for all the outputed text
  for (int i = 0; i < amountOfChunks; i++) {
    
    // the decrypted part of the text 
    std::string decryptedText = inputedText.substr(i * 16, 16);
    
    std::cout << "ENCRYPTED DATA:" + decryptedText + "\n";
    
    // this decrypts the text using the third key
    decryptedText = singleDecrypt(decryptedText, keys[2]);
    
    std::cout << "ENCRYPTED DATA:" + decryptedText + "\n";
    
    // this decrypts the text using encryption with the second key
    decryptedText = singleEncrypt(decryptedText, keys[1]);
    
    std::cout << "ENCRYPTED DATA:" + decryptedText + "\n";
    
    // this decrypts then the second key
    decryptedText = singleDecrypt(decryptedText, keys[0]);
    
    std::cout << "ENCRYPTED DATA:" + decryptedText + "\n";
    
    // this adds to the result
    outputedText += decryptedText;
    
  }
  
  // returns the outputed text
  return outputedText;
  
}

/**
 * @method singleEncrypt - this encrypts the data
 * @param {std::string} inputedText - the inputed data (hexadecimal)
 * @param {std::string} key - the key used to get the information
 * @returns {std::string} outputedText - the outputed data (hexadecimal)
 */
std::string TripleDES::singleEncrypt(std::string inputedText, std::string key) {
  
  // creates the keys
  std::string* keys = generateModifiedKeys(key);
  
  // this is the value of the outputedText
  std::string outputedText = "";
  
  // this makes the inputed data into binary
  outputedText = hexToBinary(inputedText);
  
  // this mangles the inital data
  outputedText = permutate(outputedText, initialPermutation, 64);
  
  // this prints some information
  std::cout << "After initial permutation: " + binaryToHex(outputedText) + "\n" + "After splitting: L0=" + binaryToHex(outputedText.substr(0, 32)) + " R0=" + binaryToHex(outputedText.substr(32, 32)) + "\n";
  
  // a for loop for all the rounds
  for (int currentRound = 0; currentRound < 16; currentRound++) {
    
    // edits the text
    outputedText = applyRound(outputedText, keys[currentRound], currentRound);
    
  }
  
  // this swaps the right and left side again
  outputedText = outputedText.substr(32, 32) + outputedText.substr(0, 32);
  
  // this mangles the final data
  outputedText = permutate(outputedText, finalPermutation, 64);
  
  // returns the text in hexadecimal
  return binaryToHex(outputedText);
  
}

/**
 * @method singleDecrypt - this decrypts the data
 * @param {std::string} inputedText - the inputed data
 * @param {std::string} key - the key used to get the information
 * @returns {std::string} outputedText - the outputed data
 */
std::string TripleDES::singleDecrypt(std::string inputedText, std::string key) {
  
  // creates the keys
  std::string* keys = generateModifiedKeys(key);
  
  // this reverses the keys so that it decrypts the code correctly
  reverse(keys, 0, 15);
  
  // this is the value of the outputedText
  std::string outputedText = "";
  
  // this makes the inputed data into binary
  outputedText = hexToBinary(inputedText);
  
  // this mangles the inital data
  outputedText = permutate(outputedText, initialPermutation, 64);
  
  // this prints some information
  std::cout << "After initial permutation: " + binaryToHex(outputedText) + "\n" + "After splitting: L0=" + binaryToHex(outputedText.substr(0, 32)) + " R0=" + binaryToHex(outputedText.substr(32, 32)) + "\n";
  
  // a for loop for all the rounds
  for (int currentRound = 0; currentRound < 16; currentRound++) {
    
    // edits the text
    outputedText = applyRound(outputedText, keys[currentRound], currentRound);
    
  }
  
  // this swaps the right and left side again
  outputedText = outputedText.substr(32, 32) + outputedText.substr(0, 32);
  
  // this mangles the final data
  outputedText = permutate(outputedText, finalPermutation, 64);
  
  // returns the text in hexadecimal
  return binaryToHex(outputedText);
}

