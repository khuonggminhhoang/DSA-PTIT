#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				if( a[j] > a[i]) {
					cout<<a[j]<<" ";
					break;
				}
				else if( j==n-1) cout<<-1<<" ";
			}
		}
		cout<<-1<<endl;
	}
}
