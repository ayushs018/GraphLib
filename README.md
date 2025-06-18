# Graph Algorithms

| Functionality                          | File                       | Description                                          | Time Complexity            | Function Name(s)                                                |
| -------------------------------------- | -------------------------- | ---------------------------------------------------- | -------------------------- | --------------------------------------------------------------- |
| Graph Base                             | graph/base.hpp             | Adds undirected/directed edges                       | O(1) per edge              | `add_edge`, `add_directed_edge`                                 |
| DFS                                    | graph/dfs.hpp              | Depth-first search traversal                         | O(V + E)                   | `dfs`, `get_visited`                                            |
| BFS                                    | graph/bfs.hpp              | Breadth-first search traversal                       | O(V + E)                   | `bfs`                                                           |
| Dijkstra’s Algorithm                   | graph/dijkstra.hpp         | Single-source shortest path for non-negative weights | O((V + E) log V)           | `dijkstra`                                                      |
| Heavy-Light Decomposition (HLD)        | graph/hld.hpp              | Path queries/updates on trees using segment trees    | O(log² N) per query/update | `add_edge`, `dfs_hld`, `decompose`, `query_path`, `update_path` |
| Strongly Connected Components (Tarjan) | graph/scc\_tarjan.hpp      | Finds SCCs in directed graph                         | O(V + E)                   | `SCC::run`, `SCC::get_scc`                                      |
| Gomory-Hu Tree (Min-Cut)               | graph/mincut\_gomoryhu.hpp | All-pairs min-cut using flow                         | O(V × Max Flow)            | `build_gomory_hu_tree`                                          |



# Data Structures

| Functionality    | File                   | Description                                          | Time Complexity        | Function Name(s)                                               |
| ---------------- | ---------------------- | ---------------------------------------------------- | ---------------------- | -------------------------------------------------------------- |
| Segment Tree     | ds/segment\_tree.hpp   | Range queries and point updates                      | O(log N)               | `SegmentTree`, `update`, `query`                               |
| Union-Find (DSU) | ds/union\_find.hpp     | Disjoint set with union by rank and path compression | O(α(N)) amortized      | `UnionFind`, `find`, `unite`, `connected`                      |
| Trie             | ds/trie.hpp            | Supports both bitwise and string keys                | O(L) where L is length | `insert_string`, `search_string`, `insert_bits`, `search_bits` |
| Binary Lifting   | ds/binary\_lifting.hpp | Fast ancestor queries and LCA in trees               | O(log N) per query     | `add_edge`, `preprocess`, `get_kth_ancestor`, `lca`            |



# Math Utilities

| Functionality              | File                  | Description                                      | Time Complexity           | Function Name(s)          |
| -------------------------- | --------------------- | ------------------------------------------------ | ------------------------- | ------------------------- |
| Binary Exponentiation      | utils/math\_utils.hpp | Computes A^B efficiently                         | O(log B)                  | `binpow`                  |
| Inverse Modulo             | utils/math\_utils.hpp | Computes modular inverse of A under MOD          | O(log MOD)                | `invmod`                  |
| Factorials & Combinatorics | utils/math\_utils.hpp | Precomputed factorial, nCr, nPr                  | O(1) after precomputation | `factorial`, `nCr`, `nPr` |
| Fibonacci (Nth Term)       | utils/math\_utils.hpp | Computes nth Fibonacci number                    | O(log N)                  | `fib`                     |
| Matrix Exponentiation      | utils/math\_utils.hpp | Raises a matrix to power                         | O(K³ log N)               | `matrix_pow`              |
| Smallest Prime Factor      | utils/math\_utils.hpp | Precomputes smallest prime factor and factorizes | O(N log log N)            | `init_spf`, `get_factors` |
