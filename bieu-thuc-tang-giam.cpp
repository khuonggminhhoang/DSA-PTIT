#include<iostream>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <int> stk;
		int i;
		for( i=0;i<s.size(); ++i){
			if(s[i]=='D'){
				stk.push(i+1);
			}
			else{
				cout<<i+1;
				while(!stk.empty()){
					cout<<stk.top();
					stk.pop();
				}
			}
		}	
		cout<<i+1;
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;	
	}
}
