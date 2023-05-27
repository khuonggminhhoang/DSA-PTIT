#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int to_number(string s){
	int ans = 0;
	for(auto x : s){
		ans = 10 * ans + (x - '0');
	}
	return ans;
}

bool prime( int n){
	if( n==0 || n==1) return false;
	for(int i=2; i<=sqrt(n); ++i){
		if(n%i==0) return false;
	}
	return true;
}

void solve(int n, int m){
	queue <pair<string,int>> q;
	string s = to_string(n);
	q.push({s,0});
	int ok = 0;
	while(!q.empty()){
		pair <string,int> p = q.front();
		q.pop();
		string stm = to_string(m);
		if( p.first == stm) {
			cout<<p.second<<endl;
			return;
		}
		
		for(int i=0; i<=9; ++i){
			if(ok) break;
			string x = p.first;
			x[3] = '0' + i;
			if(prime(to_number(x))){
				q.push({x,p.second+1});
			}
			if( x == stm) ok = 1;
		}
		
		for(int i=0; i<=9; ++i){
			if(ok) break;
			string x = p.first;
			x[2] = '0' + i;
			if(prime(to_number(x))){
				q.push({x,p.second+1});
			}
			if( x == stm) ok = 1;
		}
		
		for(int i=0; i<=9; ++i){
			if(ok) break;
			string x = p.first;
			x[1] = '0' + i;
			if(prime(to_number(x))){
				q.push({x,p.second+1});
			}
			if( x == stm) ok = 1;
		}
		
		for(int i=0; i<=9; ++i){
			if(ok) break;
			string x = p.first;
			x[0] = '0' + i;
			if(prime(to_number(x))){
				q.push({x,p.second+1});
			}
			if( x == stm) ok = 1;
		}
		
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		solve(n,m);
	}
}
