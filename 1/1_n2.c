#include <stdio.h>
#include <stdlib.h>
/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int idx1, idx2;
    *(returnSize) = 2;
    int *retArr = (int *)malloc(*returnSize * sizeof(int));
    int ans_flag = 0;
    for(idx1 = 0; idx1 < numsSize; idx1++) {
    	for(idx2 = idx1+1; idx2 < numsSize; idx2++) {
			if(nums[idx1] + nums[idx2] == target) {
				retArr[0] = idx1;
				retArr[1] = idx2;
        		ans_flag = 1;
        		break;
			}
		}
		if(ans_flag) break;
	}
	return retArr;
}


int main() {
	int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int numsSize = 10;
	int target = 10;
	int returnSize = -1;
	int idx;

	int *retArr = twoSum(nums, numsSize, target, &returnSize);

	for(idx = 0; idx < returnSize; idx++) {
		printf("%d\n", retArr[idx]);
	}

	return 0;
}
