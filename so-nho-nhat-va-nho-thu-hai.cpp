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
		for(int i=0; i<n; ++i) cin>>a[i];
		sort(a,a+n);
		if(n!=1 && a[0] != a[1]) cout<<a[0]<<" "<<a[1]<<endl;
		else cout<<-1<<endl;
	}
}
