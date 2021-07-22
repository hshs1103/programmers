#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int garo = 0, sero = 0;
    
    for(int i = brown + yellow; i >0; i--){
        garo = i;
        sero = total/garo;
        if(total % garo == 0 && garo >= sero){
            if((garo - 2) * (sero - 2) == yellow && 2*(garo + sero) - 4 == brown){
                answer.push_back(garo);
                answer.push_back(sero);
            }
        }        
    }
    return answer;
}
