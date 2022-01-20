#include <iostream>

int main(){
    int n;
    std::cin>>n;
    char prev,temp;
    int count = 0;
    std::cin>>prev;
    for (int i = 1; i < n; i++)
    {
        std::cin>>temp;
        if(prev==temp) count++;
        prev = temp;
    }
    std::cout<<count;
}