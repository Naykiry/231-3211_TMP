#ifndef AES_H
#define AES_H

#include <cstdint>
#include <vector>

class AES {
public:
    AES(const std::vector<uint8_t>& key);
    std::vector<uint8_t> Encrypt(const std::vector<uint8_t>& input);
    std::vector<uint8_t> Decrypt(const std::vector<uint8_t>& input);

private:
    void KeyExpansion();
    void AddRoundKey(uint8_t round);
    void SubBytes();
    void InvSubBytes();
    void ShiftRows();
    void InvShiftRows();
    void MixColumns();
    void InvMixColumns();
    void Cipher();
    void InvCipher();

    std::vector<uint8_t> state;
    std::vector<uint8_t> roundKey;
    std::vector<uint8_t> key;
    uint8_t Nr;  // Number of rounds
    uint8_t Nk;  // Key length in 32-bit words

    static const uint8_t sbox[256];
    static const uint8_t rsbox[256];
    static const uint8_t Rcon[11];
};

#endif // AES_H
