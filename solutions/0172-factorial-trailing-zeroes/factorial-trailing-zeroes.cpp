// Given an integer n, return the number of trailing zeroes in n!.
//
// Example 1:
//
//
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
//
// Example 2:
//
//
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
//
// Note: Your solution should be in logarithmic time complexity.
//


class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i=1; ; ++i) {
            long tmp = pow(5, i);
            if(tmp > n) break;
            ans += n/tmp;
        }

        return ans;
    }
    
    long pow5(int n) {
        if(n == 1) return 5;
        return pow5(n-1) * 5;
    }
};
