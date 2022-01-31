#include <iostream>
#include <cmath>

int main(){
    int a,b,c;
    long long count;
    std::cin>>a>>b>>c;
    count = std::ceil((long double)a/c)*std::ceil((long double)b/c);
    std::cout<<count<<'\n';
}