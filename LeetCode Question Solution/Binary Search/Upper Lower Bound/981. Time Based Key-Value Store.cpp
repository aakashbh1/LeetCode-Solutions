string get(string key, int timestamp) {
        if(mp2.find(key) == mp2.end()) return "";
        else {
            auto it = mp.upper_bound({key, timestamp});
            if (it == mp.begin()) return "";
            it--;
            return mp[it->first];
        }
    }
