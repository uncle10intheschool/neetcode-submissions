struct Node{
    unordered_map<char,Node*> children;
    bool endOfWord;
    Node(){endOfWord = false;}
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string w){
        Node* curr = root;
        for (char c : w){
            if (curr->children.find(c) == curr->children.end()){
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }

    string LCP(){
        Node* curr = root;
        string prefix = "";
        while (curr->children.size() == 1 && !curr->endOfWord){
            auto child = curr->children.begin();
            char c = child->first;
            prefix += c;
            curr = child->second;
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        Trie t;
        for (const auto& s : strs){
            if (s.empty()) return "";
            t.insert(s);
        }

        return t.LCP();
    }
};