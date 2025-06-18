#include "graphlib/ds/union_find.hpp"
#include <iostream>
using namespace std;
using namespace graphlib;

int main() {
    int n = 6;
    UnionFind uf(n);

    uf.union_sets(0, 1);
    uf.union_sets(1, 2);
    uf.union_sets(3, 4);

    cout << "Are 0 and 2 in the same set? " << (uf.same_set(0, 2) ? "Yes" : "No") << "\n";
    cout << "Are 2 and 4 in the same set? " << (uf.same_set(2, 4) ? "Yes" : "No") << "\n";

    uf.union_sets(2, 4);
    cout << "After union(2, 4), are 0 and 4 in the same set? " << (uf.same_set(0, 4) ? "Yes" : "No") << "\n";

    cout << "Size of set containing 0: " << uf.get_size(0) << "\n";
    cout << "Parent of 0:" << uf.find(0) << "\n" ; 

    return 0;
}
