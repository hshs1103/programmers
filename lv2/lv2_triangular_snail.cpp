#include <iostream>
#include <string>
#include <vector>

int num = 1;
int N;

using namespace std;

void triangle(vector<int> &answer, int start, int inc, int bottom, int k){
    if(bottom == 1){
        answer[start] = num;
        return;
    }
    
    int idx = start;
    for(int i =0; i< bottom -1; i++){
        answer[idx] = num++;
        idx += inc++;
    }
    
    for(int i =0; i<bottom; i++){
        answer[idx++] = num++;
    }
    
    idx--;
    int dec = N - k;
    for(int i =0; i<bottom-2; i++){
        idx -= dec--;
        answer[idx] = num++;
    }
}

vector<int> solution(int n) {
    int total = (n * (n+1)) /2;
    N = n;
    int k =0;
    vector<int> answer(total, 0);
    
    while(n >= 1){
        triangle(answer, 2*k*(k+1), 2*k+1, n, k);
        n-=3;
        k++;
    }
    return answer;
}
