class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st; int res = 0;
        for (const string& s: operations){
            if (s == "C"){
                res -= st.top();
                st.pop();
            } else {
                int temp;
                if (s == "+"){
                    int top1 = st.top(); st.pop();
                    int top2 = st.top();
                    temp = top1 + top2;
                    st.push(top1); 
                } else if (s == "D"){
                    temp = 2*st.top();
                } else {
                    temp = stoi(s);
                }
                res += temp;
                st.push(temp);
            }
        }
        return res;
    }
};