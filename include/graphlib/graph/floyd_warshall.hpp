#pragma once
#define ll long long
#include <vector>
#include <algorithm>

namespace graphlib {

const ll INF = 1e18;

inline void floyd_warshall(std::vector<std::vector<ll>>& dist) {
    int n = dist.size();
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
}

}
