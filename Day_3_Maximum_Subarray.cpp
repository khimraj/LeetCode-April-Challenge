/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. */


/* Approach - array iteration */

// Time Complexity - O(n), where n is length of nums
// Space Complexity - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = 0;
        for (int i = 0; i < nums.size(); i++) { 
            if (currSum + nums[i] > nums[i]) {
                currSum = currSum + nums[i];
            }
            else {
                currSum = nums[i];
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};