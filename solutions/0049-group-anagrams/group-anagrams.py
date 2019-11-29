# Given an array of strings, group anagrams together.
#
# Example:
#
#
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
#   ["ate","eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]
#
# Note:
#
#
# 	All inputs will be in lowercase.
# 	The order of your output does not matter.
#
#


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        思路同上，在Python中，这里涉及到3个知识点：
        1. 使用内置的 defaultdict 字典设置默认值；
        2. 内置的 ord 函数，计算ASCII值（等于chr）或Unicode值(等于unichr)；
        3. 列表不可哈希，不能作为字典的键，因此这里转为元组；
        """
        # 建立一个 26 长度的 counts 数组（如果区分大小写，我们可以建立 52 个，如果支持其他字符依次类推）。 
        # 然后我们给每一个字符一个固定的数组下标，然后我们只需要更新每个字符出现的次数。 
        # 最后形成的 counts 数组如果一致，则说明他们可以通过交换顺序得到
        str_dict = collections.defaultdict(list)
        for s in strs:
            s_key = [0] * 26
            for c in s:
                s_key[ord(c)-ord('a')] += 1
            str_dict[tuple(s_key)].append(s)
        return str_dict.values()
