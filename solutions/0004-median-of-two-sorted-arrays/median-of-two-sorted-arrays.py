# There are two sorted arrays nums1 and nums2 of size m and n respectively.
#
# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#
# You may assume nums1 and nums2 cannot be both empty.
#
# Example 1:
#
#
# nums1 = [1, 3]
# nums2 = [2]
#
# The median is 2.0
#
#
# Example 2:
#
#
# nums1 = [1, 2]
# nums2 = [3, 4]
#
# The median is (2 + 3)/2 = 2.5
#
#


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        if n == 0:
            raise ValueError
        # nums1 -> A; nums2 -> B
        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax: # 在imin ~ imax之间搜索 合适的i
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and nums2[j-1] > nums1[i]:
                # i < m 就能保证 j > 0
                # i 的值太小， 增加它
                imin = i + 1
            elif i > 0 and nums1[i-1] > nums2[j]:
                # i > 0 就能保证 j < n
                # i 的值过大， 减小它
                imax = i - 1
            else:
                # i is perfect
                if i == 0: max_of_left = nums2[j-1] # i=0表示A没有left部分
                elif j == 0: max_of_left = nums1[i-1] # j=0表示B没有left部分
                else: max_of_left = max(nums1[i-1], nums2[j-1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m: min_of_right = nums2[j] # i=m表示A没有right部分
                elif j == n: min_of_right = nums1[i]# j=n表示B没有right部分
                else: min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0
