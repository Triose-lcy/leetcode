#include <stdio.h>
#include <stdlib.h>
#include <map>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
        map<int, int> val_to_idx;
		for(int i = 0; i < nums.size(); i++) val_to_idx[nums[i]] = i;
		for(int i = 0; i < nums.size(); i++) if(val_to_idx[target - nums[i]]) {
			ans.push_back(i);
			ans.push_back(val_to_idx[target - nums[i]]);
			break;
		}
		return ans;
};


int main() {

	
}
