// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "") return b;
        if(b == "") return a;
        string ans = "";
        int len1 = a.size();
        int len2 = b.size();
        int i = len1-1; int j = len2-1;
        int carry = 0;
        while(i >= 0 || j >= 0) {
            int tmp = (i >= 0 ? (a[i--]-'0') : 0) + (j >= 0 ? (b[j--]-'0') : 0) + carry;
            cout << tmp << endl;
            ans = to_string(tmp % 2) + ans;
            carry = tmp / 2;
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};
