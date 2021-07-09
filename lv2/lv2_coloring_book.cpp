#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xd[] = {-1, 1, 0 ,0};
int yd[] = {0, 0, -1, 1};

int bfs(vector<vector<int>> picture, vector<vector<bool>> &b, int m, int n, int i, int j){
    queue<pair<int ,int>> q;
    q.push(make_pair(i,j));
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        b[i][j] = true;
        q.pop();
        
        for(int i=0; i< 4; i++){
            int xx = x + xd[i];
            int yy = y + yd[i];
            
            if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
            if(picture[xx][yy] != picture[x][y] || b[xx][yy] == true) continue;
            else {
                q.push(make_pair(xx,yy));
                b[xx][yy] = true;
                cnt++;
            }
        }
    }
    
    return cnt;
    
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> b(m, vector<bool>(n, false));
    
    vector<int> answer(2);    
    vector<pair<int, int>> v;
    
    for(int i =0; i< m; i++){
        for(int j =0; j < n; j++){
            if(picture[i][j] != 0 && b[i][j] == false){
                int cnt = bfs(picture, b, m, n, i ,j);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
