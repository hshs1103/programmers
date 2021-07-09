#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int, vector<int>, less<>> pq(works.begin(), works.end());
    
    while(n > 0){
        if(pq.empty()) return 0;
        int max = pq.top();
        pq.pop();
        max--;
        if(max > 0) pq.push(max);
        n--;
    }
    
    while(!pq.empty()){
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}
