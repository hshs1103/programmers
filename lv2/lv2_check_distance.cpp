#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int xd[] = {-1,1,0,0};
int yd[] = {0,0,-1,1};

bool bfs(vector<vector<string>> places, vector<vector<int>> &d, int i, int j, int k){
    
    int min = 987654321;
    
    queue<pair<int, int>>q;
    q.push(make_pair(j, k));
    d[j][k] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int s =0; s< 4; s++){
            int xx = x + xd[s];
            int yy = y + yd[s];
            
            if(xx <0 || yy < 0 || xx >=5 || yy >= 5) continue;
            if(places[i][xx][yy] == 'X') continue;
            else {
                if(places[i][xx][yy] == 'O') {
                    if(d[xx][yy] > d[x][y] + 1){
                        d[xx][yy] = d[x][y] + 1;
                        q.push(make_pair(xx,yy));
                    }
                }
                if(places[i][xx][yy] == 'P') {
                    if(d[xx][yy] > d[x][y] + 1){
                        d[xx][yy] = d[x][y] + 1;
                        q.push(make_pair(xx,yy));
                        if(min > d[xx][yy]) min = d[xx][yy];
                    }
                }
            }
        }
    }
    
    if(min <= 2) return false;
    else return true;
}

bool check(vector<vector<string>> places, int i){
    
    for(int j =0; j < 5; j++){
        for(int k=0; k < 5; k++){
            if(places[i][j][k] == 'P'){
                vector<vector<int>> d(5, vector<int>(5, 987654321));
                bool valid = bfs(places, d, i, j, k);
                if(valid == false) return false;    
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i =0; i< places.size(); i++){
        bool valid = true;
        valid = check(places, i);
        if(valid == true) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
