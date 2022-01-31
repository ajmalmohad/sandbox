#include <iostream>

int main(){
    int n,i,temp,j,count;
    std::cin>>n;
    int solveable = 0;
    for (i = 0; i < n; i++)
    {
        count=0;
        for (j = 0; j < 3; j++)
        {
            std::cin>>temp;
            if(temp) count++;
        }
        if(count>1) solveable++;
    }
    std::cout<<solveable<<'\n';
}