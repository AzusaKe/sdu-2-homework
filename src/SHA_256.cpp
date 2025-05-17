// sha256.cpp
#include "SHA_256.h"

// SHA-256 常量
const uint32_t SHA256::k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// 初始哈希值
const uint32_t SHA256::h0[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// 右旋转操作
uint32_t SHA256::right_rotate(uint32_t value, unsigned int count) {
    return (value >> count) | (value << (32 - count));
}

// 处理一个 512 位块
void SHA256::process_block(const std::vector<uint8_t>& block, uint32_t hash[8]) {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = (block[i * 4] << 24) | (block[i * 4 + 1] << 16) | (block[i * 4 + 2] << 8) | block[i * 4 + 3];
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = right_rotate(w[i - 15], 7) ^ right_rotate(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = right_rotate(w[i - 2], 17) ^ right_rotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3],
             e = hash[4], f = hash[5], g = hash[6], h = hash[7];

    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + k[i] + w[i];
        uint32_t S0 = right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
}

// 预处理输入数据
std::vector<uint8_t> SHA256::preprocess(const std::string& input) {
    std::vector<uint8_t> data(input.begin(), input.end());
    uint64_t original_size = data.size() * 8;
    data.push_back(0x80); // 添加 1 比特（以字节为单位）

    while (data.size() % 64 != 56) {
        data.push_back(0x00); // 填充 0
    }

    // 添加原始长度（大端格式）
    for (int i = 0; i < 8; ++i) {
        data.push_back((original_size >> (56 - i * 8)) & 0xFF);
    }

    return data;
}

// 将哈希值转换为十六进制字符串
std::string SHA256::to_hex_string(const uint32_t hash[8]) {
    std::ostringstream oss;
    for (int i = 0; i < 8; ++i) {
        oss << std::hex << std::setw(8) << std::setfill('0') << hash[i];
    }
    return oss.str();
}

// 公共接口：计算字符串的 SHA-256 哈希值
std::string SHA256::sha_256(const std::string& input) {
    std::vector<uint8_t> data = preprocess(input);
    uint32_t hash[8];
    for (int i = 0; i < 8; ++i) {
        hash[i] = h0[i];
    }

    for (size_t i = 0; i < data.size(); i += 64) {
        process_block(std::vector<uint8_t>(data.begin() + i, data.begin() + i + 64), hash);
    }

    return to_hex_string(hash);
}