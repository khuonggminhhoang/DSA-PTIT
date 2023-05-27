#include<iostream>
#include<queue>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int a,b,c,d;
		b = (s1[0] - 'a' + 1) ;
		d = (s2[0] - 'a' + 1) ;
		a = 8 - (s1[1] - '0') + 1;
		c = 8 - (s2[1] - '0') + 1;
		int x[9][9];
		for(int i=1; i<=8; ++i){
			for(int j=1; j<=8; ++j){
				x[i][j] = 0;
			}
		}

		queue <pair<pair <int,int>, int>> q;
		q.push({{a,b},0});
		x[a][b]=1;
		while(!q.empty()){
			pair <pair <int,int> , int> p = q.front();
			q.pop();
			int i = p.first.first, j = p.first.second, k = p.second	;
			if(i == c && j == d){
				cout<<k<<endl;
				break;
			}
			if( i + 2 <=8 ){
				if( j + 1 <=8 && x[i+2][j+1] == 0 ){
					q.push({{i+2, j+1},k+1});
					x[i+2][j+1] = 1;
				}
				if( j - 1 >0 && x[i+2][j-1] == 0 ){
					q.push({{i+2,j-1}, k+1});
					x[i+2][j-1] = 1;
				}
			}
			
			if( i - 2 > 0 ){
				if( j + 1 <=8 && x[i-2][j+1] == 0 ){
					q.push({{i-2, j+1},k+1});
					x[i-2][j+1] = 1;
				}
				if( j - 1 >0 && x[i-2][j-1] == 0 ){
					q.push({{i-2,j-1}, k+1});
					x[i-2][j-1] = 1;
				}
			}
			
			if( j + 2 <=8 ){
				if( i + 1 <=8 && x[i+1][j+2] == 0){
					q.push({{i+1,j+2},k+1});
					x[i+1][j+2] = 1;
				}
				if( i - 1 >0 && x[i-1][j+2] == 0){
					q.push({{i-1,j+2}, k+1});
					x[i-1][j+2] = 1;
				}
			}
			
			if( j - 2 > 0 ){
				if( i + 1 <=8 && x[i+1][j-2] == 0){
					q.push({{i+1,j-2},k+1});
					x[i+1][j-2] = 1;
				}
				if( i - 1 >0 && x[i-1][j-2] == 0){
					q.push({{i-1,j-2}, k+1});
					x[i-1][j-2] = 1;
				}
			}
			
		}
	}
}
