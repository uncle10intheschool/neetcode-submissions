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
                    int top1 = st.back(); st.pop_back();
                    int top2 = st.back();
                    temp = top1 + top2;
                    st.push_back(top1); 
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