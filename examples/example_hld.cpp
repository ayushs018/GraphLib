#include <iostream>
#include <functional>
#include "graphlib/graph/hld.hpp"
using namespace std;
ll merge_sum(ll a, ll b) {
    return a + b;
}

int main() {
    int n = 9;
    HLD hld(n);

    // Tree structure:
    //       0
    //     / | \
    //    1  2  3
    //   /      \
    //  4        5
    // / \      / \
    //6   7    8   -

    hld.add_edge(0, 1);
    hld.add_edge(0, 2);
    hld.add_edge(0, 3);
    hld.add_edge(1, 4);
    hld.add_edge(4, 6);
    hld.add_edge(4, 7);
    hld.add_edge(3, 5);
    hld.add_edge(5, 8);

    vector<ll> node_values = {5, 3, 7, 2, 4, 6, 1, 9, 8}; // value at each node

    hld.build(0, node_values, merge_sum, 0);  // sum query with 0 neutral

    cout << "Sum from node 6 to 0: " << hld.query_path(6, 0) << "\n"; // expect sum along path 6-4-1-0
    cout << "Sum from node 6 to 7: " << hld.query_path(6, 7) << "\n"; // expect 1+4+9 = 14
    cout << "Sum from node 8 to 2: " << hld.query_path(8, 2) << "\n"; // expect 8+6+3+5+7 = 29

    hld.update_node(4, 10); // update node 4's value from 4 → 10

    cout << "After update, sum from node 6 to 0: " << hld.query_path(6, 0) << "\n"; // should reflect new value at 4

    return 0;
}
