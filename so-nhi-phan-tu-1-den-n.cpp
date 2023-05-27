#include<iostream>
#include<stack>

using namespace std;

void convert_to_binary(int n){
	stack <int> stk;
	while(n!=0){
		stk.push(n%2);
		n/=2;
	}
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1; i<=n; ++i){
			convert_to_binary(i);
			cout<<" ";
		}
		cout<<endl;
	}
}
