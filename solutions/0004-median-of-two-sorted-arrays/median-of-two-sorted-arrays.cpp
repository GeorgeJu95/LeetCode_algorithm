// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(n == 0) {
            if(m % 2 == 1) return (double)nums1[m/2];
            else return (nums1[m/2-1]+nums1[m/2]) / 2.0;
        }
        if(m == 0) {
            if(n % 2 == 1) return nums2[n/2];
            else return (nums2[n/2-1]+nums2[n/2]) / 2.0;
        }
        int cnt = 0;
        if((m+n) % 2 == 1) {
            // cout << "flag";
            int i = 0, j = 0;
            int index = (m+n)/2 + 1;
            while(i<m && j<n) {
                if(nums1[i] <= nums2[j]) {
                    ++i; ++cnt;
                    if(cnt == index) return (double)nums1[i-1];
                } else {
                    ++j; ++cnt;
                    if(cnt == index) return (double)nums2[j-1];
                }
            }
            while(i < m) {
                ++i; ++cnt;
                if(cnt == index) return (double)nums1[i-1];
            }
            while(j < n) {
                ++j; ++cnt;
                if(cnt == index) return (double)nums2[j-1];
            }
        } else {
            int i = 0, j = 0, tmp1=0, tmp2=0;
            int index1 = (m+n)/2, index2 = (m+n)/2 + 1;
            while(i<m && j<n) {
                if(nums1[i] <= nums2[j]) {
                    ++i; ++cnt;
                    if(cnt == index1) tmp1 = nums1[i-1];
                    if(cnt == index2) {
                        tmp2 = nums1[i-1];
                        break;
                    }
                } else {
                    ++j; ++cnt;
                    if(cnt == index1) tmp1 = nums2[j-1];
                    if(cnt == index2) {
                        tmp2 = nums2[j-1];
                        break;
                    }
                }
            }
            // cout << tmp1 << ' ' << tmp2;
            while(i < m) {
                ++i; ++cnt;
                if(cnt == index1) tmp1 = nums1[i-1];
                if(cnt == index2) {
                    tmp2 = nums1[i-1];
                    break;
                }
            }
            // cout << cnt ;
            while(j < n) {
                ++j; ++cnt;
                if(cnt == index1) tmp1 = nums2[j-1];
                if(cnt == index2) {
                    tmp2 = nums2[j-1];
                    // cout << tmp1 << ' ' << tmp2;
                    break;
                }
            }
            return (tmp1 + tmp2) / 2.0;
        }
        return 0;
    }
};
