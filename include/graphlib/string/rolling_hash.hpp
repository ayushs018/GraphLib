#pragma once
#include <vector>
#include <string>
using namespace std;

namespace graphlib {

class RollingHash {
    static constexpr long long mod = 1e9 + 7;
    static constexpr long long base = 911;

    vector<long long> hash, power;

public:
    void build(const string& s) {
        int n = s.size();
        hash.resize(n + 1);
        power.resize(n + 1);
        power[0] = 1;
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = (hash[i] * base + s[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    // Hash of s[l...r], 0-based inclusive
    long long get_hash(int l, int r) {
        return (hash[r + 1] - hash[l] * power[r - l + 1] % mod + mod) % mod;
    }
};

}
