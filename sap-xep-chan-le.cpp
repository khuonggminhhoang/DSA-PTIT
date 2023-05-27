/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

main(){
	int n;
	cin>>n;
	int dp[n]={0};
	vector <int> chan, le;
	for(int i=0; i<n; ++i){
		int x;
		cin>>x;
		if(x % 2) le.push_back(x);
		else{
			chan.push_back(x);
			dp[i]=1;
		}
	}
	sort(chan.begin(), chan.end());
	sort(le.begin(), le.end(), greater <int> ());
	for(auto x : dp) {
		if(x){
			cout<<chan[0]<<" ";
			chan.erase(chan.begin());
		}
		else{
			cout<<le[0]<<" ";
			le.erase(le.begin());
		}
	}
}

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

main(){
	int n;
	cin>>n;
	vector <int> chan, le;
	for(int i=0; i<n; ++i){
		int x;
		cin>>x;
		if(i%2){
			le.push_back(x);
		}
		else chan.push_back(x);
	}
	sort(chan.begin(), chan.end());
	sort(le.begin(), le.end(), greater <int> ());
	
	for(int i=0; i<n; ++i){
		if(i%2){
			cout<<le[0]<<" ";
			le.erase(le.begin());
		}
		else {
			cout<<chan[0]<<" ";
			chan.erase(chan.begin());
		}
	}
}
