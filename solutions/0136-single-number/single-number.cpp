// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,1]
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,1,2,1,2]
// Output: 4
//
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 任何数和本身异或则为0
        // 任何数和 0 异或是本身
        int ret = 0;
        for(int num : nums) {
            ret ^= num;
        }
        return ret;
    }
};
