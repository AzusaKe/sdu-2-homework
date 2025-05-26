//
// Created by Azusa_Ke on 25-5-26.
//
#pragma once

#ifndef LOG_H
#define LOG_H

#pragma once
#include <ostream>

namespace azusa_log {
    extern std::ostream* log;
    void init_log();
}

extern bool is_graphic;

#endif //LOG_H
