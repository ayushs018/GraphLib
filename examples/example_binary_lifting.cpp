#include "graphlib/graph/binary_lifting.hpp"
#include <iostream>
using namespace std;
using namespace graphlib;

int main() {
    int n = 9;
    BinaryLifting bl(n);

    // Tree edges
    bl.add_edge(0, 1);
    bl.add_edge(0, 2);
    bl.add_edge(1, 3);
    bl.add_edge(1, 4);
    bl.add_edge(2, 5);
    bl.add_edge(2, 6);
    bl.add_edge(5, 7);
    bl.add_edge(5, 8);

    bl.build(0);

    cout << "LCA of 4 and 6: " << bl.lca(4, 6) << "\n"; // 0
    cout << "LCA of 7 and 8: " << bl.lca(7, 8) << "\n"; // 5
    cout << "LCA of 3 and 4: " << bl.lca(3, 4) << "\n"; // 1
    cout << "3rd ancestor of 7: " << bl.get_kth_ancestor(7, 3) << "\n"; // 0

    return 0;
}
