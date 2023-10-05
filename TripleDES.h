//
//  TripleDES.h
//  Triple DES
//
//  Created by Fedy Cherif on 7/11/21.
//  Copyright © 2021 Fedy Cherif. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @class TripleDES - This is the triple DES class for encrypting and decrypting data
 */
class TripleDES
{
  
  public:
    
    /**
     * @property {Array<int>} keyRemove8thBits - The permutation data for converting the key from 64 bit to 56 bit
     */
    int keyRemove8thBits[56] = {
      57, 49, 41, 33, 25, 17, 9,
      1, 58, 50, 42, 34, 26, 18,
      10, 2, 59, 51, 43, 35, 27,
      19, 11, 3, 60, 52, 44, 36,
      63, 55, 47, 39, 31, 23, 15,
      7, 62, 54, 46, 38, 30, 22,
      14, 6, 61, 53, 45, 37, 29,
      21, 13, 5, 28, 20, 12, 4
    };
    
    /**
     * @property {Array<int>} shiftKeyTable - The amount of keys that move
     */
    int shiftKeyTable[16] = {
      1, 1, 2, 2,
      2, 2, 2, 2,
      1, 2, 2, 2,
      2, 2, 2, 1
    };
    
    /**
     * @property {Array<int>} keyCompressionArray - The permutation data for converting the key from 56 bit to 48 bit
     */
    int keyCompressionArray[48] = {
      14, 17, 11, 24, 1, 5,
      3, 28, 15, 6, 21, 10,
      23, 19, 12, 4, 26, 8,
      16, 7, 27, 20, 13, 2,
      41, 52, 31, 37, 47, 55,
      30, 40, 51, 45, 33, 48,
      44, 49, 39, 56, 34, 53,
      46, 42, 50, 36, 29, 32 
    };
    
    
    /**
     * @property {Array<int>} initialPermutation - the table of how the 64 bits are mangled in the begining of the conversion
     */
    int initialPermutation[64] = {
      58, 50, 42, 34, 26, 18, 10, 2,
      60, 52, 44, 36, 28, 20, 12, 4,
      62, 54, 46, 38, 30, 22, 14, 6,
      64, 56, 48, 40, 32, 24, 16, 8,
      57, 49, 41, 33, 25, 17, 9, 1,
      59, 51, 43, 35, 27, 19, 11, 3,
      61, 53, 45, 37, 29, 21, 13, 5,
      63, 55, 47, 39, 31, 23, 15, 7
    };
    
    /**
     * @property {Array<int>} expandingDataFrom32to48 - The permutation data for expanding the data from 32 bits to 48 bits
     */
    int expandingDataFrom32to48[48] = {
      32, 1 , 2 , 3 , 4 , 5 , 4 , 5,
      6 , 7 , 8 , 9 , 8 , 9 , 10, 11,
      12, 13, 12, 13, 14, 15, 16, 17,
      16, 17, 18, 19, 20, 21, 20, 21,
      22, 23, 24, 25, 24, 25, 26, 27,
      28, 29, 28, 29, 30, 31, 32, 1 
    };
    
    /**
     * @property {Array<int>} shrinkingDataFrom48to32 - The permutation data for shrinking the data from 48 bits to 32 bits
     */
    int shrinkingDataFrom48to32[32] = { 
      16, 7, 20, 21,
      29, 12, 28, 17,
      1, 15, 23, 26,
      5, 18, 31, 10,
      2, 8, 24, 14,
      32, 27, 3, 9,
      19, 13, 30, 6,
      22, 11, 4, 25 
    };
    
    /**
     * @property {Array<Array<Array<int>>>} substituionBox - Substituion Box Table to change the data from one to the other
     */
    int substituionBox[8][4][16] = {
      {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
      { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
      { 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
      {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }},
        
      {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
      {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
      {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
      {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }},
    
      {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
      {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
      {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
      {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }},
      
      {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
      {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
      {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
      {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14} },
      
      {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
      {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
      {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
      {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }},
      
      {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
      {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
      {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
      {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13} },
      
      {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
      {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
      {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
      {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12} },
      
      {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
      {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
      {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
      {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} } 
    };
    
    /**
     * @property {Array<int>} finalPermutation - the table of how the 64 bits are mangled in the end of the conversion
     */
    int finalPermutation[64] = {
      40, 8, 48, 16, 56, 24, 64, 32,
      39, 7, 47, 15, 55, 23, 63, 31,
      38, 6, 46, 14, 54, 22, 62, 30,
      37, 5, 45, 13, 53, 21, 61, 29,
      36, 4, 44, 12, 52, 20, 60, 28,
      35, 3, 43, 11, 51, 19, 59, 27,
      34, 2, 42, 10, 50, 18, 58, 26,
      33, 1, 41, 9, 49, 17, 57, 25 
    };
    
    /**
     * @method binaryToHex - converts binary text to hexadecimal text
     * @param {std::string} binaryString - the binary input
     * @returns {std::string} hexadecimalString - the hexadecimal output
     */
    std::string binaryToHex(std::string binaryString);
    
    /**
     * @method hexToBinary - converts hexadecimal text to binary text
     * @param {std::string} hexadecimalString - the hexadecimal input
     * @returns {std::string} binaryString - the binary output
     */
    std::string hexToBinary(std::string hexadecimalString);
    
    /**
     * @method applyRound - since there are many rounds to DES this does an individual round
     * @param {std::string} inputedBinaryData - the inputed data in binary form
     * @param {std::string} key - the key for the code
     * @param {int} currentRound - the current round
     * @returns {std::string} encryptedData - the encrypted data
     */
    std::string applyRound(std::string inputedBinaryData, std::string key, int currentRound);
    
    /**
     * @method applySubstitutionBox - converts the inputed data based on the substituionBox array
     * @param {std::string} binaryInput - this is the 48 bit data input to get the coresponding correct value
     * @returns {std::string} binaryOutput - this is the 48 bit data that has been mangled
     */
    std::string applySubstitutionBox(std::string binaryInput);
    
    /**
     * @method shiftKeyWith - changes the key based on the spacing needed
     * @param {std::string} key - the key
     * @param {int} spacing - the amount that needs to move
     * @returns {std::string} returnKey - the fixed key with the correct placement
     */
    std::string shiftKeyWith(std::string key, int spacing);
    
    /**
     * @method generateModifiedKeys - creates a huge list of all the modified keys in the rounds
     * @param {std::string} key - the first key that needs to be added in hexadecimal
     * @returns {Array<std::string>} keys - the second key that needs to be added as binary
     */
    std::string* generateModifiedKeys(std::string key);
    
    /**
     * @method xorStringAddition - combines two binary strings together in the xor format (1 + 1 == 0, 0 + 0 == 0, 1 + 0 = 1)
     * @param {std::string} a - the first hexadecimal value
     * @param {std::string} b - the second hexadecimal value to be added
     * @returns {std::string} result - the end result
     */
    std::string xorStringAddition(std::string a, std::string b);
    
    /**
     * @method permutate - this is the function used to rearange data
     * @param {std::string} binInput - the binary byte form of the inputed data
     * @param {int[]} rules - the table used for the function to know how to rearange the data
     * @param {int} length - the size of the return data
     * @returns {std::string} binOutput - the binary byte form of the outputed data
     */
    std::string permutate(std::string binInput, int rules[], int length);
    
    /**
     * @method reverse - this reverses an array
     * @param {std::string} inputedArray - the inputed data
     * @param {int} start - this is the starting point
     * @param {int} end - this is the ending point
     */
    std::string* reverse(std::string* inputedArray, int start, int end);
    
    /**
     * @method encrypt - this encrypts the data using 3 keys
     * @param {std::string} inputedText - the inputed data from the user
     * @param {Array<std::string>} keys - the 3 symmetric keys that is used to encrypt/decrypt
     * @returns {std::string} outputedText - the outputed data (hexadecimal)
     */
    std::string encrypt(std::string inputedText, std::string* keys);
    
    /**
     * @method decrypt - this decrypts the data using 3 keys
     * @param {std::string} inputedText - the inputed data from the user
     * @param {Array<std::string>} keys - the 3 symmetric keys that is used to encrypt/decrypt
     * @returns {std::string} outputedText - the outputed data (hexadecimal)
     */
    std::string decrypt(std::string inputedText, std::string* keys);
    
    /**
     * @method singleEncrypt - this encrypts the data
     * @param {std::string} inputedText - the inputed data (hexadecimal)
     * @param {std::string} key - the key used to get the information
     * @returns {std::string} outputedText - the outputed data (hexadecimal)
     */
    std::string singleEncrypt(std::string inputedText, std::string key);
    
    /**
     * @method singleDecrypt - this decrypts the data
     * @param {std::string} inputedText - the inputed data
     * @param {std::string} key - the key used to get the information
     * @returns {std::string} outputedText - the outputed data
     */
    std::string singleDecrypt(std::string inputedText, std::string key);
    
};
