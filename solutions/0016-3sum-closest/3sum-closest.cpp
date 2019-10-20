// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        //三个数，first为nums[i]，second为nums[i+1]，third为nums[nums.size()-1]
        //固定first，在second和third之间逼近target。之后i++更新first
        for(int i=0; i<nums.size()-2; ++i) {
            int start = i+1; int end = nums.size()-1;
            int tmp = 0;
            while(start < end) {
                tmp = nums[i] + nums[start] + nums[end];
                if(tmp > target) --end;
                else if(tmp < target) ++start;
                else return tmp;
                
                if(abs(tmp-target) < abs(result-target))
                    result = tmp;
            }
        }
        return result;
    }
};
