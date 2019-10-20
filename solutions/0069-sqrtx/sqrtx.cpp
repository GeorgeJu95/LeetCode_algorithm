// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
//
//


class Solution {
public:
    int mySqrt(int x) {
        // f(a) = a^2 - x ; f'(a) = 2 * a ; a_(n+1) = a_n - f(a)/f'(a)
        double ans = x;
        while(fabs(pow(ans, 2) - x) > 0.0001) {
            ans = (ans + x/ans) / 2;
        }
        return ans;
    }
};
