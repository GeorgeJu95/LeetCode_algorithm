// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 1 || numRows == 1) return s;
        vector<string> str(min(numRows, int(s.size())));
        int Num = 0;
        bool direction = false;
        for(auto c : s) {
            str[Num] += c;
            if(Num == 0 || Num == numRows-1) direction = !direction;
            Num += direction ? 1 : -1;
        }
        
        string res = "";
        for(auto row : str) res += row;
        
        return res;
    }
};
