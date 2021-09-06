#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info{
    int number;
    int weight;
    double rate;
    int win_cnt;
} INFO;

bool compare(const INFO &i1, const INFO &i2){
    if(i1.rate == i2.rate){
        if(i1.win_cnt == i2.win_cnt) {
            if(i1.weight == i2.weight){
                return i1.number < i2.number;
            }
            else return i1.weight > i2.weight;
        }
        else return i1.win_cnt > i2.win_cnt;
    }
    else return i1.rate > i2.rate;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<INFO> v;
    
    for(int i = 0; i < weights.size(); i++){
        
        int w = weights[i], o_cnt = 0;
        double r;
        double w_cnt = 0, t_cnt = 0;

        for(int j = 0; j < head2head[i].size(); j++){
            if(i == j || head2head[i][j] == 'N') continue;
            
            if(head2head[i][j] == 'W'){
                if(weights[j] > w) o_cnt++;
                w_cnt++;
            }
            t_cnt++;
        }
        
        if(t_cnt != 0) r = w_cnt/t_cnt * 100;
        else r = 0;
        
        INFO info;
        info.number = i;
        info.weight = w;
        info.rate = r;
        info.win_cnt = o_cnt;
        
        v.push_back(info);
        
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < v.size(); i++) answer.push_back(v[i].number + 1);
    return answer;
}
