#include<iostream>
#include<string>

using namespace std;

int solve(string s1, string s2){
	int n=s2.size()+1, m=s1.size()+1;
	int a[n][m];
	for(int i=0; i<n; ++i)
		a[i][0]=0;					//cho cot dau tien cua matran a =0;
	for(int j=0; j<m; ++j)
		a[0][j]=0;
	
	for(int i=1; i<n; ++i)
		for(int j=1; j<m; ++j)
			if(s2[i-1] == s1[j-1]){
				a[i][j]= a[i-1][j-1] + 1;
			}
			else{
				a[i][j]= max(a[i][j-1], a[i-1][j]);
			}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
 	return a[n-1][m-1];
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s1, s2;
		cin>>s1>>s2;
		cout<<solve(s1,s2)<<endl;
	}
}

/*
2
AGGTAB
GXTXAYB
AA
BB
*/
