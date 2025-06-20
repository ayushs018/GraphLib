#pragma once
#define ll long long
#include <vector>
#include <algorithm>
#include "base.hpp"
#include "../ds/union_find.hpp"

namespace graphlib {

inline ll kruskal(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(n);
    ll total_weight = 0;
    for (auto& e : edges) {
        if (uf.union_sets(e.from, e.to))
            total_weight += e.weight;
    }
    return total_weight;
}

}
