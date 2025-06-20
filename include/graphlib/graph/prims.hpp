#pragma once
#define ll long long
#include <vector>
#include <queue>
#include <utility>

namespace graphlib {

inline ll prim(int n, const std::vector<std::vector<std::pair<int, ll>>>& adj) {
    std::vector<bool> vis(n, false);
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
    pq.push({0, 0});
    ll total_weight = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        total_weight += w;
        for (auto [v, weight] : adj[u])
            if (!vis[v]) pq.push({weight, v});
    }

    return total_weight;
}

}
