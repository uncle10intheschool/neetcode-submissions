class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st; int res = 0;
        for (const string& s: operations){
            if (s == "C"){
                res -= st.back();
                st.pop_back();
            } else {
                int temp;
                if (s == "+"){
                    int n = st.size();
                    temp = st[n-1] + st[n-2];
                } else if (s == "D"){
                    temp = 2*st.back();
                } else {
                    temp = stoi(s);
                }
                res += temp;
                st.push_back(temp);
            }
        }
        return res;
    }
};