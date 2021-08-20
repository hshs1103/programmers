#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_jinsu(int n){
    string buf = "";
    while(n != 0){
        buf = to_string(n%2) + buf;
        n /= 2;
    }
    
    return buf;
}

int count_one(string s){
    int one = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') one++;
    }
    return one;
}

int solution(int n) {
    int answer = 0;
    int one = count_one(make_jinsu(n));
    
    for(int i = n+1; ; i++){
        int cnt = count_one(make_jinsu(i));
        if(cnt == one) return i;
    }
    
    return answer;
}
