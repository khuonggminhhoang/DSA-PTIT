#include<iostream>

using namespace std;

int a[1000][1000];
int n, start;
bool tick[1000];
int d[1000], truoc[1000];

const int INF = 1e9+7;

void Bellman_Ford(int start){
	for(int i=1; i<=n; ++i){
		d[i] = a[start][i];
		truoc[i] = start;
	}
	d[start] = 0;
	tick[start] = 1;

	for(int k = 1; k <= n-2; ++k){
		for(int u = 1; u<= n; ++u){
			if(!tick[u]){
				for(int v=1; v <= n ; ++v){
					if(d[v] > d[u] + a[u][v] && a[u][v] != INF){
						d[v] = d[u] + a[u][v];
						truoc[v]=u;
					}
				}
			}
		}
	}
}

void print(int s, int t){
	if(d[t] == INF) cout<<"K/c "<<s<<" -> "<<t<<" = INF;\n";
	else{
		cout<<"K/c "<<s<<" -> "<<t<<" = "<<d[t]<<"; \t";
		int x = truoc[t];
		cout<<t<<"<-";
		while(x!= s){
			cout<<x<<"<-";
			x = truoc[x];
		}
		cout<<x<<endl;
	}
}

void Result(){
	for(int i=1; i<=n; ++i){
		print(start,i);
	}
}

main(){
	cin>>n>>start;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin>>a[i][j];
			if(a[i][j] == 0) a[i][j] = INF;
		}
	}	
	
	for(int i=1; i<=n; ++i) tick[i] = 0;
	Bellman_Ford(start);
	Result();
}
