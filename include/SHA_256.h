// sha256.h
#ifndef SHA256_H
#define SHA256_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdint>

class SHA256 {
public:
    // 公共接口：计算字符串的 SHA-256 哈希值
    static std::string sha_256(const std::string& input);

private:
    // 内部常量和函数
    static const uint32_t k[64]; // SHA-256 常量
    static const uint32_t h0[8]; // 初始哈希值

    static uint32_t right_rotate(uint32_t value, unsigned int count);
    static void process_block(const std::vector<uint8_t>& block, uint32_t hash[8]);
    static std::vector<uint8_t> preprocess(const std::string& input);
    static std::string to_hex_string(const uint32_t hash[8]);
};

#endif // SHA256_H