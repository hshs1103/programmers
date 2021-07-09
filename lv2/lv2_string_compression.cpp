#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i =1; i<s.size(); i++){
        int len = 1;
        string tmp = s.substr(0,i);
        string tmp_ans;
        
        for(int j = i; j < s.size(); j += i){
            string comp = s.substr(j, i);
            
            if(comp == tmp) len++;
            else {
                if(len > 1) tmp_ans += to_string(len) + tmp;
                else tmp_ans += tmp;
                
                len = 1;
                tmp = s.substr(j,i);
            }
        }
        if(len > 1) tmp_ans += to_string(len) + tmp;
        else tmp_ans += tmp;
        
        if(answer > tmp_ans.size()) answer = tmp_ans.size();
        
    }
    
    return answer;
}
