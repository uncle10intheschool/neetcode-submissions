class Solution {
public:
    string loop(int k, string s){
        string res;
        for (int i = 0; i < k; i++){
            res += s;
        }
        return res;
    }


    string decodeString(string s) {
        string st;
        for (char& c: s){
            if (c == ']'){
                string str = "";
                while (!st.empty() && st.back() != '['){
                    str = st.back() + str;
                    st.pop_back();
                }
                st.pop_back(); // del "["
                string num = "";
                while (!st.empty() && isdigit(st.back())){
                    num = st.back() + num;
                    st.pop_back();
                }
                int numInt = stoi(num);
                st += loop(numInt,str);
            }
            else st.push_back(c);
        }
        return st;
    }
};