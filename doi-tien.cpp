#include<iostream>

using namespace std;

int a[10]={1000, 500, 200, 100, 50, 20, 10, 5,2,1};

void greedy(int n){
	int sum=0;
	int i=0;
	while(n!=0 && i<10){
		sum+= n/a[i];
		n%=a[i];
		++i;
	}
	cout<<sum<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		greedy(n);
	}
}
