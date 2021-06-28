#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string member = "ACFJMNRT";
    
    do{
        bool valid = true;
        
        for(int i =0; i< data.size(); i++){
            char m1 = data[i][0];
            char m2 = data[i][2];
            char c = data[i][3];
            int d = data[i][4] - '0';
            int md = member.find(m1) - member.find(m2);
            md = abs(md) - 1;
            
            if(c == '>'){
                if(md <= d) valid = false;
            }
            else if(c == '<'){
                if(md >= d) valid = false;
            }
            else {
                if(md != d) valid = false;
            }
        }
        if(valid == true) answer++;
        
    } while(next_permutation(member.begin(), member.end()));
    return answer;
}
