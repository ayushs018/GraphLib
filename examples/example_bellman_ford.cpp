#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/bellman_ford.hpp"

using namespace std;
using namespace graphlib;

int main() {
    Graph g(5);
    g.add_edge(0, 1, 6);
    g.add_edge(0, 2, 7);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 3, 5);
    g.add_edge(2, 3, -3);
    g.add_edge(3, 4, 9);

    vector<Edge> edges;
    for (int u = 0; u < g.n; ++u)
        for (auto e : g.adj[u])
            edges.push_back(e);

    vector<ll> dist;
    if (bellman_ford(g.n, 0, edges, dist)) {
        for (int i = 0; i < g.n; ++i)
            cout << "Distance from 0 to " << i << ": " << dist[i] << "\n";
    } else {
        cout << "Negative weight cycle detected.\n";
    }

    return 0;
}
