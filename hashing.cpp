#include "hashing.h"

Hashing::Hashing()
{


}

void Hashing::sha256(const vector<unsigned char> toHash, unsigned char* data){
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, toHash.cbegin(), toHash.size());
    SHA256_Final(data, &sha256);
}

unsigned int Hashing::hexToInt(string hexValue){
    unsigned int intValue;
    stringstream ss;
    ss << hexValue;
    ss >> intValue;
    return intValue;
}

vector<unsigned char> Hashing::UintToBytes(uint256_t number){
    stringstream ss;
    ss << hex << number;
    stringstream hexarray;
    string hexValue = ss.str();
    for(int i = 0; i < hexValue.size(); i+= 2){
        string pad;
        hexarray << pad <<  hexValue[i] << hexValue[i + 1];
        if(i + 1 <= hexValue.size()){
            hexarray << " ";
        }
    }
    vector<unsigned char> byte_array;
    int nValue;
    while(hexarray >> hex >> nValue){
        byte_array.push_back(nValue);
    }
    return byte_array;
}

uint256_t Hashing::bytesToUint(vector<unsigned char> byte_array){
    stringstream hexValue;
    for(int i = 0; i < byte_array.size(); i++){
        hexValue <<  hex << setw(2) << setfill('0') << (int)byte_array.at(i);
    }
    uint256_t number;
    hexValue >> number;
    return number;
}
