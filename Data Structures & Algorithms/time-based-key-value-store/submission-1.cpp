class TimeMap {
public:
    unordered_map <string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        const vector<pair<int,string>>& v = mp[key];
        int s = 0;
        int e = v.size() - 1;
        string ans = "";
        while(s <= e){
            int mid = s + (e - s)/2;
            if(v[mid].first == timestamp){
                return v[mid].second;
            }
            else if (v[mid].first < timestamp){
                ans = v[mid].second;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    }
};
