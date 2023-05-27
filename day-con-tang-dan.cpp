#include<iostream>
#include<vector>
#include<set>

using namespace std;
	
int n, a[100], x[100];
vector < vector<int> > v;
set <string> st;

void Result(){
	vector <int> subv;
	for(int i=1; i<=n; ++i){
		if(x[i]) subv.push_back(a[i]);
	}
	v.push_back(subv);
}

bool check(vector <int> vct){
	if(vct.size() < 2) return false;
	for(int i=0; i<vct.size()-1; ++i)
		if(vct[i] > vct[i+1]) return false;
		
	return true;
}

string convert_string(vector <int> vct){
	string res="";
	for(int i=0; i<vct.size(); ++i){
		res+=to_string(vct[i]) + " ";
	}
	return res;
}

void Try(int i){
	for(int j=0; j<=1; ++j){
		x[i]=j;
		if(i==n)
			Result();
		else Try(i+1);
	}
}

main(){
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	Try(1);
	for(auto x : v){
		if(check(x)){
			st.insert(convert_string(x));
		}
	}

	for( auto x : st){
		cout<<x<<endl;
	}
}
