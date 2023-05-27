#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Items {
	int v,c;
};

bool cmp( Items a, Items b){
	return a.v < b.v;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,v;
		cin>>n>>v;
		Items ds[n];
		int a[n],b[n];
		for(auto &x : a) cin>>x;
		for(auto &y : b) cin>>y;
		for(int i=0; i<n; ++i){
			ds[i]= {a[i],b[i]};
		}
		sort(ds,ds+n,cmp);
		for(auto x : ds){
			cout<<x.v<<" "<<x.c<<endl;
		}
		
	}
}
