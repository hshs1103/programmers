#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int big = a > b ? a : b;
    int small = a > b ? b : a;
    
    while(small != 0){
        int nmg = big % small;
        big = small;
        small = nmg;
    }
    return big;
}

int lcm(int a, int b){
    return a/gcd(a,b) * b/gcd(a,b) * gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i = 0; i < arr.size(); i++) answer = lcm(answer, arr[i]);
    
    return answer;
}
