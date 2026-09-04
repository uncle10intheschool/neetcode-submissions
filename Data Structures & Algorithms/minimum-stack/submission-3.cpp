using ll = long long;

class MinStack {
private:
    ll minVal;
    stack<ll> st;
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()){
            st.push(0);
            minVal = val;
        } else {
            st.push(val-minVal); // dist --> >= 0 skip | < 0 update min 
            if (val < minVal) minVal = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        ll pop = st.top();
        st.pop();

        if (pop < 0) minVal -= pop; // lấy oldMin
    }
    
    int top() {
        ll top = st.top();

        return top > 0 ? top + minVal : (int)minVal;
    }
    
    int getMin() {
        return (int)minVal;
    }
};
