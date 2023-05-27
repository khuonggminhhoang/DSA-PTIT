#include<iostream>
#include<queue>
using namespace std;

long long so(string s){
	long long ans=0;
	for(auto x : s){
		ans = 10 * ans + (x - '0');
	}
	return ans;
}

void find_BDN_min(int n){
	queue <string> q;
	string res = "1";
	q.push(res);
	while(1){
		string s = q.front();
		q.pop();
		if(so(s) % n ==0){
			cout<<s<<endl;
			break;
		}
		q.push(s + '0');
		q.push(s + '1');
	}
	
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		find_BDN_min(n);
	}
}
