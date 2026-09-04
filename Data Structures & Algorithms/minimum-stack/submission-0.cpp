class MinStack {
private:
    vector<int> st;
public:
    MinStack() {}

    // everytime I push & pop I update.
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int minVal = st[0];
        for (const int& x: st){
            minVal = min(minVal,x);
        }
        return minVal;
    }
};