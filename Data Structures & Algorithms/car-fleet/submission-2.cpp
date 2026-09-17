class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) a.emplace_back(position[i],speed[i]);
        sort(a.rbegin(),a.rend());
        stack<double> st;
        for (int i = 0; i < n; i++){
            double time = (double)(target - a[i].first)/a[i].second;
            if (st.empty() || time > st.top()){
                st.push(time);
            }
            // else time <= st.top()
        }
        return st.size();
    }
};