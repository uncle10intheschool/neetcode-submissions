class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int,int>> st; // <start,height>
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++){
            int start = i;
            while (!st.empty() && st.top().second > heights[i]){
                int w = i - st.top().first;
                int h = st.top().second;
                maxArea = max(maxArea,w*h);
                start = st.top().first;
                st.pop();
            }
            st.emplace(start,heights[i]);
        }

        while (!st.empty()){
            int w = heights.size() - st.top().first;
            int h = st.top().second;
            maxArea = max(maxArea,w*h);
            st.pop();
        }
        return maxArea;
    }
};