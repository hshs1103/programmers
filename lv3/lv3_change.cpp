#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> v(n+1, 0);
    
    for(int i = 0; i <= n; i++){
        if(i% money[0] == 0) v[i] = 1;
    }
    
    for(int i = 1; i < money.size(); i++){
        for(int j = money[i]; j <= n; j++){
            v[j] += v[j-money[i]] % 1000000007;
        }
    }
    
    return v[n];
}
