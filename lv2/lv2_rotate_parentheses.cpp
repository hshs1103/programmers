#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i =0; i< s.size(); i++){
        string tmp ="";
        tmp = s.substr(i, s.size() - i);
        tmp += s.substr(0,i);
        bool valid = true;
        
        stack<char> st;
        for(int j =0; j < tmp.size(); j++){
            if(tmp[j] == '[' || tmp[j] == '{' || tmp[j] == '(') st.push(tmp[j]);
            else {
                if(tmp[j] == ']'){
                    if(st.empty() || st.top() != '[') {
                        valid = false;
                        break;
                    } else st.pop();
                }
                else if(tmp[j] == '}'){
                    if(st.empty() || st.top() != '{') {
                        valid = false;
                        break;
                    } else st.pop();
                }
                else {
                    if(st.empty() || st.top() != '(') {
                        valid = false;
                        break;
                    } else st.pop();
                }
            }
            
        }
        if(valid == true && st.empty()) answer++;
    }
    return answer;
}
