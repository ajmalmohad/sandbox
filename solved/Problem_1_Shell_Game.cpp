#include <iostream>
using namespace std;

int main() {
	// freopen("shell.in", "r", stdin);
	// freopen("shell.out", "w", stdout);
	int arr[4] = {0, 1, 2, 3};
	int count[4] = {0};
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a, b, c;
		cin>>a>>b>>c;
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
		count[arr[c]]++;
	}

	cout<<max(count[1], max(count[2], count[3]));
}