class Solution {
public:
    bool isValid(string s) {
        vector<char> st; st.reserve(s.size());
        st.push_back(s[0]);
        for (int i = 1; i < s.size(); i++){
            if (!st.empty() && 
            (st.back() == '(' && s[i] == ')' 
            || st.back() == '[' && s[i] == ']' 
            || st.back() == '{' && s[i] == '}')) st.pop_back();
            else st.push_back(s[i]);
        }
        return st.empty();
    }
};