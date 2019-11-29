// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string key = s; 
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        
        vector<vector<string>> anagrams;
        for(auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
    
    
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         for (string s : strs) {
//             // 由于都是小写字母，可以采用计数排序
//             mp[strSort(s)].push_back(s);
//         }
//         vector<vector<string>> anagrams;
//         for (auto p : mp) { 
//             anagrams.push_back(p.second);
//         }
//         return anagrams;
//     }
// private:
//     string strSort(string s) {
//         int counter[26] = {0};
//         for (char c : s) {
//             counter[c - 'a']++;
//         }
//         string t;
//         for (int c = 0; c < 26; c++) {
//             t += string(counter[c], c + 'a');
//         }
//         return t;
//     }
};





