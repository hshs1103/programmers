#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void make_word(vector<string> &v, vector<string> c, int len, string w){
    v.push_back(w);
    for(int i = 0; i < c.size(); i++){
        if(len < 5) make_word(v, c, len+1, w + c[i]);
    }
}

int solution(string word) {
    
    vector<string> c = {"A", "E", "I", "O", "U"};
    vector<string> s;
    make_word(s, c, 0, "");
    
    for(int i = 0; i < s.size(); i++) {
        if(word == s[i]) return i;
    }
}
