class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        // find right
        vector<int> colRight(n,0); int maxRight = height[n-1];
        for (int i = n-2; i >= 1; i--){
            if (height[i] > maxRight){
                maxRight = height[i];
            }
            colRight[i] = maxRight;
        }

        int colLeft = height[0];
        // find left
        for (int i = 1; i < n-1; i++){
            if (height[i] >= colLeft) colLeft = height[i];
            else {
                water += (min(colLeft,colRight[i]) - height[i]);
            }
        }
        return water;
    }
};