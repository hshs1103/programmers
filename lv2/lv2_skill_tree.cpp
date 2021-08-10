#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i < skill_trees.size(); i++){
        int skill_len = skill_trees[i].size(), level = 0;
        bool valid = true;
        
        for(int j=0; j < skill_len; j++){
            if(valid == false) break;
            for(int k=0; k < skill.size(); k++){
                if(skill[k] == skill_trees[i][j]){
                    if(k > level){
                        valid = false;
                        break;
                    }
                    level++;
                }
            }
        }
        if(valid == true) answer++;
        
    }
    
    return answer;
}
