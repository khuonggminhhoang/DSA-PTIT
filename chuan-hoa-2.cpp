#include<iostream>
#include<string>
#include<sstream>

using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s,tmp,res="" ,save=", ";
		getline(cin,s);
		stringstream ss (s);
		int count=0;
		while(getline(ss, tmp, ' ')){
			if(count==0) {
				for(int i=0; i<tmp.size(); ++i)
					tmp[i]=toupper(tmp[i]);
				save+=tmp;	
				count++;
			}
			else{
				tmp[0]= toupper(tmp[0]);
				for(int i=1; i<tmp.size(); ++i)
					tmp[i]= tolower(tmp[i]);
				res+=tmp + ' ';
			}
		}
		res.erase(res.begin() + res.size() - 1);
		res+=save;
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
