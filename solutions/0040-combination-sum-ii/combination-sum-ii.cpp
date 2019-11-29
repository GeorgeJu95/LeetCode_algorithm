// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
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
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        
        helper(candidates, res, combination, target, 0);
        return res;
    }
    
    void helper(vector<int>& candidates, vector<vector<int> >& res, vector<int> combination, int target, int begin) {
        if(target == 0) {
            res.emplace_back(combination);
            return;
        }
        
        for(int i=begin; i<candidates.size(); ++i) {
            if(i > begin && candidates[i] == candidates[i-1]) continue;
            
            if(candidates[i] <= target) {
                combination.emplace_back(candidates[i]);
                helper(candidates, res, combination, target-candidates[i], i+1);
                combination.pop_back();
            }
        }
    }
};
