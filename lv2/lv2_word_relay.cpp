#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    set<string> s;
    s.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        set<string>::iterator itr;
        itr = s.find(words[i]);
        int len = words[i-1].size();
        if(itr != s.end() || words[i-1][len-1] != words[i][0]){
            answer.push_back(i%n +1);
            answer.push_back(i/n +1);
            return answer;
        }
        else s.insert(words[i]);
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
