#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/****************************************************************/

#define _min(a, b) (a > b ? b : a)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> prex_sum;
        for(int i = 0; i < nums.size(); i++)
            prex_sum.push_back(i == 0 ? nums[i] : nums[i] + prex_sum[i-1]);
        int s_idx=0, e_idx=0;
        int min_len = nums.size() + 1;
        while(s_idx <= e_idx) {
            // sum of nums[s_idx] ... nums[e_idx]
            int tmp_sum = (s_idx == 0 ? prex_sum[e_idx] : prex_sum[e_idx] - prex_sum[s_idx-1]);
            if(tmp_sum >= s) {
                min_len = _min(min_len, e_idx - s_idx + 1);
                s_idx++;
            } else {
                if(e_idx != nums.size() - 1) e_idx++;
                else  s_idx++;
            }
        }
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};

/****************************************************************/

int main() {
    vector<int> nums = {101};
    int s = 100;
    cout << Solution().minSubArrayLen(s, nums) << "\n";
	return 0;
}
