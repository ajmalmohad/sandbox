#include <iostream>
#include <algorithm>

int main(){
    int n,k;
    std::cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
    int iter = k-1;
    if(arr[iter]==0){
        while(arr[iter]==0 && iter>-1) iter--;
        if(arr[iter]==0) iter=0;
    }else{
        while(arr[iter+1]==arr[iter]  && iter<n) iter++;
        if(iter==n) iter=n;
    }
    std::cout<<++iter;
}