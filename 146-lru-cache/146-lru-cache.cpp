class LRUCache {
public:
    int capacity;
    list<pair<int,int>> pageList;
    unordered_map<int,list<pair<int,int>> ::iterator> pageMap;
    LRUCache(int size) {
        capacity=size;
    }
    
    int get(int key) {
        auto itr=pageMap.find(key);
        if(itr==pageMap.end()){
            return -1;
        }
        int value=itr->second->second;
        pageList.erase(itr->second);
        pageList.push_front({key,value});
        pageMap[key]=pageList.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto itr=pageMap.find(key);
        if(itr!=pageMap.end()){
            pageList.erase(itr->second);
        }
        else if(pageMap.size()==capacity){
            pageMap.erase(pageList.back().first);
            pageList.pop_back();
        }
        pageList.push_front({key,value});
        pageMap[key]=pageList.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */