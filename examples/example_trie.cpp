#include "graphlib/ds/trie.hpp"
#include <iostream>
using namespace std;
using namespace graphlib;

int main() {
    // STRING TRIE TEST
    StringTrie st;
    st.insert("apple");
    st.insert("app");
    cout << "Search 'apple': " << st.search("apple") << "\n"; // 1
    cout << "Starts with 'app': " << st.starts_with("app") << "\n"; // 1
    st.erase("apple");
    cout << "Search 'apple' after erase: " << st.search("apple") << "\n"; // 0

    // BIT TRIE TEST
    BitTrie bt;
    bt.insert(10);  // 1010
    bt.insert(5);   // 0101
    cout << "Max XOR with 6 (0110): " << bt.get_max_xor(6) << "\n"; //  10 ^ 6 = 12
    cout << "Min XOR with 6 (0110): " << bt.get_min_xor(6) << "\n"; //  5 ^ 6 = 3
    bt.erase(10);
    cout << "Max XOR with 6 after erasing 10: " << bt.get_max_xor(6) << "\n"; //  5

    return 0;
}
