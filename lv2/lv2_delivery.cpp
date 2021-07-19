#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> v(N+1);
    vector<int> dist(N+1, 987654321);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i =0; i< road.size(); i++){
        v[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }
    
    dist[1] = 0;
    pq.push(make_pair(1,0));
    
    while(!pq.empty()){
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        for(int i =0; i< v[node].size(); i++){
            int next_node = v[node][i].first;
            int next_cost = v[node][i].second;
            
            if(dist[next_node] > dist[node] + next_cost){
                dist[next_node] = dist[node] + next_cost;
                pq.push(make_pair(next_node, next_cost));
            }
        }
    }
    
    for(int i = 0; i<dist.size(); i++){
        if(dist[i] <= K) answer++;
    }
    return answer;
}
