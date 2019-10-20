//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    
    void backtrack(vector<string>& res, string tmp, int left, int right, int n) {
        if(tmp.length() == 2*n) res.push_back(tmp);
        if(left < n) backtrack(res, tmp+'(', left+1, right, n); 
        if(right < left) backtrack(res, tmp+')', left, right+1, n); 
    }
};
