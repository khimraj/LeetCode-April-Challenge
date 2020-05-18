/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations. */


/* Approach - use two iterators*/

// Time Complexity - O(n), where n is length of nums
// Space Complexity - O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int iter1 = 0, iter2 = 0;
        while (iter2 < nums.size()) {
            while (iter2 < nums.size() && nums[iter2] == 0) {
                iter2++;
            }
            if (iter2 == nums.size()) {
                break;
            }
            nums[iter1++] = nums[iter2++];
        }
        while (iter1 < nums.size()) {
            nums[iter1++] = 0;
        }
        return;
    }
};