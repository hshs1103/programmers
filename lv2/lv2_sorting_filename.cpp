#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct file{
    string original_name, head;
    int number, order;
}ff;

int find_head_idx(string file){
    for(int i = 0; i < file.size(); i++){
        if(isdigit(file[i])) return i;
    }
}

int find_num_idx(string file){
    for(int i = 0; i < file.size(); i++){
        if(!isdigit(file[i])) return i;
    }
    
    return 5;
}

bool compare(const file &f1, const file &f2){
    if(f1.head == f2.head){
        if(f1.number == f2.number) return f1.order < f2.order;
        else return f1.number < f2.number;
    }
    else return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<ff> v;
    
    for(int i = 0; i < files.size(); i++){
        string file_name = files[i];
        
        int head_idx = find_head_idx(file_name);
        string head = file_name.substr(0, head_idx);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        file_name.erase(0, head_idx);
        
        int number_idx = find_num_idx(file_name);
        int number = stoi(file_name.substr(0, number_idx));
        
        ff f;
        f.original_name = files[i];
        f.head = head;
        f.number = number;
        f.order = i;
        
        v.push_back(f);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < v.size(); i++) answer.push_back(v[i].original_name);
    return answer;
}
