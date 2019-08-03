// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i< nums.size(); i++){
            // 该数字第一次出现
            if (m.find(nums[i]) == m.end()) {
                // 把该数字的位置存到 m[target-nums[i]] 中
                m[target - nums[i]] = i;
            }else {
                // 数字“出现过”，即有和前面匹配的数字，依次存下位置
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};
