#include<consensus.h>

Consensus::Consensus(int diff){
    this->difficulty = diff;
    this->max_nonce = 2 << (256 - diff);
}

uint256_t Consensus::PoW(vector<unsigned char> *data){
    Hashing hasher;
    uint256_t nonce;
    uint256_t result;
    vector<unsigned char> nonce_bytes; // convert uint256_t to bytes
    while(true){
        nonce_bytes = hasher.UintToBytes(nonce);
        nonce_bytes.insert(nonce_bytes.end(), data->begin(), data->end()); // append nonce bytes and data bytes together
        result = hasher.bytesToUint(nonce_bytes);
        if(result <= max_nonce){
            break;
        }
        cout << result;
        nonce += 1;
        nonce_bytes.clear();
    }
}
