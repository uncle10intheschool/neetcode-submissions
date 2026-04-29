class Solution {
public:
    void heapify(vector<int>&a, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;
        if (largest != i){
            swap(a[largest],a[i]);
            heapify(a,n,largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        for (int i = nums.size()/2 - 1; i >= 0; i--){
            heapify(nums,nums.size(),i);
        }

        for (int i = nums.size()-1; i > 0; i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
        return nums;
    }
};