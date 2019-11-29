// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> combination;
        
        helper(nums, ans, combination);
        return ans;
    }
    
    void helper(const vector<int> nums, vector<vector<int> >& ans, vector<int> combination) {
        if(combination.size() == nums.size()) {
            ans.emplace_back(combination);
            return ;
        }
        
        for(int i=0; i<nums.size(); ++i) {
            if(find(combination.begin(), combination.end(), nums[i]) == combination.end()) {
                combination.emplace_back(nums[i]);
                helper(nums, ans, combination);
                combination.pop_back();
            }
        }
    } 
};
