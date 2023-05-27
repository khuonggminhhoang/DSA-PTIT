#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void print_lucky_number(int n){
	queue <string> q;
	vector <string> v;
	q.push("6");
	q.push("8");
	while(!q.empty()){
		string s = q.front();
		q.pop();
		v.push_back(s);
		string tmp = s + '6';
		if(tmp.size() <= n) q.push(tmp);
		tmp = s + '8';
		if(tmp.size() <= n) q.push(tmp);
	}
	cout<<v.size()<<endl;
	for(auto x : v) cout<<x <<" ";
	cout<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		print_lucky_number(n);
	}
}
