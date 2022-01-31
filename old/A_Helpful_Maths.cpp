#include <iostream>
#include <unordered_map>

int main(){
    std::string a;
    std::cin>>a;
    std::unordered_map<char,int> nums;
    int slow=0;

    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]=='+') continue;
        else nums[a[i]]++;
    }

    int i=0;
    while(nums['1']){
        a[i] = '1';
        nums['1']--;
        i+=2;
    }
    while(nums['2']){
        a[i] = '2';
        nums['2']--;
        i+=2;
    }
    while(nums['3']){
        a[i] = '3';
        nums['3']--;
        i+=2;
    }
    

    std::cout<<a<<'\n';
    
}