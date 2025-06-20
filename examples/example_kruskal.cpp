#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/kruskal.hpp"

using namespace std;
using namespace graphlib;

int main() {
    Graph g(4);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 3);

    vector<Edge> edges;
    for (int u = 0; u < g.n; ++u)
        for (auto e : g.adj[u])
            if (u < e.to) // avoid duplicate edges
                edges.push_back(e);

    ll mst_weight = kruskal(g.n, edges);
    cout << "Kruskal's MST total weight: " << mst_weight << "\n";  // Expected: 6
    return 0;
}
