// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k;
        for(k=n-2; k>=0; --k) {
            // 找到第一个前一个比后一个小的情况，因为后面倒序排列，是k位置后面最后的序列
            if(nums[k] < nums[k+1])
                break;
        }
        // 如果整个序列都是倒序，说明已经是最后一个序列
        if(k < 0) {
            reverse(begin(nums), end(nums));
            return;
        }
        
        int l;
        for(l=n-1; l>k; --l) {
            // 找到k位置后面序列中比k大的那个数字，和k交换后对后面的序列进行reverse（变升序），即下一个排列
            if(nums[l] > nums[k])
                break;
        }
        
        swap(nums[k], nums[l]);
        reverse(begin(nums)+k+1, end(nums));
    }
};
