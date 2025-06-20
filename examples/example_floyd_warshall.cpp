#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/floyd_warshall.hpp"

using namespace std;
using namespace graphlib;

int main() {
    Graph g(4);
    g.add_edge(0, 1, 5);
    g.add_edge(1, 2, 3);
    g.add_edge(0, 3, 10);
    g.add_edge(3, 2, 1);

    vector<vector<ll>> dist(g.n, vector<ll>(g.n, INF));
    for (int i = 0; i < g.n; ++i) dist[i][i] = 0;

    for (int u = 0; u < g.n; ++u)
        for (auto e : g.adj[u])
            dist[u][e.to] = min(dist[u][e.to], e.weight);

    floyd_warshall(dist);

    cout << "Shortest distance from 0 to 2: " << dist[0][2] << "\n";  // Expected: 8
    return 0;
}
