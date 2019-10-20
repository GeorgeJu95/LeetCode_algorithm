// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
//
// Input: "Hello World"
// Output: 5
//
//
//  
//


class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0) return 0;
        int cnt = 0;
        bool first = 1;
        for(int i=s.length()-1; i>=0; --i) {
            if(first) {
                if(s[i] == ' ') ;
                else {
                    first = 0;
                    ++cnt;
                }
            }
            else if(s[i] != ' ') ++cnt;
            else break;
        }
        return cnt;
    }
};
