#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    istringstream ss(s);
    string buf;
    
    while(getline(ss, buf, ' ')) v.push_back(stoi(buf));
    
    int max_num = *max_element(v.begin(), v.end());
    int min_num = *min_element(v.begin(), v.end());
    
    answer += to_string(min_num) + " " + to_string(max_num);
    return answer;
}
