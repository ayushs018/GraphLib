#pragma once
#define ll long long

#include "graphlib/graph/base.hpp"
#include <vector>

using namespace std;

namespace graphlib {

    class Dijkstra {
    public:
        Dijkstra(const Graph& g);
        void run(ll source);
        const vector<ll>& distances_from_source() const;

    private:
        const Graph& graph;
        vector<ll> dist;
    };

}
