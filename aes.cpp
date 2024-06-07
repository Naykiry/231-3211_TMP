#include "aes.h"
#include <array>
#include <iostream>

const uint8_t AES::sbox[256] = {
    // S-box
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
    // (добавьте оставшиеся значения)
};

const uint8_t AES::rsbox[256] = {
    // Inverse S-box
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38,
    // (добавьте оставшиеся значения)
};

const uint8_t AES::Rcon[11] = {
    // Rcon
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

AES::AES(const std::vector<uint8_t>& key) : key(key), Nr(10), Nk(4) {
    roundKey.resize(176);
    KeyExpansion();
}

void AES::KeyExpansion() {
    // Реализация Key Expansion
    uint32_t i = 0;
    uint8_t temp[4];

    while (i < Nk * 4) {
        roundKey[i] = key[i];
        ++i;
    }

    i = Nk * 4;
    while (i < 176) {
        for (uint8_t j = 0; j < 4; ++j) {
            temp[j] = roundKey[(i - 4) + j];
        }

        if (i / 4 % Nk == 0) {
            uint8_t t = temp[0];
            temp[0] = sbox[temp[1]] ^ Rcon[i / 4 / Nk];
            temp[1] = sbox[temp[2]];
            temp[2] = sbox[temp[3]];
            temp[3] = sbox[t];
        }

        for (uint8_t j = 0; j < 4; ++j) {
            roundKey[i + j] = roundKey[i + j - Nk * 4] ^ temp[j];
        }

        i += 4;
    }
}

void AES::AddRoundKey(uint8_t round) {
    for (uint8_t i = 0; i < 16; ++i) {
        state[i] ^= roundKey[round * 16 + i];
    }
}

void AES::SubBytes() {
    for (uint8_t i = 0; i < 16; ++i) {
        state[i] = sbox[state[i]];
    }
}

void AES::InvSubBytes() {
    for (uint8_t i = 0; i < 16; ++i) {
        state[i] = rsbox[state[i]];
    }
}

void AES::ShiftRows() {
    std::vector<uint8_t> temp(16);
    temp[0] = state[0];
    temp[1] = state[5];
    temp[2] = state[10];
    temp[3] = state[15];
    temp[4] = state[4];
    temp[5] = state[9];
    temp[6] = state[14];
    temp[7] = state[3];
    temp[8] = state[8];
    temp[9] = state[13];
    temp[10] = state[2];
    temp[11] = state[7];
    temp[12] = state[12];
    temp[13] = state[1];
    temp[14] = state[6];
    temp[15] = state[11];
    state = temp;
}

void AES::InvShiftRows() {
    std::vector<uint8_t> temp(16);
    temp[0] = state[0];
    temp[1] = state[13];
    temp[2] = state[10];
    temp[3] = state[7];
    temp[4] = state[4];
    temp[5] = state[1];
    temp[6] = state[14];
    temp[7] = state[11];
    temp[8] = state[8];
    temp[9] = state[5];
    temp[10] = state[2];
    temp[11] = state[15];
    temp[12] = state[12];
    temp[13] = state[9];
    temp[14] = state[6];
    temp[15] = state[3];
    state = temp;
}

void AES::MixColumns() {
    for (uint8_t i = 0; i < 4; ++i) {
        uint8_t a = state[i * 4];
        uint8_t b = state[i * 4 + 1];
        uint8_t c = state[i * 4 + 2];
        uint8_t d = state[i * 4 + 3];

        state[i * 4] = (uint8_t) (a * 2 ^ ((b * 2) ^ (b ^ c) ^ d));
        state[i * 4 + 1] = (uint8_t) (b * 2 ^ ((c * 2) ^ (c ^ d) ^ a));
        state[i * 4 + 2] = (uint8_t) (c * 2 ^ ((d * 2) ^ (d ^ a) ^ b));
        state[i * 4 + 3] = (uint8_t) (d * 2 ^ ((a * 2) ^ (a ^ b) ^ c));
    }
}

void AES::InvMixColumns() {
    for (uint8_t i = 0; i < 4; ++i) {
        uint8_t a = state[i * 4];
        uint8_t b = state[i * 4 + 1];
        uint8_t c = state[i * 4 + 2];
        uint8_t d = state[i * 4 + 3];

        state[i * 4] = (uint8_t) (a * 14 ^ b * 11 ^ c * 13 ^ d * 9);
        state[i * 4 + 1] = (uint8_t) (a * 9 ^ b * 14 ^ c * 11 ^ d * 13);
        state[i * 4 + 2] = (uint8_t) (a * 13 ^ b * 9 ^ c * 14 ^ d * 11);
        state[i * 4 + 3] = (uint8_t) (a * 11 ^ b * 13 ^ c * 9 ^ d * 14);
    }
}

void AES::Cipher() {
    AddRoundKey(0);

    for (uint8_t round = 1; round < Nr; ++round) {
        SubBytes();
        ShiftRows();
        MixColumns();
        AddRoundKey(round);
    }

    SubBytes();
    ShiftRows();
    AddRoundKey(Nr);
}

void AES::InvCipher() {
    AddRoundKey(Nr);

    for (uint8_t round = Nr - 1; round > 0; --round) {
        InvShiftRows();
        InvSubBytes();
        AddRoundKey(round);
        InvMixColumns();
    }

    InvShiftRows();
    InvSubBytes();
    AddRoundKey(0);
}

std::vector<uint8_t> AES::Encrypt(const std::vector<uint8_t>& input) {
    state = input;
    Cipher();
    return state;
}

std::vector<uint8_t> AES::Decrypt(const std::vector<uint8_t>& input) {
    state = input;
    InvCipher();
    return state;
}
