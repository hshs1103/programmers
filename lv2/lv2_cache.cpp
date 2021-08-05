#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string evict(map<string, int> &m){
    int time = 0;
    string city = "";
    map<string, int>:: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        if(time < itr->second){
            time = itr->second;
            city = itr->first;
        }
    }
    
    return city;
}

void inc_lru(map<string, int> &m){
    map<string, int>:: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        itr->second++;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    map<string, int> cache;
    
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        if(cacheSize == 0){
            answer += 5;
            continue;
        }
        
        map<string, int>:: iterator itr;
        itr = cache.find(cities[i]);
        inc_lru(cache);
        if(itr != cache.end()){
            itr->second = 1;
            answer += 1;
        }
        else {
            if(cache.size() >= cacheSize){
                string old = evict(cache);
                cache.erase(old);
            }
            cache.insert(make_pair(cities[i], 1));
            answer += 5;
        }
    }
    return answer;
}
