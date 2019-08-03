# -*- coding:utf-8 -*-


# We are given hours, a list of the number of hours worked per day for a given employee.
#
# A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
#
# A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
#
# Return the length of the longest well-performing interval.
#
#  
# Example 1:
#
#
# Input: hours = [9,9,6,0,6,6,9]
# Output: 3
# Explanation: The longest well-performing interval is [9,9,6].
#
#
#  
# Constraints:
#
#
# 	1 <= hours.length <= 10000
# 	0 <= hours[i] <= 16
#
#


class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        res = cnt = 0
        seen = {}
        for i, num in enumerate(hours):
            cnt += (1 if num > 8 else -1)
            seen.setdefault(cnt, i) 
            #dict.setdefault(key, default=None)
            #如果字典中包含有给定键，则返回该键对应的值，否则返回为该键设置的值。
            if(cnt > 0): 
                res = i + 1
            elif cnt-1 in seen:
                res = max(res, i-seen[cnt-1])
        return res
        
