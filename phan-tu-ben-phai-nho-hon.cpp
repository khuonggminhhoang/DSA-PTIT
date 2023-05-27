#include<iostream>
#include<algorithm>

using namespace std;

struct element{
	int x;
	int index;
};

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		element e[n];
		for(auto &y : e) {
			y={-1,n};
		}
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				if(a[i]<a[j]){
					e[i]= {a[j],j};
				
					break;
				}	
			}
		}
//		for(auto x : e){
//			cout<<x.x<<"->"<<x.index<<endl;
//		}
		
		for(int i=0; i<n; ++i){
			int ok = 0;
			for(int j=e[i].index+1; j < n; ++j){
				if(e[i].x>a[j]){
					cout<<a[j]<<" ";
					ok=1;
					break;
				}
			}
			if(!ok) cout<<-1<<" ";
		}
		cout<<endl;
	//	for(auto x : vt) cout<<x<<' ';
	}
}
