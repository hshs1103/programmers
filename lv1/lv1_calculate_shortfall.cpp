#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long total_price = 0;
    for(int i =1; i <= count; i++) total_price += (price * i);
    
    return total_price <= money ? 0 : total_price - money;
}
