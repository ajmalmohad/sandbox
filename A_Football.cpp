#include <iostream>

int main(){
    std::string a;
    std::cin>>a;
    int count = 1;
    char prev = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if(a[i]==prev) count++;
        else count=1;
        if(count>=7){
            std::cout<<"YES";
            return 0;
        }
        prev = a[i];
    }
    std::cout<<"NO";
}