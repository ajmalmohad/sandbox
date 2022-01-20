#include <iostream>

int main(){
    std::string a;
    std::cin>> a;
    a[0] = std::toupper(a[0]);
    std::cout<<a<<'\n';
}