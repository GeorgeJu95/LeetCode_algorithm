// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example 1:
//
//
// Input: 16
// Output: true
//
//
//
// Example 2:
//
//
// Input: 5
// Output: false
//
//
// Follow up: Could you solve it without loops/recursion?


class Solution {
public:
    bool isPowerOfFour(int num) {
        // 循环写法
        // while(num && num % 4 == 0) {
        //     num /= 4;
        // }
        // return num == 1;
        if(num == 1) return true;
        if(num < 4) return false;

        if((num & (num - 1)) != 0) return false;   // 2的倍数

        return (num & 0x55555555) == num;
    }
};
