#include <iostream>

int main(){
    int limak,bob;
    std::cin>>limak;
    std::cin>>bob;
    int year = 0;
    while (limak<=bob)
    {
        year++;
        limak = limak*3;
        bob = bob*2;
    }
    std::cout<<year<<'\n';
}