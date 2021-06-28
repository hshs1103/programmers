#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i =0; i< scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        if(pq.top() >= K) break;
        else if(pq.size() == 1) return -1;
        else {
            int min1 = pq.top();
            pq.pop();
            int min2 = pq.top();
            pq.pop();
            
            int new_min = min1 + min2 * 2;
            pq.push(new_min);
            answer++;
        }
    }
    
    return answer;
}
