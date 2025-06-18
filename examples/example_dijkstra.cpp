#define ll long long
#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/dijkstra.hpp"
using namespace std;
using namespace graphlib;

int main() {
    Graph g(5);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 7);
    g.add_edge(2, 4, 3);
    g.add_edge(3, 4, 1);

    Dijkstra dijk(g);
    dijk.run(0);

    const auto& dist = dijk.distances_from_source();
    for (ll i = 0; i < dist.size(); ++i) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
