// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        
        backtrace(nums, ans, 0);
        return ans;
    }
    
    void backtrace(vector<int> nums, vector<vector<int>>& ans, int begin) {
        if(begin == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        
        for(int i=begin; i<nums.size(); ++i) {
            // if(i>begin && nums[i] == nums[i-1]) continue;  错误！！
            // if(i > begin && nums[i] == nums[begin]) continue; 
            // if(i != begin && ((nums[i] == nums[begin]) || (nums[i] == nums[i-1]))) continue; 错误！！ 
            int j = i-1;  // nums[i]要和前面的一个都不相同！！否则换过去不就一样的嘛
            while(j >= begin && nums[i] != nums[j]) {
                --j;
            }
            
            if(i == begin || j < begin) {
                swap(nums[i], nums[begin]);
                backtrace(nums, ans, begin+1);
                swap(nums[i], nums[begin]);
            }
        }        
    }
};
