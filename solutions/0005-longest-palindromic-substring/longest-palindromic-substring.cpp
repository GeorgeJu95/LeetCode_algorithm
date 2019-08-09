// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int last_len = 0, start = 0;
        for(int i=0; i<s.size(); ++i) {
            int len1 = lengthOfPalindrome(s, i, i);
            int len2 = lengthOfPalindrome(s, i, i+1);
            int len = max(len1, len2);
            if(len > last_len) {
                last_len = len;
                start = i-(len-1)/2;
            }
        }
        //获得字符串s中从第start位开始的长度为last_len的字符串
        return s.substr(start, last_len);
    }

    int lengthOfPalindrome(string s, int L, int R) {
        while(L>=0 && R<s.size() && s[L] == s[R]) {
            --L;
            ++R;
        }
        return R-L-1;
    }
};
