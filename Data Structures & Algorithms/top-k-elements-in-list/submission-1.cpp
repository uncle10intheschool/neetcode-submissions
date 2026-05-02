class Solution {
public:
    struct Node{
        int key; // nums[i]
        int data; // count
        Node* pNext;
        Node(int k){
            key = k;
            data = 1;
            pNext = nullptr;
        }
    };

    struct hashMap{
        int TABLE_SIZE;
        vector<Node*> table;
        int currSize;

        hashMap(int size){
            TABLE_SIZE = size;
            table.assign(TABLE_SIZE,nullptr);
            currSize = 0;
        }

        int hashFunc(int key){
            return (key%TABLE_SIZE + TABLE_SIZE) %TABLE_SIZE;
        }

        void rehash(){
            int oldSize = TABLE_SIZE;
            vector<Node*> oldTable = table;
            currSize = 0;

            TABLE_SIZE *= 2;
            table.assign(TABLE_SIZE,nullptr);
            for (int i = 0; i < oldSize; i++){
                Node* curr = oldTable[i];
                while (curr != nullptr){
                    Node* temp = curr->pNext;
                    int idx = hashFunc(curr->key);
                    curr->pNext = table[idx];
                    table[idx] = curr;
                    curr = temp;
                    currSize++;
                }
            }
        }

        void add(int key){
            double factor = (double)currSize/TABLE_SIZE;
            if (factor >= 0.75) rehash();

            int idx = hashFunc(key);
            Node* curr = table[idx];
            while (curr != nullptr){
                if (curr->key == key){
                    curr->data++;
                    return;
                }
                curr = curr->pNext;
            }

            Node* newNode = new Node(key);
            newNode->pNext = table[idx];
            table[idx] = newNode;
            currSize++;
        }

        ~hashMap(){
            for (int i = 0; i < TABLE_SIZE; i++){
                Node* curr = table[i];
                while (curr != nullptr){
                    Node* temp = curr;
                    curr = curr->pNext;
                    delete temp;
                }
            }
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        hashMap myMap(nums.size());

        for (int i = 0; i < nums.size(); i++){
            myMap.add(nums[i]);
        }

        vector<vector<int>> freq(nums.size()+1);  // vector<int> freq[nums.size()+1]

        for (int i = 0; i < nums.size(); i++){
            Node* p = myMap.table[i];
            while (p != nullptr){
                freq[p->data].emplace_back(p->key);
                p = p->pNext;
            }
        }

        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--){
            for (int n: freq[i]){
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
