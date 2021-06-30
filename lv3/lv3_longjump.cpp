#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    if(n == 1) return 1;
    else if(n == 2) return 2;
    
    long long answer = 0;
    vector<long long> v; v.push_back(1); v.push_back(2);
    for(int i = 2; i < n; i++){
        int num = v[i-1] + v[i-2];
        v.push_back(num%1234567);
    }
    
    return v[n-1];
}
