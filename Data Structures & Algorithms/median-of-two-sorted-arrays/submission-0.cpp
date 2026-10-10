class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mergeLen = nums1.size() + nums2.size(); 
        vector<int> mergeArr;
        mergeArr.reserve(mergeLen);

        int i1 = 0; int i2 = 0; int i = 0;
        while (i1 < nums1.size() && i2 < nums2.size()){
            if(nums1[i1] <= nums2[i2]){
                mergeArr.emplace_back(nums1[i1++]);
            } else {
                mergeArr.emplace_back(nums2[i2++]);
            }
        }
        while (i1 < nums1.size()) mergeArr.emplace_back(nums1[i1++]);
        while (i2 < nums2.size()) mergeArr.emplace_back(nums2[i2++]);


        if (mergeLen%2 != 0){
            return 1.0*mergeArr[mergeLen/2];
        }
        return (mergeArr[mergeLen/2 - 1] + mergeArr[mergeLen/2]) / 2.0;
    }
};