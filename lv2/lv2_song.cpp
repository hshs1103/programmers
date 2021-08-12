#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <algorithm>

using namespace std;

string make_melody(string m, int repeat, int remain){
    string tmp;
    for(int i =0; i< repeat; i++) tmp += m;
    tmp += m.substr(0, remain);
    
    return tmp;
}

string change_melody(string m){
    
    string tmp;
    for(int i = 0; i < m.size(); i++){
        if(m[i] == '#') continue;
        if(m[i+1] == '#') tmp += m[i] + 32;
        else tmp += m[i];
    }
    
    return tmp;
}

bool compare(tuple<string, int, int> &v1, tuple<string, int, int> &v2){
    int t1 = get<1>(v1);
    int t2 = get<1>(v2);
    
    int o1 = get<2>(v1);
    int o2 = get<2>(v2);
    
    if(t1 < t2) return t1 > t2;
    else if(t1 == t2) return o1 < o2;
    else return t1 > t2;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    string listen_melody = change_melody(m);
    
    vector<tuple<string, int, int>> v;
    for(int i = 0; i < musicinfos.size(); i++){
        istringstream ss(musicinfos[i]);
        string buf;
        
        getline(ss, buf, ':');
        int start_hour = stoi(buf);
        
        getline(ss, buf, ',');
        int start_min = stoi(buf);
        
        getline(ss, buf, ':');
        int end_hour = stoi(buf);
        
        getline(ss, buf, ',');
        int end_min = stoi(buf);
        
        getline(ss, buf, ',');
        string name = buf;
        
        getline(ss, buf, ',');
        string melody = change_melody(buf);
        
        int time = (end_hour - start_hour) * 60 + (end_min - start_min);
        
        int repeat = time / melody.size();
        int remain = time % melody.size();
        
        string full_melody = make_melody(melody, repeat, remain);
        
        if(full_melody.find(listen_melody) != string::npos) v.push_back(make_tuple(name, time, i));
    }
    
    sort(v.begin(), v.end(), compare);
    
    if(v.empty()) return "(None)";
    else return get<0>(v[0]);
}
