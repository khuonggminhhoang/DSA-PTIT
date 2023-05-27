#include<iostream>
#include<sstream>

using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp, res="";
		while(getline(ss, tmp, ' ')){
			tmp[0]= toupper(tmp[0]);
			for(int i=1; i<tmp.size(); ++i)
				tmp[i]= tolower(tmp[i]);
			res+=tmp + ' ';
		}
		res.erase(res.begin() + res.size() -1);
		cout<<res<<endl;
	}
}

/*
4
nGUYEn quaNG vInH
tRan thi THU huOnG
nGO quoC VINH
lE tuAn aNH
*/
