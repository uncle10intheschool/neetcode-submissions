class Solution {
private:
    void heapify(vector<int>& a,const int& size, int i){
        int largest = i;
        int left = i*2 + 1;
        int right = i*2 + 2;
        if (left < size && a[left] > a[largest]) largest = left;
        if (right < size && a[right] > a[largest]) largest = right;
        if (largest != i){
            swap(a[largest],a[i]);
            heapify(a,size,largest);
        }
    }

    void heapSort(vector<int>& a,const int& size){
        for (int i = size/2-1; i >= 0; i--){
            heapify(a,size,i);
        }

        for (int i = size-1; i > 0; i--){
            swap(a[i],a[0]);
            heapify(a,i,0);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        heapSort(nums,size);
        return nums;
    }
};