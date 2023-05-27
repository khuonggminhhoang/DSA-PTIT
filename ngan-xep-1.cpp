#include<iostream>
#include<vector>
#include<string>

using namespace std;

main(){
	vector <int> v;
	string s;
	while(1){
		cin>>s;
		if(s=="push") {
			int x;
			cin>>x;
			v.push_back(x);
		}
		else if(s=="show"){
			if(!v.empty()){
			 	for(auto x:v) cout<<x<< ' ';
				cout<<endl;
			}
			else{
				cout<<"empty\n";
				break;
			}
		}
		else if(s=="pop"){
			v.erase(v.end()-1);
		}
	}
}

