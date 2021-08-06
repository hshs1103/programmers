#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

void dfs(vector<int> &answer, int x, int y, int size){
    if(size == 0) return;
    
    int zero = 0, one = 0;
    for(int i = x; i < x+size; i++){
        for(int j = y; j < y+size; j++){
            if(board[i][j] == 0) zero++;
            else one++;
        }
    }
    
    if(size*size == zero){
        answer[0]++;
        return;
    }
    else if(size*size == one){
        answer[1]++;
        return;
    }
    
    dfs(answer, x, y, size/2);
    dfs(answer, x+size/2, y, size/2);
    dfs(answer, x, y+size/2, size/2);
    dfs(answer, x+size/2, y+size/2, size/2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    board = arr;
    dfs(answer, 0, 0, arr.size());
    return answer;
}
