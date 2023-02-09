#ifndef BLOCK_H
#define BLOCK_H
#include<vector>
#include<iostream>
#include<openssl/sha.h>
#include<consensus.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

class Block
{
public:
    Consensus cns;
    struct{
        uint256_t nonce;
        vector<unsigned char> blockHash; // hash of our block, which represents the sha256(nonce + data)
        vector<unsigned char> data; // our block data(an array of char)
    } blockData;
    Block(vector<unsigned char> data, Consensus &cns_);
    void findNonce();
    void Hash();
    bool verify();
};

#endif // BLOCK_H
