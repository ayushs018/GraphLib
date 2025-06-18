#include "graphlib/utils/logger.hpp"
#include "graphlib/utils/timer.hpp"
using namespace graphlib::utils;

int main() {
    LOG("Starting heavy computation");

    {
        Timer t("Computation Block");
        long long sum = 0;
        for (int i = 0; i < 1e8; i++) sum += i;
        LOG("Finished computing sum");
    }

    return 0;
}
