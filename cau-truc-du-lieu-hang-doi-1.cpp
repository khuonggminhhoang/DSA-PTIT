#include<iostream>
#include<queue>

using namespace std;

void solve(int n){
	queue <int> q;
	int num ;
	while(n--){
		cin>>num;
		switch(num){
			case 1 : {
				cout<<q.size()<<endl;
				break;
			}
			case 2 : {
				if(q.empty()) cout<<"YES\n";
				else cout<<"NO\n";
				break;
			}
			case 3 : {
				int x;
				cin>>x;
				q.push(x);
				break;
			}
			case 4 : {
				if(!q.empty()){
					q.pop();
				}
				break;
			}
			case 5 : {
				if(!q.empty()){
					cout<<q.front()<<endl;
				}
				else cout<<-1<<endl;
				break;
			}
			case 6 : {
				if(q.empty()) cout<<-1<<endl;
				else{
					cout<<q.back()<<endl;
				}
				break;
			}
		}
	}
	if(num == 3 || num == 4) cout<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
}


