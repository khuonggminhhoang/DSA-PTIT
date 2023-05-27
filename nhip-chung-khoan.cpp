#include<iostream>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n];
		for(auto &x : a) cin>>x;
		stack <long long> stk;
		long long d[n];
		for(auto &x:d) x=1;
		for(int i=0; i<n; ++i){
			if(stk.empty()) stk.push(i);
			else{
				if(a[i] < a[stk.top()] ) stk.push(i);
				else if(a[i] == a[stk.top()] ){
					d[i]+=d[stk.top()];
					stk.pop();
					stk.push(i);
				}
				else{
					while(a[i] > a[stk.top()]){
						d[i]+=d[stk.top()];
						stk.pop();
					}
					stk.push(i);
				}
			}
		}
		for(auto x : d) cout<<x<<" ";
		cout<<endl;
	}
}
