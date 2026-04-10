class TimeMap {
public:
    unordered_map<string, map<int, string>> _map;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        _map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        //Upperbound is timestampe
        auto it = _map[key].upper_bound(timestamp);
        return it == _map[key].begin() ? "" : prev(it)->second;
    }
};
