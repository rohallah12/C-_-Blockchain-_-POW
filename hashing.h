#ifndef HASHING_H
#define HASHING_H
#include<openssl/sha.h>
#include<string.h>
#include<sstream>
#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/lexical_cast.hpp>
#include<vector>

using namespace boost::multiprecision;
using namespace std;

class Hashing
{
public:
    Hashing();
    void sha256(const string str, unsigned char* data);
    unsigned int hexToInt(string hexValue);
    vector<unsigned char> UintToBytes(uint256_t number);
    uint256_t bytesToUint(vector<unsigned char> byte_array);
};

#endif // HASHING_H
