#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue <int , vector <int>,greater <int>> pq;
		while(n--){
			int x;
			cin>>x;
			pq.push(x);
		}
		long long sum=0;
		long long res=0;
		while(pq.size() > 1){
			sum+=pq.top();
			pq.pop();
			sum+=pq.top();
			pq.pop();
			pq.push(sum);
			res+=sum;
			sum=0;
		}
		cout<<res<<endl;
	}
}
