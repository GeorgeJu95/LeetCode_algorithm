// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
    public String multiply(String num1, String num2) {
        int m = num1.length(); int n = num2.length();
        int[] res = new int[m + n];
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                int mul = (num1.charAt(i)-'0') * (num2.charAt(j)-'0');
                int tmp = mul + res[i+j+1];
                res[i+j+1] = tmp % 10;
                // 注意进位要累计
                res[i+j] += tmp / 10;
            }
        }
        // String ret = "";
        // for(int num : res) {
        //     // 前导零的处理
        //     if(ret.length() == 0 && num == 0) continue;
        //     else ret += num;
        // }
        // return ret == "" ? "0" : ret;
        
        // 这个要快一些
        StringBuilder sb = new StringBuilder();
        for(int p : res) if(!(sb.length() == 0 && p == 0)) sb.append(p);
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
