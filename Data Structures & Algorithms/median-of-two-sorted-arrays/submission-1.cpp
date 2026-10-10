class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);

        int n = nums1.size();
        int m = nums2.size();

        int halfLen = (m + n + 1)/2;
        int left = 0; int right = n;
        while (left <= right){
            int i = left + (right - left) /2;
            int j = halfLen - i;

            int maxLeftA = (i == 0) ? INT_MIN : nums1[i-1];
            int minRightA = (i == n) ? INT_MAX : nums1[i];
            
            int maxLeftB = (j == 0) ? INT_MIN : nums2[j-1];
            int minRightB = (j == m) ? INT_MAX : nums2[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA){
                if ((m + n)%2 != 0){
                    return max(maxLeftA,maxLeftB);
                } else {
                    int maxLeft = max(maxLeftA,maxLeftB);
                    int minRight = min(minRightA,minRightB);
                    return (maxLeft + minRight)/2.0;
                }
            } else if (maxLeftA > minRightB){
                right = i - 1;
            } else left = i + 1;
        }
        return 0.0;
    }
};