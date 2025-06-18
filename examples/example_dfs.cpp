#define ll long long
#include <iostream>
#include "graphlib/graph/base.hpp"
#include "graphlib/graph/dfs.hpp"
using namespace std;
using namespace graphlib;

int main() {
    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(4, 5);

    DFS dfs(g);
    dfs.run(0);

    cout << "Nodes visited from 0: ";
    const auto& visited = dfs.visited_nodes();
    for (ll i = 0; i < visited.size(); ++i) {
        if (visited[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}
