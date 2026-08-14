class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        int i = 0, j = n-1;
        while (i < j){
            int area = (j-i) * min(heights[j],heights[i]);
            if (area > maxArea) maxArea = area;
            if (heights[j] > heights[i]) i++;
            else j--;
        }
        return maxArea;
    }
};