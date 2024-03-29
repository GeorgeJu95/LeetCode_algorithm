// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
// Note: Given n will be a positive integer.
//
// Example 1:
//
//
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
//
//
// Example 2:
//
//
// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
//
//


class Solution {
    public int climbStairs(int n) {
        int[] f = new int[n+2];
        f[1] = 1;
        f[2] = 2;
        if(n == 1) return f[1];
        if(n == 2) return f[2];
        int tmp = 3;
        while(tmp != n+1) {
            f[tmp] = f[tmp-1] + f[tmp-2];
            tmp++;
        }
        
        return f[n];
    }
}
