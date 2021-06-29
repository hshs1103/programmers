#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>> &ans, int start ,int dest, int n){
    if(n == 1) {
        ans.push_back({start, dest});
        return;
    }
    
    hanoi(ans, start, 6 - start - dest, n-1);
    ans.push_back({start, dest});
    hanoi(ans, 6 - start - dest, dest, n-1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, 1, 3, n);
    return answer;
}
