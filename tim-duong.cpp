#include<iostream>

using namespace std;

int n,m, u,v,s,t, ok;
int a[501][501];

void inp(){
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			char c;
			cin>>c;
			if(c == '.' ) a[i][j] = 1;
			if(c == '*' ) a[i][j] = 0;
			if(c == 'S') {
				u = i;
				v = j;
				a[i][j] = 1;
			}
			if( c == 'T'){
				s = i;
				t = j;
				a[i][j] = 1;
			}
		}
	}
	ok = 0;
}

void print(){
	for(int i=1; i<=n; ++i){
		for(int j = 1; j<=m ; ++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void DFS(int u, int v, int cnt, int pre, int cur){
	a[u][v] = 0;
//	print(); cout<<cnt<<endl;
//	cout<<"+++++++++++++++++++++\n";
	if(u == s && v == t){
		if(cnt <=3 ){
			ok = 1;
			return ;
		}
	}
	
	if(u >=1 && u <=n && v >=1 && v <= m){
		if(v+1 <= m && a[u][v+1] == 1){
			pre = cur;
			cur = 1;
			if(pre != cur) DFS(u,v+1,cnt+1, pre, cur);
			else DFS(u,v+1,cnt,pre,cur);
		}
		
		if( u + 1 <= n && a[u+1][v] == 1){
			pre = cur;
			cur = 3;
			if(pre != cur) DFS(u+1, v, cnt + 1, pre,cur);
			else DFS(u+1, v, cnt, pre, cur);
		}
		
		if(v-1 >=1 && a[u][v-1] == 1 ){
			pre = cur;
			cur = 2;
			if( pre != cur ) DFS(u, v-1,cnt + 1 ,pre, cur);
			else DFS(u,v-1,cnt,pre,cur);
		}
		
		if( u - 1 >=1 && a[u-1][v] == 1){
			pre = cur;
			cur = 4;
			if(pre != cur) DFS(u-1, v, cnt+1, pre, cur);
			else DFS(u-1, v, cnt, pre,cur);
		}
	}
	a[u][v] = 1;
}

main(){
	int t;
	cin>>t;
	while(t--){
		inp();
		DFS(u,v,0,0,0);
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
//		print();
	}
}

/*

3
5 5
..S..
****.
T....
****.
.....
5 5
S....
****.
.....
.****
..T..
5 5
S....
.*.**
T*...
..*..
*...*
*/
