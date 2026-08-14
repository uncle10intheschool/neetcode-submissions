class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int i = 0, j = people.size()-1;
        while (i < j){
            int sum = people[i] + people[j--];
            count++;
            if (sum <= limit){
                i++;
            }
        }
        if (i == j) count++;
        return count;
    }
};