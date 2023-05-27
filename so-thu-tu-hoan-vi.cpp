#include<iostream>
#include<algorithm>
using namespace std;

int t, n, a[100], b[100];

bool check(){
	for(int i=1; i<=n; ++i)
		if(a[i] != b[i]) return false;
	return true;
}

void sinh(){
	int pos=0;
	for(pos=n; pos>=2; --pos)
		if(a[pos-1] < a[pos]) break;
	
	int k=n;
	while( a[pos-1] > a[k]) k--;
	swap(a[pos-1], a[k]);
	sort(a+pos, a+n+1);
	check();
}

main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; ++i) a[i]=i;
		int count=1;
		bool flag=false;
		for(int i=1; i<=n; ++i) cin>>b[i];
		flag=check();
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
4
1 4 3 2
4
1 2 3 4
*/

/*
6
1
*/
