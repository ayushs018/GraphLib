#pragma once
#define ll long long
#include <vector>
#include <limits>
#include "base.hpp"

namespace graphlib {

const ll INF = 1e18;

inline bool bellman_ford(int n, int src, const std::vector<Edge>& edges, std::vector<ll>& dist) {
    dist.assign(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (auto& e : edges)
            if (dist[e.from] < INF)
                dist[e.to] = std::min(dist[e.to], dist[e.from] + e.weight);

    for (auto& e : edges)
        if (dist[e.from] < INF && dist[e.from] + e.weight < dist[e.to])
            return false; // negative cycle
    return true;
}

}
