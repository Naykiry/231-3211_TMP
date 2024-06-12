#ifndef AES_H
#define AES_H

#include <string>
#include <vector>

class AES
{
public:
    AES(const std::string &key);
    std::string encrypt(const std::string &plainText);
    std::string decrypt(const std::string &cipherText);

private:
    std::vector<std::vector<unsigned char>> keySchedule(const std::vector<unsigned char> &key);
    std::vector<unsigned char> addRoundKey(const std::vector<unsigned char> &state, const std::vector<unsigned char> &roundKey);
    std::vector<unsigned char> subBytes(const std::vector<unsigned char> &state);
    std::vector<unsigned char> invSubBytes(const std::vector<unsigned char> &state);
    std::vector<unsigned char> shiftRows(const std::vector<unsigned char> &state);
    std::vector<unsigned char> invShiftRows(const std::vector<unsigned char> &state);
    std::vector<unsigned char> mixColumns(const std::vector<unsigned char> &state);
    std::vector<unsigned char> invMixColumns(const std::vector<unsigned char> &state);

    std::string pad(const std::string &plainText);
    std::string unpad(const std::string &plainText);

    std::string bytesToHex(const std::vector<unsigned char> &bytes);
    std::vector<unsigned char> hexToBytes(const std::string &hex);

    std::vector<unsigned char> m_key;
    std::vector<std::vector<unsigned char>> m_roundKeys;
};

#endif
