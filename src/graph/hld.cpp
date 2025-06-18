#define ll long long

#include "graphlib/graph/hld.hpp"
#include <algorithm>

using namespace std;

namespace graphlib {

HLD::HLD(const Graph& g, ll root) : graph(g), root(root), n(g.n) {
    parent.assign(n, -1);
    depth.assign(n, 0);
    heavy.assign(n, -1);
    head.assign(n, 0);
    pos.assign(n, 0);
    size.assign(n, 0);
    current_pos = 0;

    dfs(root, -1);
    decompose(root, root);
}

ll HLD::dfs(ll u, ll p) {
    size[u] = 1;
    ll max_subtree = 0;
    for (auto& e : graph.adj[u]) {
        ll v = e.to;
        if (v == p) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        ll subtree_size = dfs(v, u);
        size[u] += subtree_size;
        if (subtree_size > max_subtree) {
            max_subtree = subtree_size;
            heavy[u] = v;
        }
    }
    return size[u];
}

void HLD::decompose(ll u, ll h) {
    head[u] = h;
    pos[u] = current_pos++;

    if (heavy[u] != -1)
        decompose(heavy[u], h);

    for (auto& e : graph.adj[u]) {
        ll v = e.to;
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

const vector<ll>& HLD::position() const {
    return pos;
}

const vector<ll>& HLD::head_node() const {
    return head;
}

vector<pair<ll, ll>> HLD::get_path_segments(ll u, ll v) const {
    vector<pair<ll, ll>> segments;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        segments.push_back({pos[head[u]], pos[u]});
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    segments.push_back({pos[u], pos[v]});
    return segments;
}

}
