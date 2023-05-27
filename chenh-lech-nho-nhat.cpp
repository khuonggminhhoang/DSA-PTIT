#include<iostream>
#include<algorithm>


using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		sort(a,a+n);
		int min_=1e9;
		for(int i=1; i<n; ++i){
			min_ = min(min_, a[i] - a[i-1]);
		}
		cout<<min_<<endl;
	}
}
