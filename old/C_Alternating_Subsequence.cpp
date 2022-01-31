#include <iostream>


int max(int a, int b){
    return (a>=b)?a:b;
}

void solve(){
    int n, prevcounted, negative=INT_MIN, positive=0;
    long long sum=0;
    std::cin>>n;
    int arr[n];
    
    for (int i = 0; i < n; i++) std::cin>>arr[i];

    if(arr[0]>0){
        positive = arr[0];
        prevcounted = 1;
    }else{
        negative = arr[0];
        prevcounted = -1;
    }

    for (int i = 0; i < n; i++){
        if(arr[i]<0){
            if(prevcounted == -1){
                negative = max(negative,arr[i]);
            }else{
                sum+=positive;
                positive=0;
                prevcounted = -1;
                negative = max(negative,arr[i]);
            }
        }else{
            if(prevcounted == 1){
                positive = max(positive,arr[i]);
            }else{
                sum+=negative;
                negative=INT_MIN;
                prevcounted = 1;
                positive = max(positive,arr[i]);
            }
        }
    }

    if(arr[n-1]<0) sum+=negative;
    else sum+= positive;

    std::cout<<sum<<'\n';
}

int main(){
    int t=1;
    std::cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}