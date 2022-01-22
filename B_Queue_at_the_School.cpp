#include <iostream>
#include <vector>

int main(){
    int n,x;
    std::cin>>n>>x;
    std::string queue;
    std::cin>>queue;
    for (int j = 0; j < x; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if(queue[i]=='B' && queue[i+1]){
                std::swap(queue[i],queue[i+1]);
                if(queue[i+1]!=queue[i]) i++;
            }
        }
    }
    std::cout<<queue;
}