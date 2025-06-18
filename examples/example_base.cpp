#include <iostream>
#include "graphlib/graph/base.hpp"
using namespace std;
using namespace graphlib;

int main() {
    Graph g(4);  
    g.add_edge(0, 1);
    g.add_edge(1, 2, 5);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 0, 4);

    cout << "Graph edges:\n";
    for (int u = 0; u < g.n; ++u) {
        for (const auto& e : g.adj[u]) {
            cout << e.from << " -> " << e.to << " (w=" << e.weight << ")\n";
        }
    }

    return 0;
}
