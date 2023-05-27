#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		a[0]=0;
		for(int i=1; i<=n; ++i) cin>>a[i];
		stack <long long> stk;
		stk.push(0);
		long long s=0, max_=-1e9;
		for(int i=1; i<=n; ++i){
			if(a[i]>a[i-1]){
				stk.push(i);
			}
			else if(a[i]==a[i-1]){
				stk.pop();
				stk.push(i);
			}
			else{
				long long x = stk.top();
				while(a[i]<=a[stk.top()]){
					long long w= stk.top();
					stk.pop();
					s=a[w]*(x-stk.top());
					max_=max(max_,s);
				}
				stk.push(i);
			}
		}
		long long x=stk.top();
		while(stk.size()!=1){
			long long w=stk.top();
			stk.pop();
			s=a[w]*(x-stk.top()); 
			max_=max(max_,s);
		}
		cout<<max_<<endl;
	}
}

