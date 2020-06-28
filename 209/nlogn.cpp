#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/****************************************************************/

#define _min(a, b) (a > b ? b : a)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) { // O(nlogn)
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> prex_sum;
        int min_len = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++)
            prex_sum.push_back(i == 0 ? nums[i] : nums[i] + prex_sum[i-1]);
        for(int i = 0; i < nums.size(); i++) { // O(n)
            vector<int>::iterator lower_iter = lower_bound((prex_sum.begin() + i), prex_sum.end(), (i == 0 ? s : (prex_sum[i-1]+s)));		// Olog(n)
//            cout << i << " " << lower_iter - prex_sum.begin() << " " << (lower_iter - prex_sum.begin()) - i + 1 << "\n";					// Debug
            if(lower_iter == prex_sum.end()) continue; 
            min_len = _min(min_len, (lower_iter - prex_sum.begin()) - i + 1);
        }
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};

/****************************************************************/

int main() {
    vector<int> nums = {2, 16, 14, 15};
    int s = 20;
//    sort(nums.begin(), nums.end());
//    cout << lower_bound(nums.begin(), nums.end(), 2) - nums.begin() << "\n";
    cout << Solution().minSubArrayLen(s, nums) << "\n";
	return 0;
}
