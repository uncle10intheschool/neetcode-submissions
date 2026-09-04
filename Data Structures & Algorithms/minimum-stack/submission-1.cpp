class MinStack {
private:
    vector<pair<int,int>> st;
public:
    MinStack() {}

    // everytime I push & pop I update.
    
    void push(int val) {
        int minVal = st.empty()? val : min(st.back().second,val);
        st.emplace_back(val,minVal);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
