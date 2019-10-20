// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int tmp = 0;
        for(int i=0; i<nums.size(); ++i) {
            tmp += nums[i];
            if(nums[i] > tmp) tmp = nums[i];
            if(ans < tmp) ans = tmp;
        }
        return ans;
    }
};