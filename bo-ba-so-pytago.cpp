#include<iostream>
#include<algorithm>

using namespace std;

int solve(long long a[], int n){
	for(int i=n-2; i>=2; --i){
		int l=0, r=i-1;
		while(l<r){
			if(a[l] + a[r] == a[i]) return 1;
			else if(a[l] + a[r] < a[i]) ++l;
			else --r;
		}
	}
	return 0;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n];
		for(auto &x : a){
			long long y;
			cin>>y;
			x= y*y;
		}
		sort(a,a+n);
		if(solve(a,n)) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
}
