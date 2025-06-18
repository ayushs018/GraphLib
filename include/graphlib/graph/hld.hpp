#pragma once
#define ll long long

#include "graphlib/graph/base.hpp"
#include <vector>

using namespace std;

namespace graphlib {

class HLD {
public:
    HLD(const Graph& g, ll root = 0);

    // Returns the index of each node in the segment tree
    const vector<ll>& position() const;

    // Returns the head of the heavy path for each node
    const vector<ll>& head_node() const;

    // Path decomposition from u to v
    vector<pair<ll, ll>> get_path_segments(ll u, ll v) const;

private:
    const Graph& graph;
    ll n, current_pos, root;
    vector<ll> parent, depth, heavy, head, pos, size;

    ll dfs(ll u, ll p);
    void decompose(ll u, ll h);
};

}
