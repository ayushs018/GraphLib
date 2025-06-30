#pragma once
#define ll long long

#include <vector>
#include <functional>
#include "graphlib/ds/segment_tree.hpp"
namespace graphlib{
class HLD {
public:
    HLD(int n);
    void add_edge(int u, int v);
    void build(int root, const std::vector<ll>& node_values,
               std::function<ll(ll, ll)> merge, ll neutral);
    ll query_path(int u, int v);
    void update_node(int u, ll val);

private:
    int n;
    int current_pos;

    std::vector<std::vector<int>> adj;
    std::vector<int> parent, depth, heavy, head, pos, size;
    std::vector<ll> base_array;

    graphlib::SegmentTree<ll>* segtree;
    std::function<ll(ll, ll)> merge_fn;
    ll neutral_element;

    int dfs(int v, int p);
    void decompose(int v, int h);
};
}