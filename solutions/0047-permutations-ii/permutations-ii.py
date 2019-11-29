# Given a collection of numbers that might contain duplicates, return all possible unique permutations.
#
# Example:
#
#
# Input: [1,1,2]
# Output:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ]
#
#


from collections import Counter

class Solution:
    def permuteUnique(self, nums):
        # print(Counter(nums))  Counter({1: 2, 2: 1})
        def btrack(path, counter):
            if len(path) == len(nums):
                ans.append(path[:])
                
            for x in counter:  # 用counter的增减来防止重复元素
                if counter[x] > 0:
                    path.append(x)
                    counter[x] -= 1
                    btrack(path, counter)
                    path.pop()
                    counter[x] += 1
                    
        ans = []
        btrack([], Counter(nums))
        return ans
