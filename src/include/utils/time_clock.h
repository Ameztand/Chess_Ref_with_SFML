#pragma once

#include <chrono>

class TimeClock {
private:
    std::chrono::steady_clock::time_point start_;
public:
    TimeClock() { reset(); }//包含入场onEnter

    double now() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<double>(now - start_).count();
    }

    void reset() {
        start_ = std::chrono::steady_clock::now();
    }
};