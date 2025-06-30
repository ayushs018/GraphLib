#pragma once 
#define ll long long 
#include <vector> 
#include <bits/stdc++.h> 
#include <functional> 

using namespace std ; 

namespace graphlib {
    class Manacher {
        public : 
            vector<int> p; 
            vector<int> run_manacher(string s) {
                int n = s.size(); 
                p.assign(n,1);
                int l = 1 , r = 1 ; 
                for (int i = 1 ; i < n ; i++) {
                    p[i] = max (0 , min(r-i , p[r+l-1]));
                    while (i+p[i] < n && i-p[i] >= 0 && s[i+p[i]] == s[i-p[i]]) {
                        p[i] ++; 
                    }
                    if (i+p[i] > r) {
                        l = i-p[i]; 
                        r = i+p[i]; 
                    }
                }
                return p; 
            }
            vector<int> build (string s) {
                string t; 
                for (auto v : s) {
                    t += string ("#")+v; 
                }
                vector<int> v = run_manacher (t+"#"); 
                return v; 
            }
            int getLongest (int c , bool odd) {
                int pos = 2*c + 1 + (!odd);
                return p[pos]-1; 
            }

            bool checkIsPalindrome (int l , int r) {
                if ((r-l+1) <= getLongest((l+r)/2 , l%2 == r%2)) return true ; 
                else return false; 
            }
    } ;
}