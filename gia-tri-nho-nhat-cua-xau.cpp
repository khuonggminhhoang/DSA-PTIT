#include<iostream>
#include<queue>
#include<map>


using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		long long k;
		string s;
		cin>>k>>s;
		if(k <= s.size()){
		priority_queue <long long> pr;
		map <char,long long> mp;
		for(auto x : s){
			mp[x]++;
		}
		for(auto it : mp){
			pr.push(it.second);
		}
		
		while( k>0 && pr.size() >0){
			long long x = pr.top();
			pr.pop();
			k--;
			--x;
			pr.push(x);
		}
		
		long long sum=0;
		while(pr.size() > 0){
			long long x= pr.top();
			pr.pop();
			sum += x*x;
		}
		cout<<sum<<endl;
		}
		
	}
	
}
