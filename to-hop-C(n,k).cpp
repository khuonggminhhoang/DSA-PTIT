#include<iostream>

using namespace std;

int m = 1e9+7;
int C[1001][1001]={0};

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0; i<=n; ++i){
			C[i][0]=1;				// set cac phan tu cot dau tien =1
		}
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=i; ++j){
				C[i][j] = (C[i-1][j-1] % m + C[i-1][j] % m) % m;
			}
		}
		cout<<C[n][k]<<endl;
	}
}

/*
#include<iostream>
using namespace std;
int m = 1e9+7;
int C[1001][1001]={0};
int main(){
    int t;
    cin>>t;
    for(int i=0; i<1001; ++i) C[i][0]=1; //set cac phan tu o cot dau = 1
    while(t--){
        int n,k; cin>>n>>k;
        if(C[n][k]==0){
            for(int i=1; i<=n; ++i){
                if(C[i][i]==0){
                    for(int j=1; j<=i; ++j){
                        if(C[i][j] == 0){
                            C[i][j] = (C[i-1][j-1] % m + C[i-1][j] % m) % m;    
                        }
                    }
                }
            }
        }
        cout<<C[n][k]<<endl;
    }
}
*/

