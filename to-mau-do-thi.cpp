#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V,E,M,vert;
vector <int> adj[101];
int color[101] = {0};
int ver_degmax, degmax;
bool visited[101];

void inp(){
    cin>>V>>E>>M;
    while(E--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

// tìm đỉnh có bậc lớn nhất
void find_ver_degmax(){
    degmax = 0;
    for(int i= 1; i<= V; ++i){
        if(adj[i].size() > degmax){
            degmax = adj[i].size();
            ver_degmax = i;
        }
    }
}

// xóa đỉnh v của đồ thị
void delete_ver(int v){
    for(int i=1; i<=V; ++i){
        if(i == v) adj[i].clear();
        else{
            for( int j = 0; j<adj[i].size(); ++j){
                if( adj[i][j] == v ) adj[i].erase(adj[i].begin() + j);
            }
        }
    }
}

void color_fill_ver(){
    color[ver_degmax] = 2;
    visited[ver_degmax] = 1;
    for(auto x : adj[ver_degmax]){
        color[x] = 1;
    }
    
    for(int u= 1; u<=V; ++u){
        if(color[u] == 0 && visited[u] == 0){
            color[u] = 2;
            visited[u] = 1;
            for(auto y : adj[u]){
                color[y] = 1;
            }
        }
    }
    vert = 0;
    for(int i=1; i<=V; ++i) {
    	if(visited[i]) vert++;
	}
}

void setup(){
    for(int i = 1; i<= V; ++i){
        adj[i].clear();
        color[i] = 0;
        visited[i] = false;
        vert = 0;
    }
}

int count_color_min(){
	int res = 1;
	find_ver_degmax();
	while(vert != V){
		color_fill_ver();
		if(vert == V) return res;
		else{
			for(int i = 1 ; i<= V ; ++i){
				if(visited[i]) delete_ver(i);
				else{
					color[i] = 0;
				}
			}
			find_ver_degmax();
			res++;
		}
	}
	for(int i=1; i<= V; ++i) cout<<visited[i]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        inp();
        if(count_color_min() <= M) cout<<"YES\n";
        else cout<<"NO\n";
        setup();
    }
    system("pause");
}

/*

1
12 17 3
1 2
2 3
3 4
4 5
5 6
1 4
2 5
5 7
5 8
6 8
4 9
4 10
9 10
1 12
2 11
11 12
1 6

*/
