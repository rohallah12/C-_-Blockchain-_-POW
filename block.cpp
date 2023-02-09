#include "block.h"
#include <consensus.h>

Block::Block(vector<unsigned char> data, Consensus& cn) : cns(cn)
{
    this->blockData.data = data;
}

void Block::findNonce()
{
    uint256_t target = this->cns.PoW(&(this->blockData.data));
    this->blockData.nonce = target;
}

void Block::Hash(){
    Hashing hasher;
    vector<unsigned char> nonce_data = hasher.UintToBytes(this->blockData.nonce);
    nonce_data.insert(nonce_data.end(), this->blockData.data.begin(), this->blockData.data.end());
    hasher.sha256()
}

bool Block::verify()
{

}

