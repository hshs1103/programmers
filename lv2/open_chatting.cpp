#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>> d;
    
    for(int i =0; i< record.size(); i++){
        istringstream ss(record[i]);
        string buf;
        vector<string> tmp_v;
        while(getline(ss, buf, ' ')){
            tmp_v.push_back(buf);
        }
        d.push_back(tmp_v);
        if(d[i][0] == "Enter"){
            if(m.find(d[i][1]) != m.end()){
                m[d[i][1]] = d[i][2];
            } else {
                m.insert(make_pair(d[i][1], d[i][2]));
            }
        }
        else if(d[i][0] == "Change"){
            m[d[i][1]] = d[i][2];
        }
    }
    
    for(int i=0; i<d.size(); i++){
        if(d[i][0] == "Enter"){
            string r = m[d[i][1]] + "님이 들어왔습니다.";
            answer.push_back(r);
        }
        else if(d[i][0] == "Leave"){
            string r = m[d[i][1]] + "님이 나갔습니다.";
            answer.push_back(r);
        }
    }
    
    return answer;
}
