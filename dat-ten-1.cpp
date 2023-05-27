#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n,k;
set <string> st;
int a[1000];
vector <string> v;

bool next_permutation(){
	int pos;
	for( pos= k; pos >= 1; --pos)
		if(a[pos] < st.size() -k + pos ) break;
	
	a[pos] +=1;
	for(int i=pos+1; i<=k; ++i)
		a[i] = a[pos] + (i-pos);
	
	for(int i=1; i<=k; ++i)
		if(a[i] != st.size() - k + i) return false;
	return true;
}

void print(){
	for(int i=1; i<=k; ++i)
		cout<<v[a[i] -1]<<" ";
	cout<<endl;
}

main(){
	cin>>n>>k;
	while(n--){
		string s;
		cin>>s;
		st.insert(s);
	}
	for(int i=1; i<=k; ++i)
		a[i]=i;
	bool flag=false;
	for( string s : st){
		v.push_back(s);
	}
	while(!flag){
		print();
		flag=next_permutation();
	}
	print();
}

/*
6 2
DONG TAY NAM BAC TAY BAC
*/
