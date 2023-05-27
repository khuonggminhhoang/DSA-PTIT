#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int n, a[10002];
set <int> st;
vector <int> v;

void print(){
	for(int i=1; i<=n; ++i)
		cout<< v[a[i]-1] <<" ";
	cout<<endl;
}

bool next_combination(){
	int pos;
	for(pos=n; pos>= 2; --pos)
		if(a[pos-1] < a[pos]) break;
	int k=n;
	while(a[pos-1] > a[k]) k--;
	swap(a[pos-1], a[k]);
	sort(a+pos, a+n+1);
	for(int i=1; i<n; ++i)
		if(a[i] < a[i+1]) return false;
	return true;
}

main(){
	cin>>n;
	for(int i=1; i<=n; ++i){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(int x : st)
		v.push_back(x);
		
	bool flag=false;
	for(int i=1; i<=n; ++i) a[i]=i;
	while(!flag){
		print();
		flag=next_combination();
	}
	print();
}
