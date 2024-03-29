// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
//
//
// 	The number of elements initialized in nums1 and nums2 are m and n respectively.
// 	You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//
//
// Example:
//
//
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
//
// Output: [1,2,2,3,5,6]
//


class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0, j = 0, k = 0;
        int[] tmp = new int[m];
        System.arraycopy(nums1, 0, tmp, 0, m);
        for( ; i<m && j<n; ) {
            if(tmp[i] <= nums2[j]) nums1[k++] = tmp[i++];
            else nums1[k++] = nums2[j++];
        }
        while(i != m) {
            nums1[k++] = tmp[i];
            ++i;
        }
        while(j != n) {
            nums1[k++] = nums2[j];
            ++j;
        }
    }
}
