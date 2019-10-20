// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//  
//
// Example 1:
//
//
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
//
// Example 2:
//
//
// Input:
//   s = "wordgoodgoodgoodbestword",
//   words = ["word","good","best","word"]
// Output: []
//
//


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(); int num = words.size(); 
        vector<int> ans;
        if(num == 0 || n == 0) return ans;
        int len = words[0].length();
        
        unordered_map<string, int> counts;
        for(auto word : words) {
            ++counts[word];
        }
        
        for(int i=0; i<n-num*len+1; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            for( ; j<num; ++j) {
                string tmp = s.substr(i + j*len, len);
                if(counts.find(tmp) != counts.end()) {
                    ++seen[tmp];
                    if(seen[tmp] > counts[tmp]) break;
                } else break;
            }
            if(j == num) ans.emplace_back(i);
        }
        return ans;
    }
};
