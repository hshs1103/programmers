#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    
    for(int i = 0; i < 26; i++){
        string buf = "";
        buf += 65 + i;
        m.insert(make_pair(buf, i+1));
    }
    
    int len = 1, num = 27;
    while(1){
        string w = msg.substr(0, len);
        string c = msg.substr(len, 1);
        string wc = w+c;
        
        if(m.find(w) != m.end()){
            if(m.find(wc) != m.end()){
                if(len < msg.size()) len++;
            }
            else {
                answer.push_back(m[w]);
                m.insert(make_pair(wc, num));
                num++;
                msg.erase(0, len);
                len = 1;
            }
        }
        
        if(c == "\0"){
            answer.push_back(m[w]);
            break;
        }
    }
    
    return answer;
}
