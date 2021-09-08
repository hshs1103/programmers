#include <iostream>
#include <string>
#include <vector>

using namespace std;

char element[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string make_jinsu(int n, int m){
    string buf = "";
    
    while(m != 0){
        buf = element[m%n] + buf;
        m /= n;
    }
    return buf;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string word = "0";
    int cnt = 0;
    for(int i = 1; i <= t*m; i++) word += make_jinsu(n, i);
    
    for(int i = 0; i < word.size(); i++){
        if(cnt == t) break;
        
        if(i%m == p-1) {answer += word[i]; cnt++;}
    }
    
    return answer;
}
