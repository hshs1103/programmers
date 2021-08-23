#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int max_score = 0;
    map<string, vector<pair<string, int>>> m;
    for(int i = 0; i < table.size(); i++){
        istringstream ss(table[i]);
        string buf;
        getline(ss, buf, ' ');
        string job_group = buf;
        int score = 5;
        vector<pair<string, int>> tmp_v;
        
        while(getline(ss, buf, ' ')){
            tmp_v.push_back(make_pair(buf, score));
            score--;
        }
        
        m.insert(make_pair(job_group, tmp_v));
        
    }
    
    vector<pair<string, int>> v;
    
    for(auto itr = m.begin(); itr != m.end(); itr++){
        int total_score = 0;
        string job = itr->first;
        
        for(int i = 0; i < languages.size(); i++){
            int tmp_score = 0;
            for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++){
                if(languages[i] == itr2->first){
                    tmp_score = itr2->second;
                }
            }
            if(tmp_score != 0){
                total_score += (preference[i] * tmp_score);
            }
            else total_score += 0;
        }
        
        if(max_score < total_score){
            max_score = total_score;
            answer = job;
        }
    }
    
    return answer;
}
