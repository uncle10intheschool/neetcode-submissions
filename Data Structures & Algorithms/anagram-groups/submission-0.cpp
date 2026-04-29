class Solution {
public:
    struct Node{
        string key;
        vector<string> group;
        Node* pNext;
        Node(string k, string d){
            key = k;
            group.push_back(d);
            pNext = nullptr;
        }
    };

    struct HashMap{
        int TABLE_SIZE;
        vector<Node*> table;
        int currSize;

        HashMap(int size){
            TABLE_SIZE = size;
            table.assign(TABLE_SIZE,nullptr);
            currSize = 0;
        }

        int hashFunc(const string& key){
            long long hashVal = 0;
            for (char c: key){
                hashVal = (hashVal*31 + c)%TABLE_SIZE;
            }
            return hashVal;
        }

        void rehash(){
            int oldSize = TABLE_SIZE;
            vector<Node*> oldTable = table;
            currSize  = 0;
            TABLE_SIZE *= 2;
            table.assign(TABLE_SIZE,nullptr);

            for (int i = 0; i < oldSize; i++){
                Node* curr = oldTable[i];
                while (curr != nullptr){
                    Node* next = curr->pNext;
                    int idx = hashFunc(curr->key);
                    curr->pNext = table[idx];
                    table[idx] = curr;
                    curr = next;
                    currSize++;
                }
            }
        }

        void add(const string &key, const string& data){
            double factor = (double)currSize/TABLE_SIZE;
            if (factor >= 0.75) rehash();
            
            int idx = hashFunc(key);
            Node* p = table[idx];
            while (p != nullptr){
                if (p->key == key){
                    p->group.push_back(data);
                    return;
                }
                p = p->pNext;
            }

            Node* newNode = new Node(key,data);
            newNode->pNext = table[idx];
            table[idx] = newNode;
            currSize++;
        }

        ~HashMap(){
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

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        if (strs.empty()) return {};
        int firstSize = max(10,(int)strs.size());
        HashMap myMap(firstSize);

        for (string &s: strs){
            string key = s;
            sort(key.begin(), key.end());
            myMap.add(key,s);
        }

        vector<vector<string>> res;
        for (int i = 0; i < myMap.TABLE_SIZE; i++){
            Node* curr = myMap.table[i];
            while (curr != nullptr){
                res.emplace_back(curr->group);
                curr = curr->pNext;
            }
        }
        return res;
    }
};
