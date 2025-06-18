#pragma once
#define ll long long
#include <vector>
#include <functional>
using namespace std;

namespace graphlib {

template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    function<T(T, T)> merge;
    T identity;

    void build(const vector<T>& data, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = data[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(data, 2*v, tl, tm);
            build(data, 2*v+1, tm+1, tr);
            tree[v] = merge(tree[2*v], tree[2*v+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2*v, tl, tm, pos, val);
            else
                update(2*v+1, tm+1, tr, pos, val);
            tree[v] = merge(tree[2*v], tree[2*v+1]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return identity;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return merge(
            query(2*v, tl, tm, l, min(r, tm)),
            query(2*v+1, tm+1, tr, max(l, tm+1), r)
        );
    }

public:
    SegmentTree(const vector<T>& data, function<T(T, T)> mergeFn, T id)
        : merge(mergeFn), identity(id) {
        n = data.size();
        tree.assign(4 * n, identity);
        build(data, 1, 0, n - 1);
    }

    void update(int pos, T val) {
        update(1, 0, n - 1, pos, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

} // namespace graphlib
