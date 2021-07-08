#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int, vector<int>, less<>> pq;
    queue<pair<int, int>> q;
    
    for(int i =0; i<priorities.size(); i++){
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int pri = q.front().first;
        int loc = q.front().second;
        q.pop();
        
        if(pri == pq.top()){
            answer++;
            pq.pop();
            if(loc == location) break;
        }
        else {
            q.push(make_pair(pri, loc));
        }
    }
    return answer;
}
