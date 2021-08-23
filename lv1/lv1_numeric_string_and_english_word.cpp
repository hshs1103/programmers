#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    string tmp = "";
    string ans = "";
    map<string, int> m;
    
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    for(int i =0; i< s.size(); i++){
        if(isalpha(s[i])) {
            tmp += s[i];
            if(m.find(tmp) != m.end()){
                ans += to_string(m[tmp]);
                tmp = "";
            }
        }
        else {
            if(!tmp.empty()) ans += to_string(m[tmp]);
            ans += s[i];
            tmp = "";
        }
    }
    
    return stoi(ans);
}
