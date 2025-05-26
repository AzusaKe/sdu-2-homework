//
// Created by Azusa_Ke on 25-5-26.
//

#include "log.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace azusa_log {
    static std::ofstream log_file;
    std::ostream* log = &std::cout;

    class dual_streambuf : public std::streambuf {
        std::streambuf* sb1;
        std::streambuf* sb2;
    public:
        dual_streambuf(std::streambuf* s1, std::streambuf* s2) : sb1(s1), sb2(s2) {}
    protected:
        int overflow(int c) override {
            if (c == EOF) return !EOF;
            if (sb1) sb1->sputc(c);
            if (sb2) sb2->sputc(c);
            return c;
        }
        int sync() override {
            int r1 = sb1 ? sb1->pubsync() : 0;
            int r2 = sb2 ? sb2->pubsync() : 0;
            return r1 == 0 && r2 == 0 ? 0 : -1;
        }
    };

    static dual_streambuf* dual_buf = nullptr;
    static std::ostream* dual_stream = nullptr;

    void init_log() {
        std::filesystem::create_directories("log");
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm tm;
#ifdef _WIN32
        localtime_s(&tm, &t);
#else
        localtime_r(&t, &tm);
#endif
        std::ostringstream oss;
        oss << "log/"
            << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S")
            << ".log";
        log_file.open(oss.str(), std::ios::out | std::ios::app);

        if (is_graphic && log_file.is_open()) {
            dual_buf = new dual_streambuf(log_file.rdbuf(), std::cout.rdbuf());
            dual_stream = new std::ostream(dual_buf);
            log = dual_stream;
        } else if (log_file.is_open()) {
            log = &log_file;
        } else {
            log = &std::cout;
        }
        *azusa_log::log << "日志初始化成功..." << oss.str() << std::endl;
    }
}
