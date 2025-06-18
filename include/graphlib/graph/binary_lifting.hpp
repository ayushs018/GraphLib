#pragma once
#define ll long long
#include <vector>
#include <cmath>
using namespace std;

namespace graphlib {

class BinaryLifting {
private:
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i <= LOG; ++i)
            up[u][i] = up[up[u][i - 1]][i - 1];
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

public:
    BinaryLifting(int nodes) : n(nodes) {
        LOG = ceil(log2(n));
        up.assign(n, vector<int>(LOG + 1));
        depth.assign(n, 0);
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 0) {
        depth[root] = 0;
        dfs(root, root);
    }

    int get_kth_ancestor(int u, int k) {
        for (int i = 0; i <= LOG; ++i) {
            if (k & (1 << i))
                u = up[u][i];
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        u = get_kth_ancestor(u, diff);
        if (u == v) return u;
        for (int i = LOG; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int get_depth(int u) const {
        return depth[u];
    }
};

} 
