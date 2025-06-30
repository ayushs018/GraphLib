#pragma once
#include <vector>
#include <string>
using namespace std;

namespace graphlib {

class PrefixFunction {
public:
    vector<int> compute(const string& s) {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
};

}
