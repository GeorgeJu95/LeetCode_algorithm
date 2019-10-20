# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#
#
# P   A   H   N
# A P L S I I G
# Y   I   R
#
#
# And then read line by line: "PAHNAPLSIIGYIR"
#
# Write the code that will take a string and make this conversion given a number of rows:
#
#
# string convert(string s, int numRows);
#
# Example 1:
#
#
# Input: s = "PAYPALISHIRING", numRows = 3
# Output: "PAHNAPLSIIGYIR"
#
#
# Example 2:
#
#
# Input: s = "PAYPALISHIRING", numRows = 4
# Output: "PINALSIGYAHRPI"
# Explanation:
#
# P     I    N
# A   L S  I G
# Y A   H R
# P     I
#


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # 直接按row来读并记录，最后输出ret
        
        if numRows == 1: return s
        # 分别画出numRows == 3，4，5.找出规律
        ret = ""
        cycLen = numRows + numRows - 2
        i = 0
        while i < numRows:
            j = 0
            while j + i < len(s):
                ret += s[j+i]
                # 不是第一排和最后一排要特殊处理
                if i != 0 and i != numRows-1 and j+cycLen-i < len(s):
                    ret += s[j+cycLen-i]
                j += cycLen
            i += 1
        return ret
