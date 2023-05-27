#include<iostream>

using namespace std;

int t, n,k, a[100], b[100];

bool check(){
	for(int i=1; i<=k; ++i)
		if(a[i] != b[i] ) return false;
	return true;
}

void sinh(){
	int pos;
	for(pos=k; pos>=1; --pos)
		if( a[pos] < n-k+pos) break;
	a[pos] += 1;
	for( int i=pos + 1; i<=k; ++i)
		a[i] = a[pos] + ( i-pos);
}
 
main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		int count=1;
		for(int i=1; i<=k; ++i) a[i]=i;
		for(int i=1; i<=k; ++i) cin>>b[i];
		bool flag=check();
		while(!flag){
			count++;
			sinh();
			flag=check();
		}
		cout<<count<<endl;
	}
}

/*
2
6 4
1 3 5 6
6 4
2 3 4 6
*/

/*
9
12
*/
