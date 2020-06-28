#include <iostream>
#include <vector>
using namespace std;


#define getTargetIndex(n) (n - 1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // The answer cannot be either negatives or positives larger than the vector's size.
        // Put -1 to these items
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < 1) nums[i] = -1;
            if (nums[i] > nums.size()) nums[i] = -1;
        }

        // Put each value which is not -1 to nums[value-1]
        int idx = 0, tmp_val = 0;
        int ans = nums.size() + 1;
        // It seems like O(n^2) during the process of adjustment, 
        // but actually each place in nums is only iterated for one time.
        while(idx < nums.size()) {
            if (nums[idx] < 0 or nums[idx] == idx + 1) { idx++; continue;}
            tmp_val = nums[getTargetIndex(nums[idx])];
            nums[getTargetIndex(nums[idx])] = nums[idx];
            while(tmp_val != -1 and nums[getTargetIndex(tmp_val)] != tmp_val) {
                int tmp_val1 = nums[getTargetIndex(tmp_val)];
                nums[getTargetIndex(tmp_val)] = tmp_val;
                tmp_val = tmp_val1;
            }
            idx++;
        }

        // If some value is not at the right place, it is the answer.
        // If all values are at the right place(nums[value-1] == value), the answer would be nums.size() + 1
        for(int i = 0; i < nums.size(); i++) if (i + 1 != nums[i]) {
            ans = i + 1;
            break;
        }
        return ans;
    }
};

int main() {
	vector<int> a = {8, 12, 14, 9, 5, 2, 6, 1};
	int ans = Solution().firstMissingPositive(a);
	cout << ans << "\n";
	return 0;
}
