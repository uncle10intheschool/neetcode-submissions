class MyQueue {
private:
    stack<int> q;
public:
    MyQueue() {}
    
    void push(int x) {
        vector<int> temp;
        while (!q.empty()){
            temp.push_back(q.top());
            q.pop();
        }
        q.push(x);
        for (int i = temp.size()-1; i >= 0; i--){
            q.push(temp[i]);
        }
    }
    
    int pop() {
        int front = q.top();
        q.pop();
        return front;
    }
    
    int peek() {
        return q.top();  
    }
    
    bool empty() {
        return q.empty();
    }
};