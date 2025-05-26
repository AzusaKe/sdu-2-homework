//
// Created by Azusa_Ke on 25-5-26.
//

#ifndef DUAL_STREAMBUF_H
#define DUAL_STREAMBUF_H

#include <streambuf>
#include <ostream>
#include <fstream>

class dual_streambuf : public std::streambuf {
    std::streambuf* buf1;
    std::streambuf* buf2;
public:
    dual_streambuf(std::streambuf* b1, std::streambuf* b2) : buf1(b1), buf2(b2) {}
protected:
    int overflow(int c) override {
        if (c == EOF) return !EOF;
        if (buf1) buf1->sputc(c);
        if (buf2) buf2->sputc(c);
        return c;
    }
    int sync() override {
        if (buf1) buf1->pubsync();
        if (buf2) buf2->pubsync();
        return 0;
    }
};

#endif //DUAL_STREAMBUF_H
