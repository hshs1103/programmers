#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

void check(vector<vector<char>> v, vector<vector<bool>> &b, int i, int j, bool &valid){
    if(v[i][j] == v[i+1][j] && v[i][j] == v[i+1][j+1]){
        b[i][j] = true;
        b[i+1][j] = true;
        b[i][j+1] = true;
        b[i+1][j+1] = true;
        valid = false;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<char>> v;
    for(int i=0; i < m; i++){
        vector<char> tmp;
        for(int j =0; j < n; j++){
            tmp.push_back(board[i][j]);
        }
        v.push_back(tmp);
    }
    
    while(1){
        bool is_end = true;
        vector<vector<bool>> b(m, vector<bool>(n, false));
        for(int i=0; i < m-1; i++){
            for(int j =0; j <n-1; j++){
                if(v[i][j] != '-' && v[i][j] == v[i][j+1]){
                    check(v, b, i,j,is_end);
                }
            }
        }
        
        if(is_end == true) break;
        
        set<int> s;
        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(b[i][j] == true){
                    v[i][j] = '-';
                    answer++;
                    s.insert(j);
                }
            }
        }
        
        set<int>::iterator itr;
        for(itr = s.begin(); itr != s.end(); itr++){
            stack<char> st;
            for(int i=0; i < m; i++){
                if(v[i][*itr] != '-') st.push(v[i][*itr]);
            }
            
            for(int i=m-1; i >= 0; i--){
                if(!st.empty()) {
                    v[i][*itr] = st.top();
                    st.pop();
                }
                else v[i][*itr] = '-';
            }
        }
        
    }
    return answer;
}
