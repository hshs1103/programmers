#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> v;
    string buf = "";
    for(int i = 2; i< s.size()-1; i++){
        if(isdigit(s[i])) buf += s[i];
        else {
            if(!buf.empty()) {
                v.push_back(stoi(buf));
                buf = ""; 
            }
        }
    }
    
    sort(v.begin(), v.end());
    vector<pair<int, int>> cnt;
    
    for(int i =0; i < v.size(); i++){
        if(cnt.empty()) cnt.push_back(make_pair(v[i], 1));
        else {
            if(cnt.back().first == v[i]) cnt.back().second++;
            else cnt.push_back(make_pair(v[i], 1));
        }
    }
    
    sort(cnt.begin(), cnt.end(), compare);
    
    for(int i =0; i < cnt.size(); i++) answer.push_back(cnt[i].first);
    
    return answer;
}
