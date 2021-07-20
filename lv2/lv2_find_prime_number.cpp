#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater());
    int max_num = stoi(numbers);
    
    vector<bool> sosu(max_num, true);
    for(int i =2; i<= sqrt(max_num); i++){
        if(sosu[i] == true){
            for(int j = i*i; j <= max_num; j +=i){
                sosu[j] = false;
            }
        }
    }
    
    sort(numbers.begin(), numbers.end());
    vector<int> num;
    vector<char> c;
    
    for(int i =0; i< numbers.size(); i++) c.push_back(numbers[i]);
    do {
        string tmp = "";
        for(int i =0; i< c.size(); i++){
            tmp += c[i];
            num.push_back(stoi(tmp));
        }
    } while(next_permutation(c.begin(), c.end()));
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    for(int i =0; i< num.size(); i++) {
        if(num[i] > 1 && sosu[num[i]] == true) answer++;
    }
    
    return answer;
}
