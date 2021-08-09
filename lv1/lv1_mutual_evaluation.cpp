#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    vector<int> v;
    for(int i =0; i< scores.size(); i++){
        int self_score = scores[i][i], cnt = scores.size(), max_cnt = 0, min_cnt = 0, sum = 0;

        for(int j =0; j< scores[i].size(); j++){
            if(self_score < scores[j][i]) min_cnt++;
            if(self_score > scores[j][i]) max_cnt++;
            sum += scores[j][i];
        }
        
        if(max_cnt == (cnt-1) || min_cnt == (cnt-1)){
            cnt--;
            sum -= self_score;
        }
        
        v.push_back(sum/cnt);
        
    }
    
    for(int i =0; i<v.size(); i++){
        if(v[i] < 50) answer += "F";
        else if(50 <= v[i] && v[i] < 70) answer += "D";
        else if(70 <= v[i] && v[i] < 80) answer += "C";
        else if(80 <= v[i] && v[i] < 90) answer += "B";
        else answer += "A";
    }
    
    return answer;
}
