#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, max_idx = people.size(), min_idx = 0;
    sort(people.begin(), people.end());
    
    while(min_idx < max_idx){
        int heavy = people.back();
        people.pop_back();
        
        if(heavy + people[min_idx] <= limit){
            max_idx--;
            min_idx++;
        }
        else max_idx--;
        answer++;
    }
    return answer;
}
