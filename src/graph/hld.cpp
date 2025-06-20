#define ll long long

#include "graphlib/graph/hld.hpp"

using namespace std;
using namespace graphlib;

HLD::HLD(int n) : n(n), current_pos(0) {
    adj.resize(n);
    parent.resize(n);
    depth.resize(n);
    heavy.assign(n, -1);
    head.resize(n);
    pos.resize(n);
    size.resize(n);
}

void HLD::add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int HLD::dfs(int v, int p) {
    parent[v] = p;
    size[v] = 1;
    int max_size = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        int sz = dfs(u, v);
        size[v] += sz;
        if (sz > max_size) {
            max_size = sz;
            heavy[v] = u;
        }
    }
    return size[v];
}

void HLD::decompose(int v, int h) {
    head[v] = h;
    pos[v] = current_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (int u : adj[v]) {
        if (u != parent[v] && u != heavy[v])
            decompose(u, u);
    }
}

void HLD::build(int root, const vector<ll>& node_values,
                function<ll(ll, ll)> merge, ll neutral) {
    merge_fn = merge;
    neutral_element = neutral;
    dfs(root, -1);
    decompose(root, root);
    base_array.resize(n);
    for (int i = 0; i < n; ++i)
        base_array[pos[i]] = node_values[i];
    segtree = new SegmentTree<ll>(base_array, merge_fn, neutral_element);
}

ll HLD::query_path(int u, int v) {
    ll res = neutral_element;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        res = merge_fn(res, segtree->query(pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    res = merge_fn(res, segtree->query(pos[u], pos[v]));
    return res;
}

void HLD::update_node(int u, ll val) {
    segtree->update(pos[u], val);
}
