#include<iostream>
#include<string>
#include<vector>

using namespace std;

main(){
	int n;
	cin>>n;
	cin.ignore();
	vector <int> ke[1002];
	for(int j=1; j<=n; ++j){
		string s;
		getline(cin,s);
		
		int number=0;
		for(int i=0; i<=s.size(); ++i){			//note dau =
			if(isdigit(s[i])){
				number=10*number + (s[i]-'0');
			}
			else{
				ke[j].push_back(number);
				number=0;
			}
		}
	}
	
	int a[n+1][n+1]={0};
	for(int i=1; i<=n; ++i)
		for(auto x : ke[i])
			a[i][x]=1;
			
	for(int i=1; i<=n; ++i){
		for( int j=1; j<=n ; ++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
			
}
