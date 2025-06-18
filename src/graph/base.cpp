#include "graphlib/graph/base.hpp"
using namespace std;

namespace graphlib {

    void Graph::add_edge(ll u, ll v, ll w) {
        adj[u].push_back(Edge(u, v, w));
    }

}
