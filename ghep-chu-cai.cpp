#include<iostream>
#include<string>
#include<set>

using namespace std;
char c;
char res[1000];
bool visited[1000];

bool check(char chr){
	int pos=0;
	for(int i=0; i<= c-'A'; ++i){
		if(chr==res[i]) {
			pos=i;
			break;
		}
	}
	
	if(0<pos && pos < c-'A' ){
		if(res[pos-1]=='E' || res[pos+1]=='E') return true;
		if(res[pos-1]=='A' || res[pos+1]=='A') return true;
		return false;
	}
	return true;
}
  
void Try(int u){
	for(int i='A'; i<= c; ++i){
		if(!visited[i]){
			res[u]=i;
			visited[i]=1;
			if(u==c-'A' && check('A') && check('E')) 
				cout<<res<<endl;
			else Try(u+1);
			visited[i]=0;
		}
		
	}
}

main(){
	cin>>c;
	Try(0);
}
