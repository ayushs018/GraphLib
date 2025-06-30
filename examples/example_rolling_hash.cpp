#include <iostream>
#include "graphlib/string/rolling_hash.hpp"
using namespace std;
using namespace graphlib;

int main() {
    string s = "abcdefg";
    RollingHash rh;
    rh.build(s);
    cout << "Hash of [1, 3] = " << rh.get_hash(1, 3) << endl;
    cout << "Hash of [2, 4] = " << rh.get_hash(2, 4) << endl;
    return 0;
}
