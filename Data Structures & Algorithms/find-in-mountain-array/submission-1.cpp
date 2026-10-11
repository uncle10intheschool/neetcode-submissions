/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private: 
    inline int findPeak(MountainArray& m, int left, int right){
        while (left <= right){
            int peakIdx = left + (right - left)/2;
            int prev = m.get(peakIdx-1);
            int peak = m.get(peakIdx);
            int aft = m.get(peakIdx+1);
            if (prev < peak && peak > aft){
                return peakIdx;
            } else if (prev < peak && peak < aft){
                left = peakIdx + 1;
            } else right = peakIdx - 1;
        }
        return -1; // not exist peak
    }

    inline int findTargetAsc(MountainArray& m, int left, int right, int target){
        while (left <= right){
            int mid = left + (right - left)/2;
            int val = m.get(mid);
            if (val == target){
                return mid;
            } else if (val < target){
                left = mid + 1;
            } else right = mid - 1;
        }
        return -1; // not exist Idx
    }

    inline int findTargetDesc(MountainArray& m, int left, int right, int target){
        while (left <= right){
            int mid = left + (right - left)/2;
            int val = m.get(mid);
            if (val == target){
                return mid;
            } else if (val > target){
                left = mid + 1;
            } else right = mid - 1;
        }
        return -1; // not exist Idx
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // check MountArr
        int n = mountainArr.length();
        if (n < 3) return -1;
        // find MountPoint
        int mountPeakIdx = findPeak(mountainArr, 1, n-2);
        // BinarySearch to find minIdx
        // a. first asc
        int minIdx = findTargetAsc(mountainArr,0,mountPeakIdx,target);
        if (minIdx == -1){ // b. second desc
            minIdx = findTargetDesc(mountainArr,mountPeakIdx+1,n-1,target);
        }
        return minIdx;
    }
};