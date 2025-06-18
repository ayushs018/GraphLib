#define ll long long

#include "graphlib/graph/dijkstra.hpp"
#include <queue>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

namespace graphlib {

Dijkstra::Dijkstra(const Graph& g) : graph(g), dist(g.n, LLONG_MAX) {}

void Dijkstra::run(ll source) {
    dist.assign(graph.n, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& edge : graph.adj[u]) {
            if (dist[edge.to] > dist[u] + edge.weight) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}

const vector<ll>& Dijkstra::distances_from_source() const {
    return dist;
}

}
