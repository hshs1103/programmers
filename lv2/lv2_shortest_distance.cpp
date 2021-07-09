#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xd[] = {-1,1,0,0};
int yd[] = {0,0,-1,1};



int solution(vector<vector<int> > maps)
{

    vector<vector<bool>> b(maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> d(maps.size(), vector<int>(maps[0].size(), 987654321));
    
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    d[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x + xd[i];
            int yy = y + yd[i];
            
            if(xx <0 || yy<0 || xx >= maps.size() || yy >= maps[0].size()) continue;
            if(maps[xx][yy] == 0) continue;
            else {
                if(d[xx][yy] > d[x][y] + 1){
                    d[xx][yy] = d[x][y] + 1;
                    b[xx][yy] = true;
                    q.push(make_pair(xx,yy));
                }
            }
        }
    }
    
    if(b[maps.size()-1][maps[0].size()-1] == false) return -1;
    else return d[maps.size()-1][maps[0].size()-1];

}
