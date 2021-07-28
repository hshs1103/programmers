#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> data[3][2][2][2];
    
    for(int i =0; i< info.size(); i++){
        istringstream ss(info[i]);
        string buf;
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0, score = 0;
        
        getline(ss, buf, ' ');
        if(buf == "cpp") i1 = 0; else if(buf == "java") i1 = 1; else i1 = 2;
        
        getline(ss, buf, ' ');
        if(buf == "backend") i2 = 0; else i2 = 1;
        
        getline(ss, buf, ' ');
        if(buf == "junior") i3 = 0; else i3 = 1;
        
        getline(ss, buf, ' ');
        if(buf == "chicken") i4 = 0; else i4 = 1;
       
        getline(ss, buf, ' ');
        score = stoi(buf);
        
        data[i1][i2][i3][i4].push_back(score);
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    sort(data[i][j][k][l].begin(), data[i][j][k][l].end());
                }
            }
        }
    }
    
    for(int i =0; i< query.size(); i++){
        istringstream ss(query[i]);
        string buf;
        int q1 = 0, q2 = 0, q3 = 0, q4 = 0, score = 0, cnt = 0;
        
        getline(ss, buf, ' ');
        if(buf == "cpp") q1 = 0; else if(buf == "java") q1 = 1; else if(buf == "python") q1 = 2; else q1 = -1;
        
        getline(ss, buf, ' '); getline(ss, buf, ' ');
        if(buf == "backend") q2 = 0; else if(buf == "frontend") q2 = 1; else q2 = -1;
        
        getline(ss, buf, ' '); getline(ss, buf, ' ');
        if(buf == "junior") q3 = 0; else if(buf == "senior") q3 = 1; else q3 = -1;
        
        getline(ss, buf, ' '); getline(ss, buf, ' ');
        if(buf == "chicken") q4 = 0; else if(buf == "pizza") q4 = 1; else q4 = -1;
       
        getline(ss, buf, ' ');
        if(buf == "-") score = -1; else score = stoi(buf);
        
        for(int i = 0; i < 3; i++){
            if(q1 != -1 && q1 != i) continue;
            for(int j = 0; j < 2; j++){
                if(q2 != -1 && q2 != j) continue;
                for(int k = 0; k < 2; k++){
                    if(q3 != -1 && q3 != k) continue;
                    for(int l = 0; l < 2; l++){
                        if(q4 != -1 && q4 != l) continue;
                        
                        auto itr = lower_bound(data[i][j][k][l].begin(), data[i][j][k][l].end(), score);
                        for(; itr != data[i][j][k][l].end(); itr++) cnt++;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
