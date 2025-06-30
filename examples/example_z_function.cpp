#include <iostream>
#include "graphlib/string/z_function.hpp"
using namespace std;
using namespace graphlib;

int main() {
    string s = "aabcaabxaaaz";
    ZFunction zf;
    vector<int> z = zf.compute(s);
    for (int i : z) cout << i << " ";
    cout << endl;
    return 0;
}
