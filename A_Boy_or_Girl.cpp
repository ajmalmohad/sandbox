#include <iostream>
#include <unordered_map>

int main(){
    std::string a;
    std::cin>>a;
    int count=0;
    std::unordered_map<char,int> record;
    for (int i = 0; i < a.size(); i++)
    {
        if(!record[a[i]]){
            record[a[i]]++;
            count++;
        };
    }
    if(!(count%2)){
        std::cout<<"CHAT WITH HER!";
    }else{
        std::cout<<"IGNORE HIM!";
    }
}