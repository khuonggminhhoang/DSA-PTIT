#include<iostream>
#include<queue>

using namespace std;
const int mod = 1e9 + 7;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue <int , vector <int>, greater <int>> pq;
		while(n--){
			int x;
			cin>>x;
			pq.push(x);
		}
		long long sum = 0, res = 0;
		while(pq.size() > 1){
			sum = (sum%mod + pq.top()%mod) %mod;
			pq.pop();
			sum = (sum%mod + pq.top()%mod) %mod;
			pq.pop();
			res = (res%mod + sum%mod) %mod;
			pq.push(sum);
			sum=0;
		}
		cout<<res<<endl;
	}
}
