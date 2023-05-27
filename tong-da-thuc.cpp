#include<iostream>
#include<map>
#include<vector>

using namespace std;

int toNum(string s){
	int num =0 ;
	for(auto x: s){
		num = 10*num + (x - '0');
	}
	return num;
}

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s1;
		getline(cin,s1);
		string s2;
		getline(cin,s2);
		string number = "";
		map <int , int> mp;
		vector <int> v;
		for(int i=0; i<=s1.size(); ++i){
			if(isdigit(s1[i])){
				number += s1[i];
			}
			else {
				if(number != ""){
					int num = toNum(number);
					v.push_back(num);
				}
				number = "";
			}
		}		
		
		
		for(int i=0; i<=s2.size(); ++i){
			if(isdigit(s2[i])){
				number += s2[i];
			}
			else {
				if(number != ""){
					int num = toNum(number);
					v.push_back(num);
				}
				number = "";
			}
		}	
		for(int i=1; i<v.size(); i+=2){
			mp[v[i]] += v[i-1];
		}	
		string res = "";
		auto it = mp.end();
		it--;
		auto x = it;
		for( x = it; x!=mp.begin(); --x ){
			cout<<x->second <<"*x^"<<x->first<<" + "; 
		}
		cout<<x->second <<"*x^"<<x->first<<endl;
	}
}


