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

// 日志记录模块
// 该模块负责初始化日志记录系统，并提供一个全局的日志输出流
// 日志将同时输出到控制台和一个文件中（如果是图形化界面），
// 文件名格式为 "log/YYYY-MM-DD_HH-MM-SS.log"
// 具有双缓冲功能，允许同时输出到多个流（如控制台和文件）
// 支持跨平台的时间格式化和文件操作

// 使用新的命名空间 azusa_log，避免与其他模块冲突
namespace azusa_log {
    // 新建输入输出流对象
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

        // 检测是否为图形化界面，文件是否打开
        if (is_graphic && log_file.is_open()) {
            dual_buf = new dual_streambuf(log_file.rdbuf(), std::cout.rdbuf());
            dual_stream = new std::ostream(dual_buf);
            log = dual_stream;
        } else if (log_file.is_open()) {
            log = &log_file;
        } else {
            log = &std::cout;
        }
        *log << "日志初始化成功..." << oss.str() << std::endl;
    }
}
