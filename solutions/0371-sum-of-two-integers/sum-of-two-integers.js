// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//
// Example 1:
//
//
// Input: a = 1, b = 2
// Output: 3
//
//
//
// Example 2:
//
//
// Input: a = -2, b = 3
// Output: 1
//
//
//
//


/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
    if(a === 0) return b;
    if(b === 0) return a;
    
    // 异或可以看做不进位的加减法，与运算之后左移一位可以表示进位
    return getSum(a ^ b, (a & b) << 1);
};
