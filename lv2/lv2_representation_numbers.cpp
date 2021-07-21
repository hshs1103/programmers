#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        int sum = i;
        
        for(int j = i+1; j <=n; j++){
            if(sum < n) sum += j;
            else break;
        }
        if(sum == n) answer++;
    }
    return answer;
}
