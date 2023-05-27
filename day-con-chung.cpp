#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int binarySearch(vector <int> a, int x){
	int r=a.size()-1,l=0,m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==x) return m;
		if(a[m] < x) l=m+1;
		if(a[m] > x) r=m-1; 
	}
	return -1;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector <int> a,b,c,v;
		int x;
		while(n--){
			cin>>x;
			a.push_back(x);
		}
		while(m--){
			cin>>x;
			b.push_back(x);
		}
		while(k--){
			cin>>x;
			c.push_back(x);
		}
		
		for(int i=0; i<a.size(); ++i){
			int res1= binarySearch(b,a[i]);
			int res2= binarySearch(c,a[i]);
			if(res1 != -1 && res2 != -1){
				v.push_back(a[i]);
				a.erase(a.begin() + i);
				b.erase(b.begin() + res1);
				c.erase(c.begin() + res2);
				--i;
			}
		}
		if(v.empty()) cout<<"NO\n";
		else {
			for(auto x : v) cout<<x<<" ";
			cout<<endl;
		}
	}
}
