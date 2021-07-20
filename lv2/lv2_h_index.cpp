#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater());
    for(int i =0; i < citations.size(); i++) {
        if(i + 1 <= citations[i]) answer += 1;
        else break;
    }
    return answer;
}
