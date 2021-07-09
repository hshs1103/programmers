#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer(1,1);
    vector<int> day;
    
    for(int i =0; i < progresses.size(); i++ ){
        int total = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) total++;
        day.push_back(total);
    }
    
    int d = day[0];
    for(int i =1; i < day.size(); i++ ){
        if(d >= day[i]) answer.back()++;
        else {
            d = day[i];
            answer.push_back(1);
        }
    }
    return answer;
}
