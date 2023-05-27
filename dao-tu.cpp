#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		stack <string> stk;
		string s;
		getline(cin,s);
		stringstream ss (s);
		string tmp;
		while(ss>>tmp){
			stk.push(tmp);
		}
		while(!stk.empty()){
			cout<<stk.top()<<" ";
			stk.pop();
		}
		cout<<endl;
	}
}

