#include <iostream>
#include "graphlib/string/prefix_function.hpp"
using namespace std;
using namespace graphlib;

int main() {
    string s = "ababcabab";
    PrefixFunction pf;
    vector<int> pi = pf.compute(s);
    for (int i : pi) cout << i << " ";
    cout << endl;
    return 0;
}
