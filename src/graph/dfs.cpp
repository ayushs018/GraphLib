#define ll long long

#include "graphlib/graph/dfs.hpp"
using namespace std;

namespace graphlib {

DFS::DFS(const Graph& g) : graph(g), visited(g.n, false) {}

void DFS::run(ll start) {
    fill(visited.begin(), visited.end(), false);
    dfs(start);
}

void DFS::dfs(ll u) {
    visited[u] = true;
    for (const auto& edge : graph.adj[u]) {
        if (!visited[edge.to]) {
            dfs(edge.to);
        }
    }
}

const vector<bool>& DFS::visited_nodes() const {
    return visited;
}

}
