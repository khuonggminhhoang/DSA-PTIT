#include<iostream>
#include<queue>
#include<map>
#include<cmath>

using namespace std;

void solve(int n){
	queue <pair<int,int>> q;
	map <int,bool> mp;
	q.push({n,0});
	
	while(!q.empty()){
		pair <int,int> p = q.front();
		q.pop();
		if(p.first == 1){
			cout<<p.second<<endl;
			return;
		}
		
		for(int i=2; i<=sqrt(p.first); ++i){
			if(p.first % i ==0 && !mp[p.first/i]){
				q.push({p.first/i, p.second+1});
				mp[p.first/i] = 1;
			}
		}
		
		q.push({p.first - 1, p.second + 1});
	}
	
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);

	}
}
