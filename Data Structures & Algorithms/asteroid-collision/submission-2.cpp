class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> remain;
        for (int i = 0; i < asteroids.size(); i++){
            // collision
            bool survive = true;
            while (!remain.empty() && remain.back() > 0 && asteroids[i] < 0){
                int val = abs(asteroids[i]);
                int top = remain.back();
                if (top < val){
                    remain.pop_back();
                } else if (top == val){
                    remain.pop_back();
                    survive = false;
                    break;
                } else {
                    survive = false;
                    break;
                }
            }
            // NOT collision 
            if (survive) remain.push_back(asteroids[i]);
        }
        return remain;     
    }
};