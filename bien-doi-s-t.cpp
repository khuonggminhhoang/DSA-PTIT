#include<iostream>
#include<queue>
#include<map>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int s,t;
		cin>>s>>t;
		queue <pair<int,int>> q;
		map <int,bool> mp;
		q.push({s,0});
		
		while(!q.empty()){
			pair <int,int> p;
			p = q.front();
			q.pop();
			if( p.first == t){
			 	cout<<p.second<<endl;
				break;
			}
			
			if( p.first <= t && mp[2*p.first]==0){
				q.push({2*p.first , p.second+1});
				mp[2*p.first] = 1;
			}
			
			if( p.first -1 >=0 && mp[p.first-1] == 0){
				q.push({p.first - 1, p.second + 1});
				mp[p.first - 1] = 1;
			}
			
		}
		
	}
}

