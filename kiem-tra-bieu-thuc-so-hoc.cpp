#include<iostream>
#include<string>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		stack <char> stk;
		bool check ;		
		for(int i=0; i<s.size(); ++i){
			if(s[i] == ')'){
				char top = stk.top();
				stk.pop();
				check = false;
				while(top != '('){
					if(top == '+' || top == '-' || top == '*' || top == '/'){
						check = true;
					}
					top = stk.top();
					stk.pop();
				}
				if(check == false) break;
			}
			else stk.push(s[i]);
		}
		
		if(!check) cout<<"Yes\n";
		else cout<<"No\n";
	}
}

//3
//((a+b))
//(a + (b)/c)
//(a + b*(c-d))

