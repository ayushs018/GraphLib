#include "graphlib/ds/segment_tree.hpp"
#include <iostream>
using namespace std;
using namespace graphlib;

int main() {
    vector<ll> data = {1, 3, 5, 7, 9, 11};
    auto mergeFn = [](ll a, ll b) { return a + b; };
    SegmentTree<ll> seg(data, mergeFn, 0LL);
    cout << "Sum of range [1, 3]: " << seg.query(1, 3) << "\n"; // 3 + 5 + 7 = 15
    seg.update(1, 10);  // change 3 -> 10
    cout << "Sum of range [1, 3] after update: " << seg.query(1, 3) << "\n"; // 10 + 5 + 7 = 22

    return 0;
}
