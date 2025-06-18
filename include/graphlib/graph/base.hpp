#pragma once
#include <vector>
#define ll long long 
using namespace std;

namespace graphlib {

    struct Edge {
        ll from, to, weight;
        Edge(ll u, ll v, ll w = 1) : from(u), to(v), weight(w) {}
    };

    class Graph {
    public:
        ll n;
        vector<vector<Edge>> adj;
        Graph(ll _n) : n(_n), adj(_n) {}
        void add_edge(ll u, ll v, ll w = 1);
    };

}
