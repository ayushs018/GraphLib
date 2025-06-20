#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/prims.hpp"

using namespace std;
using namespace graphlib;

int main() {
    Graph g(4);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 6);
    g.add_edge(2, 3, 3);

    vector<vector<pair<int, ll>>> adj(g.n);
    for (int u = 0; u < g.n; ++u)
        for (auto e : g.adj[u])
            adj[u].push_back({e.to, e.weight});

    ll mst_weight = prim(g.n, adj);
    cout << "Prim's MST total weight: " << mst_weight << "\n";  // Expected: 6
    return 0;
}
