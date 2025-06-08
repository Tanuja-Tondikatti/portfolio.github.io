#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1;

        // Move the accessed node to the front
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Key exists, update value and move to front
            cache.erase(map[key]);
        } else if (cache.size() == capacity) {
            // Remove least recently used element
            int lruKey = cache.back().first;
            map.erase(lruKey);
            cache.pop_back();
        }

        // Insert new pair at front
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }

    void display() {
        cout << "Cache state: ";
        for (auto& pair : cache)
            cout << "[" << pair.first << ":" << pair.second << "] ";
        cout << endl;
    }
};

// Sample usage
int main() {
    LRUCache lru(3);

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.display();

    cout << "Get 2: " << lru.get(2) << endl;
    lru.display();

    lru.put(4, 40); // This will evict key 1
    lru.display();

    cout << "Get 1: " << lru.get(1) << endl; // -1
    cout << "Get 3: " << lru.get(3) << endl;
    lru.display();

    return 0;
}
