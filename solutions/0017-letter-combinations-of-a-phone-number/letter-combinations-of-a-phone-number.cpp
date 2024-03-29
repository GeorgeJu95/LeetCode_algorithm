// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        vector<vector<char>> table(2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); 
        table.push_back(vector<char>{'d','e','f'}); 
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); 
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); 
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); 
        
        backtracking(table, res, local, 0, digits);
        return res;
    }
    
    void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, int index, const string& digits) {
        if(index == digits.size())
            res.push_back(local);
        else
            for(int i=0; i<table[digits[index]-'0'].size(); ++i) {
                local.push_back(table[digits[index]-'0'][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
    }
};
