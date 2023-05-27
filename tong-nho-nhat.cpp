#include<iostream>
#include<algorithm>

using namespace std;

void greedy(int a[], int n){
	long long x=0, y=0;
	for(int i=0; i<n; ++i){
		if(i%2==0) x= 10*x + a[i];
		else y = 10*y + a[i];
	}
	cout<<x+y<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for( auto &x : a) cin>>x;
		sort(a,a+n);
		greedy(a,n);
	}
}
