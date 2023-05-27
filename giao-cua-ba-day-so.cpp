#include<iostream>
#include<vector>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		vector <long long> ans;
		cin>>n>>m>>k;
		long long a[n], b[m], c[k];
		for(auto &x : a) cin>>x;
		for(auto &x : b) cin>>x;
		for(auto &x : c) cin>>x;
		int i=0, j=0, l=0;
		while(i <n && j < m && l < k){
			if(a[i] == b[j] && a[i] == c[l]){
				ans.push_back(a[i]);
				++i; 
				++j;
				++l;
			}
			else if(a[i] < b[j] && a[i] < c[l]){
				++i;
			}
			else if(b[j] < a[i] && b[j] < c[l]){
				++j;
			}
			else if(c[l]<a[i] && c[l] < b[j]){
				++l;
			}
			else if(a[i] < b[j] && c[l] < b[j]){
				++i;
				++l;
			}
			else if(b[j] < a[i] && c[l] < a[i]){
				++j;
				++l;
			}
			else if(a[i] < c[l] && b[j] < c[l]){
				++i;
				++j;
			}
		}
		if(ans.size()==0){
			cout<<-1<<endl;
		}
		else{
			for(auto x : ans) cout<<x<<" ";
			cout<<endl;
		}
	}
}
