#include<iostream>
#include<vector>

using namespace std;

int n, a[1001][1001], d[1001][1001], nex[1001][1001];
const int INF = INT_MAX;

void Input(){
    cin>>n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin>>a[i][j];
            if(a[i][j] == 0){
                a[i][j] = INF;
            }
            if(i==j) a[i][j] = 0;
        }
    }
}

void Floyd_Alg(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            	d[i][j] = a[i][j];      
            if(a[i][j] != INF){
                nex[i][j] = j;
            }
            else {
                nex[i][j] = INT_MIN;
            }
        }
    }

    for(int k =1 ; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(d[i][k] != INT_MAX && d[k][j] != INT_MAX){
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                        nex[i][j] = nex[i][k];
                    }
                }
            }
        }
    }    
}

void Reconstruct_Path(int u, int v){
    vector <int> path;
    if(nex[u][v] == INT_MIN){
        cout<<"no path\n";
    }
    else{
        cout<<"K/c "<<u<<"->"<<v<<"="<<d[u][v]<<"; ";
        path.push_back(u);
        while (u!=v){
            u = nex[u][v];
            path.push_back(u);
        }
    }
    for(int x = 0; x < path.size() - 1; ++x){
        cout<<path[x]<<"--> ";
    }
    cout <<v<<endl;
}

void print(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            Reconstruct_Path(i,j);
        }
    }
}

int main(int argc, char const *argv[])
{
    Input();
    Floyd_Alg();
    print();
    system("pause");
    return 0;
}
