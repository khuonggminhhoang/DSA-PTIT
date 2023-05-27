#include<iostream>
#include<queue>
#include<map>

using namespace std;

int so(string s){
	int ans=0;
	for(auto x : s){
		ans = 10*ans + (x-'0');
	}
	return ans;
}

bool check( string s){
	map <char,int> mp;
	for(auto x : s){
		mp[x]++;
	}
	for( auto it : mp){
		if(it.second > 1 ) return false;
	}
	return true;
}

int solve(int L, int R){
	queue <string> q;
	int cnt = 0;
	q.push("0");
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while(!q.empty()){
		string s = q.front();
		q.pop();
		int num = so(s);
		if(num >= L && num <= R) cnt++;
		if( s[0]=='0') continue;
		if( check(s+"0") && so(s + "0") <= R) q.push(s + "0");
		else if(so(s + "0") > R) continue;
		if( check(s+"1") && so(s + "1") <= R) q.push(s + "1");
		else if(so(s + "1") > R) continue;
		if( check(s+"2") && so(s + "2") <= R) q.push(s + "2");
		else if(so(s + "2") > R) continue;
		if( check(s+"3") && so(s + "3") <= R) q.push(s + "3");
		else if(so(s + "3") > R) continue;
		if( check(s+"4") && so(s + "4") <= R) q.push(s + "4");
		else if(so(s + "4") > R) continue;
		if( check(s+"5") && so(s + "5") <= R) q.push(s + "5");
		else if(so(s + "5") > R) continue;
	}
	return cnt;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int L,R;
		cin>>L>>R;
		cout<<solve(L,R)<<endl;
	}
}
