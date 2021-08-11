#include <iostream>
#include <string>
using namespace std;

typedef struct move {
    bool up;
    bool down;
    bool left;
    bool right;
} Move;

int solution(string dirs) {
    int answer = 0, x = 5, y = 5;
    Move map[11][11] = {false, };
    
    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i] == 'U'){
            if(y != 10){
                if(map[x][y+1].down == false){
                    map[x][y].up = true;
                    map[x][y+1].down = true;
                    answer++;
                }
                y++;
            }
        }
        else if(dirs[i] == 'D'){
            if(y != 0){
                if(map[x][y-1].up == false){
                    map[x][y].down = true;
                    map[x][y-1].up = true;
                    answer++;
                }
                y--;
            }
        }
        else if(dirs[i] == 'L'){
            if(x != 0){
                if(map[x-1][y].right == false){
                    map[x][y].left = true;
                    map[x-1][y].right = true;
                    answer++;
                }
                x--;
            }
        }
        else {
            if(x != 10){
                if(map[x+1][y].left == false){
                    map[x][y].right = true;
                    map[x+1][y].left = true;
                    answer++;
                }
                x++;
            }
        }
    }
    return answer;
}
