class MyHashSet {
private:

    struct Node{
        int key;
        Node* pNext;
        Node(int x){
            key = x; 
            pNext =nullptr;
        }
    };

    int TABLE_SIZE;
    vector<Node*> table;

    int hashFunc(int key){
        return (key%TABLE_SIZE + TABLE_SIZE)%TABLE_SIZE;
    }

public:
    MyHashSet() {
        TABLE_SIZE = 10000;
        table.assign(TABLE_SIZE,nullptr);
    }
    
    void add(int key) {
        if (contains(key)) return;
        Node* newNode = new Node(key);
        int idx = hashFunc(key);
        newNode->pNext = table[idx];
        table[idx] = newNode;
    }
    
    void remove(int key) {
        int idx = hashFunc(key);

        Node* curr = table[idx];
        Node* prev = nullptr;
        while (curr != nullptr){
            if (curr->key == key){
                if (prev == nullptr){
                    table[idx] = curr->pNext;
                } else prev->pNext = curr->pNext;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->pNext;
        }
    }
    
    bool contains(int key) {
        int idx = hashFunc(key);
        Node* curr = table[idx];
        while (curr != nullptr){
            if (curr->key == key){
                return true;
            }
            curr = curr->pNext;
        }
        return false;
    }
};

/*
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */