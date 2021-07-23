#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck;
    queue<int> bridge;
    int sum = 0, idx = 0;
    
    while(1){
        if(truck.size() == truck_weights.size()) break;
        
        if(bridge.size() == bridge_length){
            if(bridge.front() != 0){
                sum -= bridge.front();
                truck.push(bridge.front());
                bridge.pop();
            } else {
                bridge.pop();
            }
        } 
        
        if(sum + truck_weights[idx] <= weight) {
            sum += truck_weights[idx];
            bridge.push(truck_weights[idx]);
            idx++;
        }
        else {
            bridge.push(0);
        }
        answer++;
    }
    return answer;
}
