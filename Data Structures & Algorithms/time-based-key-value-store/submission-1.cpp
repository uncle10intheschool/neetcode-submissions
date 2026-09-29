class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> tMap;
    // {key , vec()<timestamp , value>}
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tMap[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        // check key exist
        auto it = tMap.find(key);
        if (it == tMap.end()) return "";
        const auto& vec = it->second; // tMap[key]
        // search timeStamp_prev max
        auto left = vec.begin();
        auto right = vec.end();
        while (left < right){
            auto mid = left + (right - left)/2;
            if ((*mid).first <= timestamp){
                left = mid + 1;
            } else right = mid; // > timestamp
        }
        if (right == vec.begin()) return "";
        return (*(right-1)).second;
    }
};

