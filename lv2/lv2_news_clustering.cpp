#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    vector<string> v1;
    for(int i =0; i< str1.size()-1; i++){
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            string tmp = str1.substr(i,2);
            v1.push_back(tmp);
        }
    }
    
    vector<string> v2;
    for(int i =0; i< str2.size()-1; i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            string tmp = str2.substr(i,2);
            v2.push_back(tmp);
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<string> in;
    in.resize(v1.size() + v2.size());
    auto itr = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), in.begin());
    in.erase(itr, in.end());
    
    vector<string> un;
    un.resize(v1.size() + v2.size());
    itr = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), un.begin());
    un.erase(itr, un.end());
    
    if(in.empty() && un.empty()) return 65536;
    else return 65536 * in.size() / un.size();

}
