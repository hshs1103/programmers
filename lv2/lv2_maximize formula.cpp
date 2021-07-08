#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> number;
    vector<char> op;
    string buf = "";
    
    for(int i =0; i< expression.size(); i++){
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
            number.push_back(stoi(buf));
            buf = "";
            op.push_back(expression[i]);
        }
        else buf += expression[i];
    }
    number.push_back(stoi(buf));
    
    string op_list = "-+*";
    sort(op_list.begin(), op_list.end());
    
    do {
        vector<long long> t_number = number;
        vector<char> t_op = op;
        
        for(int i =0; i< op_list.size(); i++){
            for(int j =0; j < t_op.size();){
                if(op_list[i] == t_op[j]){
                    long long cal;
                    if(t_op[j] == '-'){
                        cal = t_number[j] - t_number[j+1];
                    }
                    else if(t_op[j] == '+'){
                        cal = t_number[j] + t_number[j+1];
                    }
                    else{
                        cal = t_number[j] * t_number[j+1];
                    }
                    
                    t_number.erase(t_number.begin() + j);
                    t_number.erase(t_number.begin() + j);
                    t_number.insert(t_number.begin() + j, cal);
                    
                    t_op.erase(t_op.begin() + j);
                }
                else j++;
            }
        }
        
        answer = max(answer, abs(t_number[0]));
    } while(next_permutation(op_list.begin(), op_list.end()));
    
    return answer;
}
