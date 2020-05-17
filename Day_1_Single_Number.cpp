/*  Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4  */


/* Approach - use xor operator */

// Time Complexity - O(n), where n is length of nums
// Space Complexity - O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorValue = 0;
        for (int n : nums) {
            xorValue ^= n;
        }
        return xorValue;
    }
};