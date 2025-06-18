#pragma once
#include <chrono>
#include <iostream>
#include <string>

namespace graphlib {
    namespace utils {

    class Timer {
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        std::string label;

    public:
        Timer(const std::string& lbl = "Timer") : label(lbl) {
            start_time = std::chrono::high_resolution_clock::now();
        }

        ~Timer() {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            std::cout << label << " took " << ms << " ms.\n";
        }
    };

    }  
}  