#include<iostream>
#include<deque>

using namespace std;

main(){
	int n;
	cin>>n;
	deque <int> dq;
	while(n--){
		string s;
		cin>>s;
		if( s == "PUSHBACK"){
			int x;
			cin>>x;
			dq.push_back(x);
		}
		else if( s == "PUSHFRONT"){
			int x;
			cin>>x;
			dq.push_front(x);
		}
		else if( s == "PRINTFRONT"){
			if(!dq.empty())	cout<<dq.front()<<endl;
			else cout<<"NONE\n";
		}
		else if( s == "POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		}
		else if( s== "PRINTBACK"){
			if(!dq.empty()) cout<<dq.back()<<endl;
			else cout<<"NONE\n";
		}
		else if( s == "POPBACK"){
			if(!dq.empty()) dq.pop_back();
		}
	}
}
