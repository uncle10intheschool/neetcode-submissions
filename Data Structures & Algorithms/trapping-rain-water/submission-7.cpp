class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;

        for (int i = 0; i < n; i++){
            while (!st.empty() && height[i] >= height[st.top()]){
                int mid = height[st.top()];
                st.pop();
                if (!st.empty()){
                    int right = height[i];
                    int left = height[st.top()];

                    int h = min(right,left) - mid;
                    int w = i - st.top() - 1;

                    res += h*w;
                }
            }
            st.push(i);
        }

        return res;
    }
};