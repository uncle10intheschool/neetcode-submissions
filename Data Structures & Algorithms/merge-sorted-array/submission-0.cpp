class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = 0, n2 = 0, i = 0;
        vector<int> copyNum = nums1;
        while (n1 < m && n2 < n){
            if(copyNum[n1] < nums2[n2]){
                nums1[i++] = copyNum[n1++];
            } else nums1[i++] = nums2[n2++];
        }
        while (n1 < m) nums1[i++] = copyNum[n1++];
        while (n2 < n) nums1[i++] = nums2[n2++];
    }
};
