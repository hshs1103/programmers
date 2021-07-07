#include <iostream>
#include <string>
#include <vector>

using namespace std;

int move(vector<vector<int>> &map, int i1, int j1, int i2, int j2){

    int cnt = j2 - j1;
    int buf1 = map[i1][j1], buf2 = 0;
    int min = map[i1][j1];
    int x_idx = i1;
    int y_idx = j1 + 1;
    
    while(cnt !=0){
        if(min > map[x_idx][y_idx]) min = map[x_idx][y_idx];
        buf2 = map[x_idx][y_idx];
        map[x_idx][y_idx] = buf1;
        buf1 = buf2;
        y_idx++;
        cnt--;
    }
    
    cnt = i2 - i1;
    y_idx--;
    x_idx++;
    
    while(cnt !=0){
        if(min > map[x_idx][y_idx]) min = map[x_idx][y_idx];
        buf2 = map[x_idx][y_idx];
        map[x_idx][y_idx] = buf1;
        buf1 = buf2;
        x_idx++;
        cnt--;
    }
    
    cnt = j2 - j1;
    x_idx--;
    y_idx--;
    while(cnt !=0){
        if(min > map[x_idx][y_idx]) min = map[x_idx][y_idx];
        buf2 = map[x_idx][y_idx];
        map[x_idx][y_idx] = buf1;
        buf1 = buf2;
        y_idx--;
        cnt--;
    }
    
    cnt = i2 - i1;
    y_idx++;
    x_idx--;
    
    while(cnt !=0){
        if(min > map[x_idx][y_idx]) min = map[x_idx][y_idx];
        buf2 = map[x_idx][y_idx];
        map[x_idx][y_idx] = buf1;
        buf1 = buf2;
        x_idx--;
        cnt--;
    }
    
    return min;
    
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows, vector<int> (columns, 0));
    int num = 1;
    
    for(int i =0; i< rows; i++){
        for(int j =0; j<columns; j++){
            map[i][j] = num;
            num++;
        }
    }

    for(int i =0; i< queries.size(); i++){
        int min = move(map, queries[i][0]-1, queries[i][1]-1, queries[i][2]-1, queries[i][3]-1);
        answer.push_back(min);
    }

    
    return answer;
}
