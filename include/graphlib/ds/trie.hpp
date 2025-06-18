#pragma once
#define ll long long
#include <bits/stdc++.h>
using namespace std;

namespace graphlib {

class StringTrieNode {
public:
    bool is_end;
    int count;
    unordered_map<char, StringTrieNode*> next;

    StringTrieNode() {
        is_end = false;
        count = 0;
    }
};

// String Trie //

class StringTrie {
private:
    StringTrieNode* root;

public:
    StringTrie() {
        root = new StringTrieNode();
    }

    void insert(const string& word) {
        auto node = root;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new StringTrieNode();
            }
            node = node->next[ch];
            node->count++;
        }
        node->is_end = true;
    }

    bool search(const string& word) {
        auto node = root;
        for (char ch : word) {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        return node->is_end;
    }

    bool starts_with(const string& prefix) {
        auto node = root;
        for (char ch : prefix) {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        return true;
    }

    void erase(const string& word) {
        if (!search(word)) return;
        auto node = root;
        for (char ch : word) {
            node = node->next[ch];
            node->count--;
        }
        node->is_end = false;
    }
};

//  Bit Trie //

class BitTrieNode {
public:
    BitTrieNode* child[2];
    int count;
    BitTrieNode() {
        child[0] = child[1] = nullptr;
        count = 0;
    }
};

class BitTrie {
private:
    BitTrieNode* root;
    const int MAX_BIT = 31; // for 32-bit integers

public:
    BitTrie() {
        root = new BitTrieNode();
    }

    void insert(ll num) {
        BitTrieNode* node = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new BitTrieNode();
            }
            node = node->child[bit];
            node->count++;
        }
    }

    void erase(ll num) {
        BitTrieNode* node = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            node = node->child[bit];
            node->count--;
        }
    }

    ll get_max_xor(ll num) {
        BitTrieNode* node = root;
        ll result = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int prefer = 1 - bit;
            if (node->child[prefer] && node->child[prefer]->count > 0) {
                result |= (1LL << i);
                node = node->child[prefer];
            } else {
                node = node->child[bit];
            }
        }
        return result;
    }

    ll get_min_xor(ll num) {
        BitTrieNode* node = root;
        ll result = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[bit] && node->child[bit]->count > 0) {
                node = node->child[bit];
            } else {
                result |= (1LL << i);
                node = node->child[1 - bit];
            }
        }
        return result;
    }
};

} 