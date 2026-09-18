class FreqStack {
private:
    unordered_map<int,int> freq;
    //
    unordered_map<int,stack<int>> m; // idx
    int max_freq;
public:
    FreqStack() {max_freq = 0;}
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > max_freq){
            max_freq = freq[val];
        }
        m[freq[val]].push(val);
    }
    
    int pop() {
        int val = m[max_freq].top();
        m[max_freq].pop();
        freq[val]--;
        if (m[max_freq].empty()) max_freq--;
        return val;
    }
};