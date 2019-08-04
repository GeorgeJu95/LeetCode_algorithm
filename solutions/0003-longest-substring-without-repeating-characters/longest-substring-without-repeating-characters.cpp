// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int len = s.size();
    //     set<char> m;
    //     int ans = 0, i = 0, j = 0;
    //     //维持一个窗口[i, j),不在set中j++并且比较更新ans，在set中，j不动，i前进一格
    //     //j保持不动，就能构保证一定能让重复的出去，并且成为一个新的每个元素都不同的窗口
    //     while(i < len && j < len) {
    //         if(m.find(s[j]) != m.end())
    //             m.erase(s[i++]);
    //         else {
    //             m.insert(s[j++]);
    //             ans = max(ans, j-i);
    //         }
    //     }
    //     return ans;
    // }
    
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), ans = 0;
        int* index = new int[128]; //记录字符的索引（出现的下一个位置）
        //记录下每个字母出现的下一个位置，这样当字符重复时，只需要拿该位置和i比较并更新i即可维持窗口
        //这样可保证，立即更新到最新窗口，而且不会做无用功。例如bacabcbb
        for (int j = 0, i = 0; j < len; j++) {
            i = max(index[s[j]], i);
            ans = max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};
