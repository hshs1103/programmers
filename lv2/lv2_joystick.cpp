#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    vector<int> v(name.size(), 0);
    for(int i =0; i< name.size(); i++){
        if(name[i] < 'O') v[i] = name[i] - 'A';
        else v[i] = 'Z' - name[i] + 1;
        
        answer += v[i];
    }
    
    int move = name.size() - 1;
    int len = name.size();
    
     for (int i = 0; i < name.size(); ++i) {
        int a_pos = i + 1;
        while (a_pos < name.size() && name[a_pos] == 'A') a_pos++;
        move = min(move, 2*i + len - a_pos);
    }
    answer += move;
    return answer;
}
