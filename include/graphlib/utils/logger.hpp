#pragma once
#include <iostream>
#include <chrono>
#include <string>

#define LOG(msg) graphlib::utils::Logger::log(msg, __FILE__, __LINE__)

namespace graphlib {
    namespace utils {

    class Logger {
    public:
        static void log(const std::string &msg, const char* file, int line) {
            auto now = std::chrono::system_clock::now();
            std::time_t t = std::chrono::system_clock::to_time_t(now);
            std::cout << "[LOG " << std::ctime(&t)
                    << " @ " << file << ":" << line << "] " << msg << std::endl;
        }
    };

    }  
}  
