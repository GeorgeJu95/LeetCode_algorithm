// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//


class Solution {
    public int nthUglyNumber(int n) {
        int[] table = new int[n];
        int index2 = 0, index3 = 0, index5 = 0;
        table[0] = 1;
        for(int i=1; i<table.length; i++) {
            table[i] = Math.min(table[index2]*2, Math.min(table[index3]*3, table[index5]*5));
            if(table[i] == table[index2]*2) index2++;
            if(table[i] == table[index3]*3) index3++;
            if(table[i] == table[index5]*5) index5++;
        }
        return table[n-1];
    }
}
