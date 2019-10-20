// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int len = normalize(s);
        // for(int i=0; i<len; ++i) {
        //     cout << s[i];
        // }
        
        for(int i=0, j=len-1; i<j; ++i,--j) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
    int normalize(string& s) {
        int tmp = 0, i;
        for(i=0; i<s.size(); ++i) {
            if(isalnum(s[i])) {
                s[i-tmp] = tolower(s[i]);
            }
            else ++tmp;
        }
        return i-tmp;
    }
};
