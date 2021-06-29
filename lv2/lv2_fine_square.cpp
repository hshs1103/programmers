#include <iostream>
using namespace std;

int gcd(int a, int b){
    int small = (a > b) ? small = b : small = a;
    int big = (a > b) ? big = a : big = b;
    
    while(small != 0){
        int nmg = big % small;
        big = small;
        small = nmg;
    }
    
    return big;
}


long long solution(int w,int h) {
    long long answer = 1;
    return ((long long)w * h - ((long long)w + h - gcd(w,h)));
}
