# Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
#
# Return the quotient after dividing dividend by divisor.
#
# The integer division should truncate toward zero.
#
# Example 1:
#
#
# Input: dividend = 10, divisor = 3
# Output: 3
#
# Example 2:
#
#
# Input: dividend = 7, divisor = -3
# Output: -2
#
# Note:
#
#
# 	Both dividend and divisor will be 32-bit signed integers.
# 	The divisor will never be 0.
# 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
#
#


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """
        二分法
        :param int divisor
        :param int dividend
        :return int
        """
        # 错误处理
        if divisor == 0:
            raise ZeroDivisionError
        if abs(divisor) == 1:
            result = dividend if 1 == divisor else -dividend
            return min(2**31-1, max(-2**31, result))

        # 确定结果的符号
        sign = ((dividend >= 0) == (divisor >= 0))
        
        result = 0
        # abs也可以直接写在while条件中，不过可能会多计算几次
        _divisor = abs(divisor)
        _dividend = abs(dividend)
        
        while _divisor <= _dividend:
            r, _dividend = self._multi_divide(_divisor, _dividend)
            result += r
        
        result = result if sign else -result

        # 注意返回值不能超过32位有符号数的表示范围
        return min(2**31-1, max(-2**31, result))
    
    
    # 翻倍除法，需要单独成一个函数，应为有可能出现最后一个翻倍无法满足，却仍然存在没除尽的情况
    def _multi_divide(self, divisor, dividend):
        """
        【核心翻倍除法，如果一个个减去divisor是会超时的】，如果可以被除，则下一步除数翻倍，直至除数大于被除数，
        返回商加总的结果与被除数的剩余值；
        这里就不做异常处理了；
        :param int divisor
        :param int dividend
        :return tuple result, left_dividend
        """
        result = 0
        times_count = 1
        while divisor <= dividend:
            dividend -= divisor
            result += times_count
            times_count += times_count
            divisor += divisor
        return result, dividend
