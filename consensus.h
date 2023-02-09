#ifndef CONSENSUS_H
#define CONSENSUS_H
#include<hashing.h>
#include<sstream>
#include<boost/multiprecision/cpp_int.hpp>
#include<vector>

using namespace boost::multiprecision;
using namespace std;


class Consensus
{
public:
    int difficulty;
    uint256_t max_nonce;
    Consensus(int diff);
    uint256_t PoW(vector<unsigned char> *data);
};

#endif // CONSENSUS_H
