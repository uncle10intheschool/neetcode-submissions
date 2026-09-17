class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st; // fake Stack
        
        while (getline(ss,token,'/')){
            if (token == "" || token == ".") continue;
            else if (token == ".."){
                if (!st.empty()){
                    st.pop_back();
                }
            } else {
                st.push_back(token);
            }
        }

        if (st.empty()) return "/";

        string res = "";
        for (string& i : st){
            res += '/' + i;
        }
        return res;
    }
};