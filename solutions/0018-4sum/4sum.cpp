// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() == 0 || nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // deduplicate
            for(int j=i+1; j<nums.size()-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue; // deduplicate
                int start = j+1; 
                int end = nums.size()-1;
                while(start < end) {
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum > target) --end;
                    else if(sum < target) ++start;
                    else {
                        vector<int> tmp{nums[i], nums[j], nums[start], nums[end]};
                        res.emplace_back(tmp);
                        // deduplicate
                        while(start < end && nums[start] == nums[start+1]) ++start;
                        while(start < end && nums[end] == nums[end-1]) --end;
                        --end;
                        ++start;
                    }
                }    
            }  
        }
        return res;
    }
};
