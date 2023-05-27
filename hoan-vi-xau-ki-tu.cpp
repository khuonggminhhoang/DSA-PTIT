#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool visited[1000];
string s;
char res[1000];

void Try(int i){
	for(int j=0; j<s.size(); ++j){
		if(!visited[j]){
			res[i] = s[j];
			visited[j] = true;
			if( i == s.size()-1){
				cout<<res<<" ";
			}
			else Try(i+1);
			visited[j]=false;
		}
	}
}


main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		memset( visited, false, sizeof(visited));
		Try(0);
		cout<<endl;
	}
}
