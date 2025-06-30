#include <iostream>
#include "graphlib/string/manacher.hpp"
using namespace std;
using namespace graphlib;

int main() {
    string s = "abba";

    Manacher manacher;
    vector<int> pal_lengths = manacher.build(s); 

    cout << "Original string: " << s << endl;
    cout << "Palindrome lengths in transformed string:\n";
    for (int i = 0; i < pal_lengths.size(); ++i) {
        cout << "Index " << i << ": " << pal_lengths[i] << "\n";
    }

    cout << manacher.checkIsPalindrome(0,3) << endl ; // is the substring between l and r is a palindrome 
    cout << manacher.getLongest(1,0) << endl ; // idx , isOdd

    return 0;
}
