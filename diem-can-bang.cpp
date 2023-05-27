#include<iostream>

using namespace std;

int solve(int a[], int n, int sum, int s1, int s2){
	for(int i=0; i<n-1; ++i){
		s1+=a[i];
		s2=sum - s1 - a[i+1];
		if(s1 == s2) return i+2;
	}
	return -1;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int sum=0, s1=0,s2;
		for(auto &x : a){
			cin>>x;
			sum+=x;
		}
		cout<<solve(a,n,sum,s1,s2)<<endl;
	}
}
