#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define _max(a, b) (a > b ? a : b)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        char ch_dict[130];      // O(n)
        memset(ch_dict, 0, sizeof(ch_dict));
        int s_idx = 0, e_idx = 1, max_len = 1;
        ch_dict[s[0]] = 1;
        while(e_idx < s.length()) {
            while(ch_dict[s[e_idx]] > 0) {
                max_len = _max(max_len, e_idx - s_idx);
                ch_dict[s[s_idx]]--;
                s_idx++;
            }
            ch_dict[s[e_idx]]++;
            e_idx++;
        }
        max_len = _max(max_len, e_idx - s_idx);
        return max_len;
    }
};


int main() {
    cout << Solution().lengthOfLongestSubstring(string("abcabcbb")) << "\n";
    return 0;
}
