#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    vector<int> v;
    int row = relation.size(), col = relation[0].size();
    
    for(int i =1; i< (1<<col); i++){
        set<string> s;
        for(int j=0; j < row; j++){
            string candidate = "";
            for(int k = 0; k < col; k++){
                if(i & (1<<k)) candidate += relation[j][k];
            }
            s.insert(candidate);
        }
        
        if(s.size() == row){
            bool valid = true;
            
            for(int l=0; l < v.size(); l++){
                if((i & v[l]) == v[l]) valid = false;
            }
            if(valid == true) v.push_back(i);
        }
    }
    
    return v.size();
}
