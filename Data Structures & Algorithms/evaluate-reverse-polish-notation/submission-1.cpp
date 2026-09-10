class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s: tokens){
            if (s == "+" || s == "*" || s == "/" || s == "-"){
                int A = st.top(); st.pop(); // số gần dấu hơn
                int B = st.top(); st.pop(); // số xa dấu hơn
                int res = 0;
                if (s == "+") res = B + A;
                if (s == "*") res = B * A;
                if (B != 0 && s == "/") res = B / A;
                if (s == "-") res = B - A;
                st.push(res);
            } else { 
                int c = stoi(s);
                st.push(c);
            }
        }
        return st.top();
    }
};