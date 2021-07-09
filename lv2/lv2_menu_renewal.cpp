#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void put_answer(vector<string> &answer, map<string, int> m, int num){
    map<string, int> :: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        if(num == itr->second) answer.push_back(itr->first);
    }
}

int find_max(map<string, int> m){
    map<string, int> :: iterator itr;
    int max_num = 0;
    for(itr = m.begin(); itr != m.end(); itr++){
        if(max_num < itr->second) max_num = itr->second;
    }
    return max_num;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i =0; i< course.size(); i++){
        map<string, int> m;
        for(int j=0; j < orders.size(); j++){
            if(orders[j].size() >= course[i]) {
                
                sort(orders[j].begin(), orders[j].end());
                vector<bool> b(orders[j].size() - course[i], false);
                b.insert(b.end(), course[i], true);
                
                do {
                    string tmp;
                    for(int k=0; k < b.size(); k++){
                        if(b[k] == true) tmp += orders[j][k];
                    }
                    
                    if(m.find(tmp) != m.end()) m[tmp]++;
                    else m.insert(make_pair(tmp, 1));
                } while(next_permutation(b.begin(), b.end()));
            }
        }
        
        int max_num = find_max(m);
        if(max_num < 2) continue;
        else put_answer(answer, m, max_num);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
