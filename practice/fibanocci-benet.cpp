#include <iostream>
#include <cmath>

using namespace std;

int64_t fib(int N) {
        double phi = (sqrt(5) + 1) / 2;     
        return (int64_t)round((int64_t)pow(phi, N) / sqrt(5));
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
}