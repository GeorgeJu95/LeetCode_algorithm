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
    public int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = Integer.MAX_VALUE;
        while (true) {
            int mid = left + (right - left) / 2;  // nice
            if (mid > x/mid) {  // nice
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
        
        // if(x == 0) return 0;
        // long left = 0, right = x;   使用long 才行，比较蠢
        // while(left <= right) {
        //     long mid = (left + right) / 2;
        //     long tmp = mid * mid;
        //     if(tmp > x) right = mid - 1;
        //     else if(tmp < x) left = mid + 1;
        //     else return (int)mid;
        // }
        // return (int)right;
    } 
}
