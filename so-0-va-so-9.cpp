#include<iostream>
#include<queue>
using namespace std;

string solve(int n){
	queue <string> q;
	q.push("9");
	while(!q.empty()){
		string s = q.front(); 
		q.pop();
		int num=0 ;
		for(auto x : s){
			num = num*10 + (x - '0');
		}
		if(num%n==0) return s;
		q.push(s + "0");
		q.push(s + "9");
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}
}
