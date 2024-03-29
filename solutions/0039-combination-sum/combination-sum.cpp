// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, res, combination, 0);
        
        return res;
    }
    
    void helper(const vector<int>& candidates, int target, vector<vector<int> >& res, vector<int> combination, int begin) {
        if(!target) res.emplace_back(combination);
        
        for(int i=begin; i<candidates.size(); ++i) {
            if(candidates[i] <= target) { 
                combination.emplace_back(candidates[i]);
                helper(candidates, target-candidates[i], res, combination, i);
                combination.pop_back();
            }
        }
    }
};
