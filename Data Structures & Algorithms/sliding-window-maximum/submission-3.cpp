class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; res.reserve(nums.size()-k+1);
        priority_queue<pair<int,int>> pq; // <nums[i],i>
        int left = 0;
        for (int right = 0; right < nums.size(); right++){ // O(n)
            pq.emplace(nums[right],right); // O(logN)
            if (right - left + 1 == k){
                // dọn trước
                while (!pq.empty() && pq.top().second < left) pq.pop();
                // 100% đã chuẩn maxVal --> push
                int maxVal = pq.top().first;
                res.push_back(maxVal);
                left++;
            }    
        }
        return res;
    }
};