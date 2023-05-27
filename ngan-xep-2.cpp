#include<iostream>
#include<stack>
#include<string>

using namespace std;

main(){
	int t;
	cin>>t;
	stack <int> stk;
	while(t--){
		string s;
		cin>>s;
		if(s=="PUSH"){
			int x;
			cin>>x;
			stk.push(x);
		}
		else if( s=="POP"){
			if(!stk.empty()){
				stk.pop();
			}
		}
		else if(s=="PRINT"){
			if(!stk.empty()){
				cout<<stk.top()<<endl;
			}
			else cout<<"NONE\n";
		}
	}
}
