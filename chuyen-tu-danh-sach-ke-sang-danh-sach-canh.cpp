#include<iostream>
#include<vector>
#include<string>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n+2][n+2]={0};
	cin.ignore();
	vector <int> ke[1000];
	for(int j=1; j<=n; ++j){
		string s;
		getline(cin, s);
		
		int number=0;
		for(int i=0; i<=s.size(); ++i){
			if(isdigit(s[i])){
				number=10*number + (s[i]-'0');
			}
			else{
				ke[j].push_back(number);
				number=0;
			}
		}
	}
	
	for(int i=1; i<=n; ++i){
		for(auto x:ke[i]) {
			a[i][x]=1;
		}
	}
	
	for(int i=1; i<=n ; ++i){
		for(int j=i; j<=n; ++j)
			if(a[i][j]) cout<<i<<" "<<j<<endl;
	}
}
