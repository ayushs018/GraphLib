#pragma once
#define ll long long

#include "graphlib/graph/base.hpp"
#include <vector>
using namespace std;

namespace graphlib {

    class DFS {
        public:
            DFS(const Graph& g);
            void run(ll start);
            const vector<bool>& visited_nodes() const;

        private:
            const Graph& graph;
            vector<bool> visited;
            void dfs(ll u);
    };

}
