// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 1 && digits[0] == 0) {
            digits[0] = 1;
            return digits;
        }
        int carry = 0;
        int n = digits.size();
        for(int i=n-1; i>=0; --i) {
            int tmp = digits[i] + carry;
            tmp += (i == n-1) ? 1 : 0;
            digits[i] = (tmp % 10);
            carry = tmp / 10;
            if(!carry) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
