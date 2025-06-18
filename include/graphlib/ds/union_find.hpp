#pragma once
#define ll long long
#include <vector>
using namespace std;

namespace graphlib {

class UnionFind {
private:
    vector<int> parent, size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    bool union_sets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }

    int get_size(int u) {
        return size[find(u)];
    }

    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};

} 
