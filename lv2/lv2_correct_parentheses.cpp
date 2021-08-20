#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    
    if(!st.empty()) return false;

    return answer;
}
