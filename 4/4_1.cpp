#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int idx1=0, idx2=0;
        while(idx1 < nums1.size() || idx2 < nums2.size()) {
            if(idx1 == nums1.size()) {
                merged.push_back(nums2[idx2]);
                idx2++;
            } else if(idx2 == nums2.size()) {
                merged.push_back(nums1[idx1]);
                idx1++;
            } else if(nums1[idx1] < nums2[idx2]) {
                merged.push_back(nums1[idx1]);
                idx1++;
            } else {
                merged.push_back(nums2[idx2]);
                idx2++;
            }
        }
        if(merged.size() % 2 != 0) {
            return merged[merged.size() / 2];
        } else {
            return (double)(merged[(merged.size() / 2) - 1] + merged[merged.size() / 2]) / 2;
        }
    }
};


int main() {
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << Solution().findMedianSortedArrays(a, b) << "\n";
    return 0;
}
